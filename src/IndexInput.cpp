
#include "IndexInput.h"

IndexInput::IndexInput() {
  titleFont.loadFont("roadgeek.ttf", 20);
  labelFont.loadFont("roadgeek.ttf", 15);
  neighborFont.loadFont("arial.ttf", 10);
}

IndexInput::~IndexInput() {}

void IndexInput::draw(int x, int y, int width, int height) {
  if (lattice) {
    x += 4;
    y += 4;
    width -= 8;
    height -= 8;
    int w = width / 10;
    int h = w;

    int count = lattice->positionCount();
    for (int i = 0; i < count; i++) {
      int px = (i % 10) * w;
      int py = floor(i / 10) * h;

      LatticePosition* pos = lattice->getPosition(i);
      ofSetColor(255);
      if (isSelected(pos)) {
        ofSetLineWidth(2);
        ofFill();
        ofDrawRectangle(x + px + 6, y + py + 6, w - 12, h - 12);
        ofNoFill();
        ofDrawRectangle(x + px + 2, y + py + 2, w - 4, h - 4);
        ofSetColor(0);
      }
      else if (isSelectedNeighbor(pos)) {
        ofSetLineWidth(2);
        ofNoFill();
        ofDrawRectangle(x + px + 2, y + py + 2, w - 4, h - 4);
      }

      neighborFont.drawString(ofToString(pos->index), x + px + 7, y + py + 20);
    }
  }
}

bool IndexInput::isSelected(LatticePosition* pos) {
  return lattice->getSelectedPosition() == pos;
}

bool IndexInput::isSelectedNeighbor(LatticePosition* pos) {
  LatticePosition* selectedPos = lattice->getSelectedPosition();
  return pos->hasNeighbor(selectedPos);
}

void IndexInput::setLattice(RhombododdyLattice* latticeArg) {
  lattice = latticeArg;
}

void IndexInput::setPosition(LatticePosition* posArg) {
  pos = posArg;
}

