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
  int getReportWidth();
  int getReportHeight();

  RhombododdyLattice* lattice;
};

