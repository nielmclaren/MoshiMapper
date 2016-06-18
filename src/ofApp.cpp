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

  RhombododdyReport report(&lattice);
  report.save("render.png");
}

void ofApp::setupLighting() {
  ofSetSmoothLighting(true);
  pointLight.setDiffuseColor(ofFloatColor(.85, .85, .55));
  pointLight.setSpecularColor(ofFloatColor(1.f, 1.f, 1.f));

  pointLight2.setDiffuseColor(ofFloatColor( 238.f/255.f, 57.f/255.f, 135.f/255.f));
  pointLight2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));

  pointLight3.setDiffuseColor(ofFloatColor(19.f/255.f,94.f/255.f,77.f/255.f));
  pointLight3.setSpecularColor(ofFloatColor(18.f/255.f,150.f/255.f,135.f/255.f));
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
}

void ofApp::setupIndexInput() {
  indexInput.set(10, 10, 300, 95);
  indexInput.setLattice(&lattice);
  indexInput.addListener(this, &ofApp::indexInputChanged);
}

//--------------------------------------------------------------
void ofApp::update(){
    int w = ofGetWidth();
    int h = ofGetHeight();
    float t = ofGetElapsedTimef();

    pointLight.setPosition((w*.5)+ cos(t*.5)*(w*.3), h/2, 500);
    pointLight2.setPosition((w*.5)+ cos(t*.15)*(w*.3), h*.5 + sin(t*.7)*(h), -300);
    pointLight3.setPosition(cos(t*1.5) * w*.5, sin(t*1.5f) * w*.5, cos(t*.2) * w);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor cyan = ofColor::fromHex(0x00abec);
    ofColor magenta = ofColor::fromHex(0xec008c);
    ofColor yellow = ofColor::fromHex(0xffee00);

    ofBackgroundGradient(magenta * .6, magenta * .4);
    ofNoFill();

    ofEnableDepthTest();

    ofEnableLighting();
    pointLight.enable();
    pointLight2.enable();
    pointLight3.enable();

    easyCam.begin();
    ofRotateX(15);

    ofSetColor(0);
    ofDrawGrid(500, 10, false, false, true, false);

    lattice.draw();

    easyCam.end();

    ofDisableDepthTest();
    ofDisableLighting();

    drawIndexInput(10, 10);
    drawNeighborReadout(10, ofGetHeight() - 385);
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
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
