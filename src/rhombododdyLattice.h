#pragma once

#include "ofMain.h"
#include "ofGraphics.h"
#include "LatticePosition.h"
#include "RhombododdyFace.h"
#include "RhombododdyPrimitive.h"

class RhombododdyLattice {
public:
    RhombododdyLattice();
    ~RhombododdyLattice();

    void draw();

    float getSize();
    void setSize(float size);

    LatticePosition* getPosition(int index);
    LatticePosition* getPosition(int x, int y, int z);
    void setPosition(int x, int y, int z, bool v);
    int positionCount();

    LatticePosition* getSelectedPosition();
    int getSelectedIndex();
    void setSelectedIndex(int i);

    void setColor(int index, ofColor color);

    void debug();

protected:
    void initMaterial();

    void drawRhombododdy(LatticePosition* p);
    int getIndexOfPosition(int x, int y, int z);
    void calculateNeighbors();
    void calculateNeighbors(LatticePosition* pos);
    LatticePosition* getNeighbor(LatticePosition* pos, int face);

    void debug(LatticePosition* pos);

    RhombododdyPrimitive rhombododdy;

    float size;
    std::vector<LatticePosition*> positions;
    int selectedIndex;

    ofMaterial normalMaterial;
    ofMaterial selectedMaterial;
};

