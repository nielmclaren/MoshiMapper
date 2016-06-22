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

    void input(float* input);

    void setLattice(RhombododdyLattice* lattice);
    void setStrands(std::vector<PhoneStrand*>*);

private:
    float getStrandSegmentValue(int strandIndex, int segmentIndex, int segmentCount);
    int getInputHistoryIndexByDelay(int delayMs);
    float getInputHistoryValue(int strandIndex, int segmentIndex);

    float modTime(int duration);
    float splitTime(float t);
    float clampTime(float t);

    bool hasLattice;
    bool hasStrands;
    RhombododdyLattice* lattice;
    std::vector<PhoneStrand*>* strands;

    int numChannels;
    std::array<std::deque<float>, 6> inputHistory;
    std::deque<unsigned long> inputHistoryTimings;

    int strandDelayMs;
};

