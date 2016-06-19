#pragma once

#include "ofMain.h"
#include "LatticePosition.h"
#include "RhombododdyFace.h"

class NeighborReadout {
public:
    NeighborReadout();
    ~NeighborReadout();

    void draw(int x, int y);
    void setPosition(LatticePosition* p);

    void drawRhombododdy(int x, int y, float h);
    void drawRhombododdyReadout(int x, int y, float h);
    void drawRhombus(int x, int y, float h);
    void drawNeighbors(int x, int y, float h);
    void drawExpandedRhombododdyReadout(int x, int y, float h);
    void drawExpandedNeighbors(int x, int y, float h);
    void drawNeighborString(LatticePosition* pos, int x, int y);
private:

    int index;
    LatticePosition* pos;
    ofTrueTypeFont titleFont;
    ofTrueTypeFont labelFont;
    ofTrueTypeFont neighborFont;
};

