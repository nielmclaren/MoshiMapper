
#include "ofGraphics.h"
#include "LatticePosition.h"
#include "RhombododdyPrimitive.h"

class RhombododdyLattice {
public:
    RhombododdyLattice();
    ~RhombododdyLattice();

    void draw();

    float getSize();
    void setSize(float size);

    void setPosition(int x, int y, int z, bool v);

protected:
    void drawRhombododdy(LatticePosition* p);
    int getIndexOfPosition(int x, int y, int z);

    RhombododdyPrimitive rhombododdy;

    float size;
    std::vector<LatticePosition*> positions;
};

