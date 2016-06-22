
#include "LightController.h"

LightController::LightController() {
  lattice = 0;
  strands = 0;

  hasLattice = false;
  hasStrands = false;

  numChannels = 6;
  strandDelayMs = 1500;
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

void LightController::stepStrand(int strandIndex, PhoneStrand* strand) {
  float t = modTime(10000);

  ofColor pink = ofColor::fromHex(0xf3399e);
  ofColor blue = ofColor::fromHex(0x274f8c);
  ofColor highlight = ofColor::fromHex(0xd5a1b7);

  int segmentCount = strand->getSegmentCount();
  for (int i = 0; i < segmentCount; i++) {
    ofColor baseColor = blue.getLerped(pink, splitTime(clampTime(t - i * 0.01)));
    float v = getStrandSegmentValue(strandIndex, segmentCount - i - 1, segmentCount);
    strand->setColor(i, baseColor.getLerped(highlight, v));
  }
}

float LightController::getStrandSegmentValue(int strandIndex, int segmentIndex, int segmentCount) {
  int targetDelayMs = floor((float)segmentIndex / segmentCount * strandDelayMs);
  int historyIndex = getInputHistoryIndexByDelay(targetDelayMs);
  return historyIndex >= 0 ? getInputHistoryValue(strandIndex, historyIndex) : 0;
}

int LightController::getInputHistoryIndexByDelay(int delayMs) {
  unsigned long now = ofGetElapsedTimeMillis();
  for (int i = 0; i < inputHistoryTimings.size(); i++) {
    if (inputHistoryTimings[i] > now - delayMs) {
      return i;
    }
  }
  return -1;
}

float LightController::getInputHistoryValue(int strandIndex, int historyIndex) {
  return inputHistory[strandIndex][historyIndex];
}

void LightController::input(float* input) {
  unsigned long now = ofGetElapsedTimeMillis();
  inputHistoryTimings.push_back(now);
  for (int i = 0; i < numChannels; i++) {
    inputHistory[i].push_back(input[i]);
  }

  while (inputHistoryTimings.size() > 0
      && inputHistoryTimings.front() < now - strandDelayMs) {
    inputHistoryTimings.pop_front();
    for (int i = 0; i < numChannels; i++) {
      inputHistory[i].pop_front();
    }
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

