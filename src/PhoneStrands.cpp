
#include "PhoneStrand.h"

PhoneStrand::PhoneStrand() {
  segments = new ofColor[0];
}

PhoneStrand::~PhoneStrand() {}

void PhoneStrand::draw() {
  float segmentLength = 3;
  int segmentCount = 50;

  float slopage = 1.4;

  ofSetLineWidth(16);

  for (int i = 0; i < segmentCount; i++) {
    int j = i + 1;
    ofSetColor(segments[i]);
    ofDrawLine(
        0, -i * segmentLength, 0,
        0, -j * segmentLength, 0);
  }
}

int PhoneStrand::getSegmentCount() {
  return segmentCount;
}

void PhoneStrand::setSegmentCount(int count) {
  segmentCount = count;

  delete[] segments;
  segments = new ofColor[segmentCount];
  for (int i = 0; i < segmentCount; i++) {
    segments[i].set(0);
  }
}

void PhoneStrand::setColor(int index, ofColor color) {
  segments[index].set(color);
}
