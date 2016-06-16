#pragma once

#include "ofMain.h"
#include "IndexInput.h"
#include "NeighborReadout.h"
#include "RhombododdyLattice.h"
#include "RhombododdyReport.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void setupLighting();
    void setupLattice();
    void setupIndexInput();

    void update();

    void draw();
    void drawIndexInput(int x, int y);
    void drawNeighborReadout(int x, int y);

    void selectedIndexChanged();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofEasyCam easyCam;

    int selectedIndex;
    RhombododdyLattice lattice;

    ofLight pointLight;
    ofLight pointLight2;
    ofLight pointLight3;

    IndexInput indexInput;
    NeighborReadout neighborReadout;
};

