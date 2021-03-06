
#include "NeighborReadout.h"

NeighborReadout::NeighborReadout() {
  titleFont.loadFont("roadgeek.ttf", 20);
  labelFont.loadFont("roadgeek.ttf", 15);
  neighborFont.loadFont("arial.ttf", 10);
}

NeighborReadout::~NeighborReadout() {}

void NeighborReadout::draw(int x, int y) {
  float h = 80;
  if (pos) {
    drawExpandedRhombododdyReadout(x, y, h);
    drawExpandedNeighbors(x, y, h);
  }
}

void NeighborReadout::drawRhombus(int cx, int cy, float h) {
  float w = h / sqrt(2);

  ofSetLineWidth(4);
  ofDrawLine(cx, cy - h/2, cx + w/2, cy);
  ofDrawLine(cx + w/2, cy, cx, cy + h/2);
  ofDrawLine(cx, cy + h/2, cx - w/2, cy);
  ofDrawLine(cx - w/2, cy, cx, cy - h/2);
}

void NeighborReadout::drawRhombododdy(int cx, int cy, float h) {
  float w = h / sqrt(2);

  ofNoFill();

  // TOP
  ofSetLineWidth(4);
  drawRhombus(cx, cy, h);

  ofSetLineWidth(2);

  // LEFT
  ofDrawLine(cx, cy - h/2, cx - w/2, cy - h/2);
  ofDrawLine(cx - w/2, cy - h/2, cx - w, cy);
  ofDrawLine(cx - w, cy, cx - w/2, cy);
  ofDrawLine(cx - w, cy, cx - w/2, cy + h/2);
  ofDrawLine(cx - w/2, cy + h/2, cx, cy + h/2);

  // RIGHT
  ofDrawLine(cx, cy - h/2, cx + w/2, cy - h/2);
  ofDrawLine(cx + w/2, cy - h/2, cx + w, cy);
  ofDrawLine(cx + w, cy, cx + w/2, cy);
  ofDrawLine(cx + w, cy, cx + w/2, cy + h/2);
  ofDrawLine(cx + w/2, cy + h/2, cx, cy + h/2);
}

void NeighborReadout::drawRhombododdyReadout(int x, int y, float h) {
  titleFont.drawString("n" + ofToString(pos->index), x + 93, y + 27);

  drawRhombododdy(x + 100, y + 140, h);
  labelFont.drawString("top", x + 90, y + 120);

  labelFont.drawString("back", x + 85, y + 55);

  labelFont.drawString("front", x + 85, y + 240);

  labelFont.drawString("left", x + 17, y + 200);
  labelFont.drawString("right", x + 160, y + 200);
}

void NeighborReadout::drawNeighbors(int x, int y, float h) {
  int upperRadius = 7;
  int lowerRadius = 13;

  float w = h / sqrt(2);

  int cx = x + 100;
  int cy = y + 140;

  int offset = 11;

  if (pos->getNeighbor(RhombododdyFace::TOP)) {
    ofFill();
    ofDrawCircle(cx, cy, upperRadius);
  }

  if (pos->getNeighbor(RhombododdyFace::BOTTOM)) {
    ofNoFill();
    ofDrawCircle(cx, cy, lowerRadius);
  }

  if (pos->getNeighbor(RhombododdyFace::FRONT)) {
    ofFill();
    ofDrawCircle(cx, cy + h/2 + offset, upperRadius);
  }

  if (pos->getNeighbor(RhombododdyFace::BACK)) {
    ofFill();
    ofDrawCircle(cx, cy - h/2 - offset, upperRadius);
  }

  if (pos->getNeighbor(RhombododdyFace::LEFT_TOP_FRONT)) {
    ofFill();
    ofDrawCircle(cx - w/2, cy + h/4, upperRadius);
  }

  if (pos->getNeighbor(RhombododdyFace::LEFT_BOTTOM_FRONT)) {
    ofNoFill();
    ofDrawCircle(cx - w/2, cy + h/4, lowerRadius);
  }

  if (pos->getNeighbor(RhombododdyFace::RIGHT_TOP_FRONT)) {
    ofFill();
    ofDrawCircle(cx + w/2, cy + h/4, upperRadius);
  }

  if (pos->getNeighbor(RhombododdyFace::RIGHT_BOTTOM_FRONT)) {
    ofNoFill();
    ofDrawCircle(cx + w/2, cy + h/4, lowerRadius);
  }

  if (pos->getNeighbor(RhombododdyFace::LEFT_TOP_BACK)) {
    ofFill();
    ofDrawCircle(cx - w/2, cy - h/4, upperRadius);
  }

  if (pos->getNeighbor(RhombododdyFace::LEFT_BOTTOM_BACK)) {
    ofNoFill();
    ofDrawCircle(cx - w/2, cy - h/4, lowerRadius);
  }

  if (pos->getNeighbor(RhombododdyFace::RIGHT_TOP_BACK)) {
    ofFill();
    ofDrawCircle(cx + w/2, cy - h/4, upperRadius);
  }

  if (pos->getNeighbor(RhombododdyFace::RIGHT_BOTTOM_BACK)) {
    ofNoFill();
    ofDrawCircle(cx + w/2, cy - h/4, lowerRadius);
  }
}

void NeighborReadout::drawExpandedRhombododdyReadout(int x, int y, float h) {
  titleFont.drawString("n" + ofToString(pos->index), x + 58, y + 27);

  drawRhombododdy(x + 70, y + 75, h);
  labelFont.drawString("top", x + 140, y + 80);

  drawRhombus(x + 70, y + 150, h);
  labelFont.drawString("front", x + 140, y + 155);

  drawRhombododdy(x + 70, y + 225, h);
  labelFont.drawString("bottom", x + 140, y + 230);

  drawRhombus(x + 70, y + 300, h);
  labelFont.drawString("back", x + 140, y + 305);

  labelFont.drawString("left", x + 27, y + 347);
  labelFont.drawString("right", x + 90, y + 347);
}

void NeighborReadout::drawExpandedNeighbors(int x, int y, float h) {
  LatticePosition* neighbor;

  int radius = 7;

  float w = h / sqrt(2);

  int cx;
  int cy;

  ofFill();

  if ((neighbor = pos->getNeighbor(RhombododdyFace::FRONT))) {
    drawNeighborString(neighbor, x + 70 - 8, y + 150 - 4);
    ofDrawCircle(x + 70, y + 150 + 8, radius);
  }

  if ((neighbor = pos->getNeighbor(RhombododdyFace::BACK))) {
    drawNeighborString(neighbor, x + 70 - 8, y + 300 - 4);
    ofDrawCircle(x + 70, y + 300 + 8, radius);
  }

  // TOP

  cx = x + 70;
  cy = y + 75;
  if ((neighbor = pos->getNeighbor(RhombododdyFace::TOP))) {
    drawNeighborString(neighbor, cx - 8, cy - 4);
    ofDrawCircle(cx, cy + 8, radius);
  }

  if ((neighbor = pos->getNeighbor(RhombododdyFace::LEFT_TOP_FRONT))) {
    drawNeighborString(neighbor, cx - w/2 - 32, cy + h/4 + 18);
    ofDrawCircle(cx - w/2, cy + h/4, radius);
  }

  if ((neighbor = pos->getNeighbor(RhombododdyFace::RIGHT_TOP_FRONT))) {
    drawNeighborString(neighbor, cx + w/2 + 18, cy + h/4 + 18);
    ofDrawCircle(cx + w/2, cy + h/4, radius);
  }

  if ((neighbor = pos->getNeighbor(RhombododdyFace::LEFT_TOP_BACK))) {
    drawNeighborString(neighbor, cx - w/2 - 32, cy - h/4 - 10);
    ofDrawCircle(cx - w/2, cy - h/4, radius);
  }

  if ((neighbor = pos->getNeighbor(RhombododdyFace::RIGHT_TOP_BACK))) {
    drawNeighborString(neighbor, cx + w/2 + 18, cy - h/4 - 10);
    ofDrawCircle(cx + w/2, cy - h/4, radius);
  }

  /// BOTTOM

  cx = x + 70;
  cy = y + 225;
  if ((neighbor = pos->getNeighbor(RhombododdyFace::BOTTOM))) {
    drawNeighborString(neighbor, cx - 8, cy - 4);
    ofDrawCircle(cx, cy + 8, radius);
  }

  if ((neighbor = pos->getNeighbor(RhombododdyFace::LEFT_BOTTOM_FRONT))) {
    drawNeighborString(neighbor, cx - w/2 - 32, cy - h/4 - 10);
    ofDrawCircle(cx - w/2, cy - h/4, radius);
  }

  if ((neighbor = pos->getNeighbor(RhombododdyFace::RIGHT_BOTTOM_FRONT))) {
    drawNeighborString(neighbor, cx + w/2 + 18, cy - h/4 - 10);
    ofDrawCircle(cx + w/2, cy - h/4, radius);
  }

  if ((neighbor = pos->getNeighbor(RhombododdyFace::LEFT_BOTTOM_BACK))) {
    drawNeighborString(neighbor, cx - w/2 - 32, cy + h/4 + 18);
    ofDrawCircle(cx - w/2, cy + h/4, radius);
  }

  if ((neighbor = pos->getNeighbor(RhombododdyFace::RIGHT_BOTTOM_BACK))) {
    drawNeighborString(neighbor, cx + w/2 + 18, cy + h/4 + 18);
    ofDrawCircle(cx + w/2, cy + h/4, radius);
  }
}

void NeighborReadout::drawNeighborString(LatticePosition* pos, int x, int y) {
  neighborFont.drawString("n" + ofToString(pos->index), x, y);
}

void NeighborReadout::setPosition(LatticePosition* p) {
  pos = p;
}

