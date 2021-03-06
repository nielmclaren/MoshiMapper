#include "ofApp.h"

/*
	rotateToNormal will rotate everything using ofRotate. the rotation amount
	and axis are generated using an ofQuaternion. the trick is to use ofQuaternion
	to determine the rotation that is required from a standard axis (0,0,1) to the
	desired normal vector, then apply that rotation.
 */
//--------------------------------------------------------------
void rotateToNormal(ofVec3f normal) {
    normal.normalize();

    float rotationAmount;
    ofVec3f rotationAngle;
    ofQuaternion rotation;

    ofVec3f axis(0, 0, 1);
    rotation.makeRotate(axis, normal);
    rotation.getRotate(rotationAmount, rotationAngle);
    ofRotate(rotationAmount, rotationAngle.x, rotationAngle.y, rotationAngle.z);
}

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetVerticalSync(true);

  selectedIndex = -1;
  selectedIndexChanged();

  setupLighting();
  setupLattice();
  setupIndexInput();
  setupStrands();
  setupLightController();
  setupIsKeyDown();

  RhombododdyReport report(&lattice);
  report.save("render.png");
}

void ofApp::setupLighting() {
  ofSetSmoothLighting(true);

  overheadLight.setDiffuseColor(ofFloatColor(.8));
  overheadLight.setSpecularColor(ofFloatColor(1));
  overheadLight.setPosition(0, 500, 0);

  underLight.setDiffuseColor(ofFloatColor(.6));
  underLight.setSpecularColor(ofFloatColor(.6));
  underLight.setPosition(0, -500, 0);

  angleLight.setDiffuseColor(ofFloatColor(.4));
  angleLight.setSpecularColor(ofFloatColor(.4));
  angleLight.setPosition(200, 500, 1500);
}

void ofApp::setupLattice() {
  lattice.setSize(50);

  lattice.setPosition(2, 0, 1, true);
  lattice.setPosition(1, 0, 2, true);
  lattice.setPosition(2, 0, 2, true);
  lattice.setPosition(1, 0, 3, true);

  lattice.setPosition(1, 1, 0, true);
  lattice.setPosition(0, 1, 1, true);
  lattice.setPosition(1, 1, 1, true);
  lattice.setPosition(2, 1, 1, true);
  lattice.setPosition(0, 1, 2, true);
  lattice.setPosition(1, 1, 2, true);
  lattice.setPosition(2, 1, 2, true);
  lattice.setPosition(1, 1, 3, true);

  lattice.setPosition(1, 2, 0, true);
  lattice.setPosition(2, 2, 0, true);
  lattice.setPosition(0, 2, 1, true);
  lattice.setPosition(1, 2, 1, true);
  lattice.setPosition(3, 2, 1, true);
  lattice.setPosition(0, 2, 2, true);
  lattice.setPosition(3, 2, 2, true);
  lattice.setPosition(2, 2, 3, true);
  lattice.setPosition(1, 2, 4, true);
  lattice.setPosition(2, 2, 4, true);

  lattice.setPosition(0, 3, 0, true);
  lattice.setPosition(2, 3, 0, true);
  lattice.setPosition(0, 3, 2, true);
  lattice.setPosition(3, 3, 2, true);
  lattice.setPosition(0, 3, 3, true);
  lattice.setPosition(1, 3, 3, true);

  latticeWidth = lattice.getWidth();
  latticeHeight = lattice.getHeight();
  latticeDepth = lattice.getDepth();

  // This is just to test that setting colours is actually working.
  ofColor orange = ofColor::fromHex(0xfde0c6);
  ofColor blue = ofColor::fromHex(0xb5d2fd);
  for (int i = 0; i < lattice.positionCount(); i++) {
    LatticePosition* pos = lattice.getPosition(i);
    if (i % 2 == 0) {
      pos->color = orange;
    }
    else {
      pos->color = blue;
    }
  }
}

void ofApp::setupIndexInput() {
  indexInput.set(10, 10, 300, 95);
  indexInput.setLattice(&lattice);
  indexInput.addListener(this, &ofApp::indexInputChanged);
}

void ofApp::setupStrands() {
  int phoneStrandCount = 6;
  for (int i = 0; i < phoneStrandCount; i++) {
    PhoneStrand* strand = new PhoneStrand();
    strand->setSegmentCount(40);
    phoneStrands.push_back(strand);
  }
}

void ofApp::setupLightController() {
  lightController.setLattice(&lattice);
  lightController.setStrands(&phoneStrands);
}

void ofApp::setupIsKeyDown() {
  isKeyDown = new bool[6];
  for (int i = 0; i < 6; i++) {
    isKeyDown[i] = 0;
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  float input[6];
  for (int i = 0; i < 6; i++) {
    input[i] = isKeyDown[i] ? ofRandom(0.5, 1) : 0;
  }

  lightController.input(input);
  lightController.step();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor cyan = ofColor::fromHex(0x00abec);
    ofColor magenta = ofColor::fromHex(0xec008c);
    ofColor yellow = ofColor::fromHex(0xffee00);
    ofColor bgColor = ofColor::fromHex(0x333333);

    ofBackgroundGradient(bgColor * 0.6, bgColor * 0.4);
    ofNoFill();

    ofEnableDepthTest();

    ofEnableLighting();
    overheadLight.enable();
    underLight.enable();
    angleLight.enable();

    easyCam.begin();
    ofRotateX(15);

    ofSetColor(0);
    ofDrawGrid(500, 10, false, false, true, false);

    ofPushMatrix();
    ofTranslate(-latticeWidth/2, 0, -latticeDepth/2);
    lattice.draw();
    ofPopMatrix();

    drawStrands();

    easyCam.end();

    ofDisableDepthTest();
    ofDisableLighting();

    drawIndexInput(10, 10);
    drawNeighborReadout(10, ofGetHeight() - 385);
}

void ofApp::drawStrands() {
  ofPushMatrix();
  ofTranslate(40, 0, 0);

  for (int i = 0; i < phoneStrands.size(); i++) {
    ofPushMatrix();
    ofRotateY(17 + 360.0 * i / phoneStrands.size());
    ofTranslate(60, 0, 0);

    phoneStrands[i]->draw();

    ofPopMatrix();
  }
  ofPopMatrix();
}

void ofApp::drawIndexInput(int x, int y) {
  ofFill();
  ofSetColor(255);
  ofDrawRectangle(x, y, 300, 95);
  ofSetColor(0);
  ofDrawRectangle(x + 2, y + 2, 296, 91);

  ofSetColor(255);
  indexInput.draw();
}

void ofApp::drawNeighborReadout(int x, int y) {
  ofFill();
  ofSetColor(255);
  ofDrawRectangle(x, y, 200, 375);
  ofSetColor(0);
  ofDrawRectangle(x + 2, y + 2, 196, 371);

  ofSetColor(255);
  neighborReadout.draw(x, y);
}

void ofApp::indexInputChanged(int &v) {
  selectedIndex = v;
  selectedIndexChanged();
}

void ofApp::selectedIndexChanged() {
  lattice.setSelectedIndex(selectedIndex);
  indexInput.setPosition(lattice.getSelectedPosition());
  neighborReadout.setPosition(lattice.getSelectedPosition());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  int index;
  switch (key) {
    case OF_KEY_UP:
      selectedIndex++;
      selectedIndexChanged();
      break;
    case OF_KEY_DOWN:
      selectedIndex--;
      selectedIndexChanged();
      break;
    case ' ':
      lattice.debug();
      break;

    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
      isKeyDown[key - '1'] = true;
      break;
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
  switch (key) {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
      isKeyDown[key - '1'] = false;
      break;
  }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  indexInput.mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
