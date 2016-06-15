
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
    void drawRhombododdy(int x, int y);
    void drawNeighbors(int x, int y);

    LatticePosition* pos;
};

