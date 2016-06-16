#pragma once

#include "ofMain.h"
#include "LatticePosition.h"
#include "RhombododdyLattice.h"

class IndexInput {
public:
    IndexInput();
    ~IndexInput();

    void set(int x, int y, int w, int h);
    void draw();

    void setPosition(LatticePosition* pos);
    void setLattice(RhombododdyLattice* lattice);

    void mouseReleased(int x, int y, int button);

private:
    bool isSelected(LatticePosition* pos);
    bool isSelectedNeighbor(LatticePosition* pos);

    ofTrueTypeFont titleFont;
    ofTrueTypeFont labelFont;
    ofTrueTypeFont neighborFont;

    int boundsX;
    int boundsY;
    int boundsW;
    int boundsH;

    RhombododdyLattice* lattice;
    LatticePosition* pos;
};

