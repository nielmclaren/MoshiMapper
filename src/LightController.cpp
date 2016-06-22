
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
    for (int i = 0; i < lattice->positionCount(); i++) {
      lattice->setColor(i, ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
    }

    for (int i = 0; i < strands->size(); i++) {
      stepStrand(i, strands->at(i));
    }
  }
}

void LightController::stepStrand(int index, PhoneStrand* strand) {
  int segmentCount = strand->getSegmentCount();
  for (int i = 0; i < segmentCount; i++) {
    strand->setColor(i, ofColor(255, ofRandom(255), ofRandom(255)));
  }
}

void LightController::setLattice(RhombododdyLattice* latticeArg) {
  lattice = latticeArg;
  hasLattice = true;
}

void LightController::setStrands(std::vector<PhoneStrand*>* strandsArg) {
  strands = strandsArg;
  hasStrands = true;
}

