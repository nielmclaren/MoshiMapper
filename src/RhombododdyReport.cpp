#include "RhombododdyReport.h"

RhombododdyReport::RhombododdyReport(RhombododdyLattice* latticeArg) {
  lattice = latticeArg;
}

~RhombododdyReport::RhombododdyReport() {}

void RhombododdyReport::save(string filepath) {
  ofFbo fbo;
  fbo.allocate(getReportWidth(), getReportHeight(), GL_RGB);

  fbo.begin();
  ofClear(0,0,0,0);
  drawLattice();
  fbo.end();

  ofPixels pixels;
  fbo.readToPixels(pixels);

  ofImage img;
  img.setFromPixels(pixels);
  img.save(filepath);
}

int RhombododdyReport::getReportWidth() {
  int widthPer = 200;
  if (lattice.rhombododdyCount() < 6) {
    return lattice.rhombododdyCount() * widthPer;
  }
  return 6 * widthPer;
}

int RhombododdyReport::getReportHeight() {
  int heightPer = 375;
  return (lattice.rhombododdyCount() / 6) * heightPer;
}

void RhombododdyReport::drawLattice() {
  std::vector<LatticePositions*> positions = lattice.getPositions();

  for (int i = 0; i < positions.size(); i++) {
    drawPosition(i, positions[i]);
  }

  delete positions;
}

void RhombododdyReport::drawRhombododdy(int index, LatticePosition* pos) {
}


