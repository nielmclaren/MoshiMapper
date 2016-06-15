
#include "RhombododdyLattice.h"

RhombododdyLattice::RhombododdyLattice() {
    rhombododdy.setMode(OF_PRIMITIVE_TRIANGLES);
    rhombododdy.set(200, 2);

}
RhombododdyLattice::~RhombododdyLattice() {}

void RhombododdyLattice::draw() {
  for (LatticePosition* pos : positions) {
    drawRhombododdy(pos);
  }
}

void RhombododdyLattice::drawRhombododdy(LatticePosition* p) {
  rhombododdy.setPosition(
      p->x * 2/sqrt(2) * size + (p->y % 2 == 0 ? 0 : 1/sqrt(2) * size),
      p->y * size / 2,
      p->z * size + (p->y % 2 == 0 ? 0 : size/2));
  rhombododdy.draw();
}

float RhombododdyLattice::getSize() {
  return size;
}

void RhombododdyLattice::setSize(float s) {
  size = s;
  rhombododdy.set(size, 2);
}

void RhombododdyLattice::setPosition(int x, int y, int z, bool v) {
  int index = getIndexOfPosition(x, y, z);
  if (index < 0) {
    if (v) {
      positions.push_back(new LatticePosition(x, y, z));
    }
  }
  else if (!v) {
    positions.erase(positions.begin() + index);
  }
}

int RhombododdyLattice::getIndexOfPosition(int x, int y, int z) {
  for (int i = 0; i < positions.size(); i++) {
    LatticePosition* pos = positions[i];
    if (pos->x == x && pos->y == y && pos->z == z) {
      return i;
    }
  }
  return -1;
}

