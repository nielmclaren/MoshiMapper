
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

LatticePosition* RhombododdyLattice::getPosition(int x, int y, int z) {
  int index = getIndexOfPosition(x, y, z);
  if (index < 0) {
    return 0;
  }
  return positions[index];
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

  calculateNeighbors();
}

void RhombododdyLattice::debug() {
  for (int i = 0; i < positions.size(); i++) {
    LatticePosition* pos = positions[i];
    cout << "pos(" << pos->x << ", " << pos->y << ", " << pos->z << ")" << endl;

    for (int i = 0; i < 12; i++) {
      if (getNeighbor(pos, i)) {
        cout << "\t" << RhombododdyFace::getDisplayName(i) << endl;
      }
    }
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

void RhombododdyLattice::calculateNeighbors() {
  for (int i = 0; i < positions.size(); i++) {
    LatticePosition* pos = positions[i];
    calculateNeighbors(pos);
  }
}

void RhombododdyLattice::calculateNeighbors(LatticePosition* pos) {
  for (int i = 0; i < 12; i++) {
    pos->setNeighbor(i, getNeighbor(pos, i));
  }
}

LatticePosition* RhombododdyLattice::getNeighbor(LatticePosition* pos, int face) {
  int x = pos->x;
  int y = pos->y;
  int z = pos->z;

  switch (face) {
    case RhombododdyFace::TOP:
      y += 2;
      break;

    case RhombododdyFace::BOTTOM:
      y -= 2;
      break;

    case RhombododdyFace::FRONT:
      z += 1;
      break;

    case RhombododdyFace::BACK:
      z -= 1;
      break;

    case RhombododdyFace::LEFT_TOP_FRONT:
      if (y % 2 == 0) {
        x -= 1;
      }
      else {
        z += 1;
      }
      y += 1;
      break;

    case RhombododdyFace::LEFT_BOTTOM_FRONT:
      if (y % 2 == 0) {
        x -= 1;
      }
      else {
        z += 1;
      }
      y -= 1;
      break;

    case RhombododdyFace::RIGHT_TOP_FRONT:
      if (y % 2 == 0) {
      }
      else {
        x += 1;
        z += 1;
      }
      y += 1;
      break;

    case RhombododdyFace::RIGHT_BOTTOM_FRONT:
      if (y % 2 == 0) {
      }
      else {
        x += 1;
        z += 1;
      }
      y -= 1;
      break;

    case RhombododdyFace::LEFT_TOP_BACK:
      if (y % 2 == 0) {
        x -= 1;
        z -= 1;
      }
      else {
      }
      y += 1;
      break;

    case RhombododdyFace::LEFT_BOTTOM_BACK:
      if (y % 2 == 0) {
        x -= 1;
        z -= 1;
      }
      else {
      }
      y -= 1;
      break;

    case RhombododdyFace::RIGHT_TOP_BACK:
      if (y % 2 == 0) {
        z -= 1;
      }
      else {
        x += 1;
      }
      y += 1;
      break;

    case RhombododdyFace::RIGHT_BOTTOM_BACK:
      if (y % 2 == 0) {
        z -= 1;
      }
      else {
        x += 1;
      }
      y -= 1;
      break;
  }

  return getPosition(x, y, z);
}

