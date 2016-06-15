
#include "LatticePosition.h"

LatticePosition::LatticePosition() {
  x = 0;
  y = 0;
  z = 0;
}

LatticePosition::LatticePosition(int xArg, int yArg, int zArg) {
  x = xArg;
  y = yArg;
  z = zArg;
}

LatticePosition::~LatticePosition() {}

void LatticePosition::initNeighbors() {
  for (int i = 0; i < 12; i++) {
    neighbors[i] = 0;
  }
}

LatticePosition* LatticePosition::getNeighbor(int face) {
  if (face < 0 || face >= 12) {
    return 0;
  }
  return neighbors[face];
}

void LatticePosition::setNeighbor(int face, LatticePosition* pos) {
  neighbors[face] = pos;
}

int LatticePosition::neighborCount() {
  int count = 0;
  for (int i = 0; i < 12; i++) {
    if (neighbors[i]) {
      count++;
    }
  }
  return count;
}

