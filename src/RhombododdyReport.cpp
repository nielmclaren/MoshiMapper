#include "RhombododdyReport.h"

RhombododdyReport::RhombododdyReport(RhombododdyLattice* latticeArg) {
  lattice = latticeArg;

  widthPer = 200;
  heightPer = 250;
}

RhombododdyReport::~RhombododdyReport() {}

void RhombododdyReport::save(string filepath) {
  ofFbo fbo;
  fbo.allocate(getReportWidth(), getReportHeight(), GL_RGB);

  fbo.begin();
  ofClear(255);
  drawLattice();
  fbo.end();

  ofPixels pixels;
  fbo.readToPixels(pixels);

  ofImage img;
  img.setFromPixels(pixels);
  img.save(filepath);
}

int RhombododdyReport::getReportWidth() {
  if (lattice->positionCount() < 6) {
    return lattice->positionCount() * widthPer;
  }
  return 6 * widthPer;
}

int RhombododdyReport::getReportHeight() {
  return ceil((float)lattice->positionCount() / 6) * heightPer;
}

void RhombododdyReport::drawLattice() {
  for (int i = 0; i < lattice->positionCount(); i++) {
    drawPosition(lattice->getPosition(i));
  }
}

void RhombododdyReport::drawPosition(LatticePosition* pos) {
  ofSetColor(0);
  readout.setPosition(pos);
  readout.draw(pos->index % 6 * widthPer, pos->index / 6 * heightPer);
}


