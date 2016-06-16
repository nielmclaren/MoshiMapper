#pragma once

#include "ofMain.h"
#include "LatticePosition.h"
#include "RhombododdyLattice.h"

class IndexInput {
public:
    IndexInput();
    ~IndexInput();

    void draw(int x, int y, int w, int h);
    void setPosition(LatticePosition* pos);
    void setLattice(RhombododdyLattice* lattice);

private:
    bool isSelected(LatticePosition* pos);
    bool isSelectedNeighbor(LatticePosition* pos);

    ofTrueTypeFont titleFont;
    ofTrueTypeFont labelFont;
    ofTrueTypeFont neighborFont;

    RhombododdyLattice* lattice;
    LatticePosition* pos;
};

