#pragma once

#include "ofMain.h"
#include "PhoneStrand.h"
#include "RhombododdyLattice.h"

class LightController {
public:
    LightController();
    ~LightController();

    void step();
    void stepLattice();
    void stepStrand(int index, PhoneStrand* strand);

    void setLattice(RhombododdyLattice* lattice);
    void setStrands(std::vector<PhoneStrand*>*);

private:
    float modTime(int duration);
    float splitTime(float t);
    float clampTime(float t);

    bool hasLattice;
    bool hasStrands;
    RhombododdyLattice* lattice;
    std::vector<PhoneStrand*>* strands;
};

