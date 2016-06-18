
#include "IndexInput.h"

IndexInput::IndexInput() {
  titleFont.loadFont("roadgeek.ttf", 20);
  labelFont.loadFont("roadgeek.ttf", 15);
  neighborFont.loadFont("arial.ttf", 10);
}

IndexInput::~IndexInput() {}

void IndexInput::set(int x, int y, int w, int h) {
  boundsX = x;
  boundsY = y;
  boundsW = w;
  boundsH = h;
}

void IndexInput::draw() {
  if (lattice) {
    int x = boundsX + 4;
    int y = boundsY + 4;
    int width = boundsW - 8;
    int height = boundsH - 8;
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

void IndexInput::mouseReleased(int mouseX, int mouseY, int button) {
  if (boundsX < mouseX && mouseX < boundsX + boundsW
      && boundsY < mouseY && mouseY < boundsY + boundsH) {
    int x = boundsX + 4;
    int y = boundsY + 4;
    int width = boundsW - 8;
    int height = boundsH - 8;
    int w = width / 10;
    int h = w;

    int count = lattice->positionCount();
    for (int i = 0; i < count; i++) {
      int px = x + (i % 10) * w;
      int py = y + floor(i / 10) * h;

      if (px < mouseX && mouseX < px + w
          && py < mouseY && mouseY < py + h) {
        indexValue = i;
      }
    }
  }
}

