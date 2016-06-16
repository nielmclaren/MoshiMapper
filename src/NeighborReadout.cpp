
#include "NeighborReadout.h"

NeighborReadout::NeighborReadout() {
  labelFont.loadFont("arial.ttf", 12);
}

NeighborReadout::~NeighborReadout() {}

void NeighborReadout::draw(int x, int y) {
  drawExpandedRhombododdy(x, y);
  drawExpandedNeighbors(x, y);
}

void NeighborReadout::drawRhombus(int cx, int cy, int h) {
  float w = h / sqrt(2);

  ofSetLineWidth(4);
  ofDrawLine(cx, cy - h/2, cx + w/2, cy);
  ofDrawLine(cx + w/2, cy, cx, cy + h/2);
  ofDrawLine(cx, cy + h/2, cx - w/2, cy);
  ofDrawLine(cx - w/2, cy, cx, cy - h/2);
}

void NeighborReadout::drawRhombododdy(int cx, int cy, int h) {
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

void NeighborReadout::drawNeighbors(int x, int y) {
  int upperRadius = 7;
  int lowerRadius = 13;

  float h = 120;
  float w = h / sqrt(2);

  int cx = x + 100;
  int cy = y + 100;

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

void NeighborReadout::drawExpandedRhombododdy(int x, int y) {
  labelFont.drawString("n" + ofToString(index), x + 61, y + 27);

  drawRhombododdy(x + 70, y + 75, 80);
  labelFont.drawString("top", x + 120, y + 50);

  drawRhombus(x + 70, y + 150, 80);
  labelFont.drawString("front", x + 120, y + 135);

  drawRhombododdy(x + 70, y + 225, 80);
  labelFont.drawString("bottom", x + 120, y + 200);

  drawRhombus(x + 70, y + 300, 80);
  labelFont.drawString("back", x + 120, y + 285);

  labelFont.drawString("left", x + 27, y + 347);
  labelFont.drawString("right", x + 90, y + 347);
}

void NeighborReadout::drawExpandedNeighbors(int x, int y) {
  int radius = 7;

  float h = 80;
  float w = h / sqrt(2);

  int cx;
  int cy;

  ofFill();

  if (pos->getNeighbor(RhombododdyFace::FRONT)) {
    ofDrawCircle(x + 70, y + 150, radius);
  }

  if (pos->getNeighbor(RhombododdyFace::BACK)) {
    ofDrawCircle(x + 70, y + 300, radius);
  }

  // TOP

  cx = x + 70;
  cy = y + 75;
  if (pos->getNeighbor(RhombododdyFace::TOP)) {
    ofDrawCircle(cx, cy, radius);
  }

  if (pos->getNeighbor(RhombododdyFace::LEFT_TOP_FRONT)) {
    ofDrawCircle(cx - w/2, cy + h/4, radius);
  }

  if (pos->getNeighbor(RhombododdyFace::RIGHT_TOP_FRONT)) {
    ofDrawCircle(cx + w/2, cy + h/4, radius);
  }

  if (pos->getNeighbor(RhombododdyFace::LEFT_TOP_BACK)) {
    ofDrawCircle(cx - w/2, cy - h/4, radius);
  }

  if (pos->getNeighbor(RhombododdyFace::RIGHT_TOP_BACK)) {
    ofDrawCircle(cx + w/2, cy - h/4, radius);
  }

  /// BOTTOM

  cx = x + 70;
  cy = y + 225;
  if (pos->getNeighbor(RhombododdyFace::BOTTOM)) {
    ofDrawCircle(cx, cy, radius);
  }

  if (pos->getNeighbor(RhombododdyFace::LEFT_BOTTOM_FRONT)) {
    ofDrawCircle(cx - w/2, cy - h/4, radius);
  }

  if (pos->getNeighbor(RhombododdyFace::RIGHT_BOTTOM_FRONT)) {
    ofDrawCircle(cx + w/2, cy - h/4, radius);
  }

  if (pos->getNeighbor(RhombododdyFace::LEFT_BOTTOM_BACK)) {
    ofDrawCircle(cx - w/2, cy + h/4, radius);
  }

  if (pos->getNeighbor(RhombododdyFace::RIGHT_BOTTOM_BACK)) {
    ofDrawCircle(cx + w/2, cy + h/4, radius);
  }
}

void NeighborReadout::set(int indexArg, LatticePosition* p) {
  index = indexArg;
  pos = p;
}

