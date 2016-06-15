
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

    LatticePosition* getPosition(int x, int y, int z);
    void setPosition(int x, int y, int z, bool v);

    void debug();

protected:
    void drawRhombododdy(LatticePosition* p);
    int getIndexOfPosition(int x, int y, int z);
    void calculateNeighbors();
    void calculateNeighbors(LatticePosition* pos);
    LatticePosition* getNeighbor(LatticePosition* pos, int face);

    RhombododdyPrimitive rhombododdy;

    float size;
    std::vector<LatticePosition*> positions;
};
