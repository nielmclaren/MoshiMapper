#pragma once

#include "NeighborReadout.h"
#include "RhombododdyLattice.h"

class RhombododdyReport {
public:
  RhombododdyReport(RhombododdyLattice* latticeArg);
  ~RhombododdyReport();

  void save(string filepath);

private:
  void drawLattice();
  void drawPosition(LatticePosition* pos);

  int getReportWidth();
  int getReportHeight();

  int widthPer;
  int heightPer;

  RhombododdyLattice* lattice;
  NeighborReadout readout;
};

