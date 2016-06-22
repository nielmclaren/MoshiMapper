
#include "LightController.h"

LightController::LightController() {
  lattice = 0;
  strands = 0;

  hasLattice = false;
  hasStrands = false;
}

LightController::~LightController() {}

void LightController::step() {
  if (hasLattice && hasStrands) {
    stepLattice();

    for (int i = 0; i < strands->size(); i++) {
      stepStrand(i, strands->at(i));
    }
  }
}

void LightController::stepLattice() {
  float t = modTime(6000);

  ofColor pink = ofColor::fromHex(0xf3399e);
  ofColor blue = ofColor::fromHex(0x274f8c);

  for (int i = 0; i < lattice->positionCount(); i++) {
    LatticePosition* pos = lattice->getPosition(i);
    lattice->setColor(i, blue.getLerped(pink, splitTime(clampTime(t + pos->y * 0.1))));
  }
}

void LightController::stepStrand(int index, PhoneStrand* strand) {
  float t = modTime(10000);

  ofColor pink = ofColor::fromHex(0xf3399e);
  ofColor blue = ofColor::fromHex(0x274f8c);

  int segmentCount = strand->getSegmentCount();
  for (int i = 0; i < segmentCount; i++) {
    strand->setColor(i, blue.getLerped(pink, splitTime(clampTime(t - i * 0.01))));
  }
}

float LightController::modTime(int duration) {
  unsigned long now = ofGetElapsedTimeMillis();
  return (float)(now % duration) / duration;
}

float LightController::splitTime(float t) {
  if (t < 0.5) {
    return 2.0 * t;
  }
  else {
    return (1.0 - t) * 2.0;
  }
}

float LightController::clampTime(float t) {
  while (t >= 1) {
    t -= 1;
  }
  while (t < 0) {
    t += 1;
  }
  return t;
}

void LightController::setLattice(RhombododdyLattice* latticeArg) {
  lattice = latticeArg;
  hasLattice = true;
}

void LightController::setStrands(std::vector<PhoneStrand*>* strandsArg) {
  strands = strandsArg;
  hasStrands = true;
}

