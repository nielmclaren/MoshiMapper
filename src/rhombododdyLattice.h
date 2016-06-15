
#include "ofGraphics.h"
#include "latticePosition.h"
#include "rhombododdyPrimitive.h"

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

    rhombododdyPrimitive rhombododdy;

    int getIndexOfPosition(int x, int y, int z);

    float size;
    std::vector<LatticePosition*> positions;
};

