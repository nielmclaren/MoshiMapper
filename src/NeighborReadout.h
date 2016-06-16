
#include "ofMain.h"
#include "LatticePosition.h"
#include "RhombododdyFace.h"

class NeighborReadout {
public:
    NeighborReadout();
    ~NeighborReadout();

    void draw(int x, int y);
    void set(LatticePosition* p);
private:
    void drawRhombododdy(int x, int y, int h);
    void drawRhombus(int x, int y, int h);
    void drawNeighbors(int x, int y);
    void drawExpandedRhombododdy(int x, int y);
    void drawExpandedNeighbors(int x, int y);

    LatticePosition* pos;
    ofTrueTypeFont labelFont;
};

