
#include "NeighborReadout.h"

NeighborReadout::NeighborReadout() {}
NeighborReadout::~NeighborReadout() {}

void NeighborReadout::draw(int x, int y) {
  ofFill();
  ofSetColor(255);
  ofDrawRectangle(x, y, 200, 200);
  ofSetColor(0);
  ofDrawRectangle(x + 2, y + 2, 196, 196);

  drawRhombododdy(x, y);
  drawNeighbors(x, y);
}

void NeighborReadout::drawRhombododdy(int x, int y) {
  float h = 120;
  float w = h / sqrt(2);

  int cx = x + 100;
  int cy = y + 100;

  ofNoFill();
  ofSetColor(255);

  // TOP
  ofSetLineWidth(4);
  ofDrawLine(cx, cy - h/2, cx + w/2, cy);
  ofDrawLine(cx + w/2, cy, cx, cy + h/2);
  ofDrawLine(cx, cy + h/2, cx - w/2, cy);
  ofDrawLine(cx - w/2, cy, cx, cy - h/2);

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

void NeighborReadout::set(LatticePosition* p) {
  pos = p;
}

