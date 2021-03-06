#pragma once

#include "ofMain.h"

class LatticePosition {
public:
    LatticePosition();
    LatticePosition(int index, int x, int y, int z);
    ~LatticePosition();

    LatticePosition* getNeighbor(int face);
    bool hasNeighbor(LatticePosition* pos);
    void setNeighbor(int face, LatticePosition* pos);
    int neighborCount();

    int index;
    int x;
    int y;
    int z;
    ofColor color;

private:
    LatticePosition* neighbors[12];
};

