
#include "LatticePosition.h"

LatticePosition::LatticePosition() {
  index = -1;
  x = 0;
  y = 0;
  z = 0;
  color.set(0);
}

LatticePosition::LatticePosition(int indexArg, int xArg, int yArg, int zArg) {
  index = indexArg;
  x = xArg;
  y = yArg;
  z = zArg;
  color.set(0);
}

LatticePosition::~LatticePosition() {}

LatticePosition* LatticePosition::getNeighbor(int face) {
  if (face < 0 || face >= 12) {
    return 0;
  }
  return neighbors[face];
}

bool LatticePosition::hasNeighbor(LatticePosition* pos) {
  for (int i = 0; i < 12; i++) {
    if (neighbors[i] == pos) {
      return true;
    }
  }
  return false;
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

