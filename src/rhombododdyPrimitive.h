
#include "ofGraphics.h"
#include "of3dPrimitives.h"

class rhombododdyPrimitive : public of3dPrimitive {
public:

    enum Faces {
      SIDE_TOP,
      SIDE_BOTTOM,
      SIDE_FRONT,
      SIDE_BACK,
      SIDE_LEFT_TOP_FRONT,
      SIDE_LEFT_BOTTOM_FRONT,
      SIDE_RIGHT_TOP_FRONT,
      SIDE_RIGHT_BOTTOM_FRONT,
      SIDE_LEFT_TOP_BACK,
      SIDE_LEFT_BOTTOM_BACK,
      SIDE_RIGHT_TOP_BACK,
      SIDE_RIGHT_BOTTOM_BACK,
      SIDES_TOTAL
    };

    rhombododdyPrimitive();
    rhombododdyPrimitive(float size, int res);
    ~rhombododdyPrimitive();

    void set(float size, int res);
    void set(float size);

    void setSize(float size);

    vector<ofIndexType> getSideIndices(int sideIndex) const;
    ofMesh getSideMesh(int sideIndex) const;
    ofMesh rhombododdyMesh(float size, int res);

    void setResolution(int res);

    void setMode(ofPrimitiveMode mode);

    int getResolution() const;

    float getSize() const;
protected:
    float size;
    int resolution;
    // indices strides for faces //
    int strides[6][2];
    int vertices[6][2];

};
