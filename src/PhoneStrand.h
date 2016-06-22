#pragma once

#include "ofMain.h"
#include "ofGraphics.h"

class PhoneStrand {
public:
    PhoneStrand();
    ~PhoneStrand();

    void draw();

    int getSegmentCount();
    void setSegmentCount(int count);
    void setColor(int index, ofColor color);

protected:
    int segmentCount;
    ofColor* segments;
};

