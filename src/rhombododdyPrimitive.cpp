
#include "RhombododdyPrimitive.h"

RhombododdyPrimitive::RhombododdyPrimitive() {
    texCoords = ofVec4f(0,0,1,1);
    set(100, 2);
}

RhombododdyPrimitive::RhombododdyPrimitive(float size, int res) {
    texCoords = ofVec4f(0,0,1,1);
    set(size, res);
}

RhombododdyPrimitive::~RhombododdyPrimitive() {}

void RhombododdyPrimitive::set(float sizeArg, int res) {
    //
    // FIXME: This hasn't been updated from ofBoxPrimitive
    //
    size = sizeArg;
    resolution = res;

    int resX = res;
    int resY = res;
    int resZ = res;
/*
    //FRONT, resY, resX
    strides[ SIDE_FRONT ][0] = 0;
    strides[ SIDE_FRONT ][1] = (resY)*(resX)*6;
    vertices[SIDE_FRONT][0] = 0;
    vertices[SIDE_FRONT][1] = (resX+1) * (resY+1);

    //RIGHT, resY, resZ
    strides[ SIDE_RIGHT ][0] = strides[ SIDE_FRONT ][0] + strides[ SIDE_FRONT ][1];
    strides[ SIDE_RIGHT ][1] = (resY)*(resZ)*6;
    vertices[SIDE_RIGHT][0] = vertices[SIDE_FRONT][0] + vertices[SIDE_FRONT][1];
    vertices[SIDE_RIGHT][1] = (resY+1) * (resZ+1);

    //LEFT, resY, resZ
    strides[ SIDE_LEFT ][0] = strides[ SIDE_RIGHT ][0] + strides[ SIDE_RIGHT ][1];
    strides[ SIDE_LEFT ][1] = (resY)*(resZ)*6;
    vertices[SIDE_LEFT][0] = vertices[SIDE_RIGHT][0] + vertices[SIDE_RIGHT][1];
    vertices[SIDE_LEFT][1] = (resY+1) * (resZ+1);

    //BACK, resY, resX
    strides[ SIDE_BACK ][0] = strides[ SIDE_LEFT ][0] + strides[ SIDE_LEFT ][1];
    strides[ SIDE_BACK ][1] = (resY)*(resX)*6;
    vertices[SIDE_BACK][0] = vertices[SIDE_LEFT][0] + vertices[SIDE_LEFT][1];
    vertices[SIDE_BACK][1] = (resY+1) * (resZ+1);

    //TOP, resZ, resX
    strides[ SIDE_TOP ][0] = strides[ SIDE_BACK ][0] + strides[ SIDE_BACK ][1];
    strides[ SIDE_TOP ][1] = (resZ)*(resX)*6;
    vertices[SIDE_TOP][0] = vertices[SIDE_BACK][0] + vertices[SIDE_BACK][1];
    vertices[SIDE_TOP][1] = (resY+1) * (resZ+1);

    //BOTTOM, resZ, resX
    strides[ SIDE_BOTTOM ][0] = strides[ SIDE_TOP ][0]+strides[ SIDE_TOP ][1];
    strides[ SIDE_BOTTOM ][1] = (resZ)*(resX)*6;
    vertices[SIDE_BOTTOM][0] = vertices[SIDE_TOP][0] + vertices[SIDE_TOP][1];
    vertices[SIDE_BOTTOM][1] = (resY+1) * (resZ+1);
*/
    getMesh() = rhombododdyMesh(size, resolution);

    normalizeAndApplySavedTexCoords();
}

ofMesh RhombododdyPrimitive::rhombododdyMesh(float size, int res) {
  ofMesh mesh;
  mesh.setMode(OF_PRIMITIVE_TRIANGLES);

  float longDiag = size;
  float shortDiag = size / sqrt(2);
  float halfLong = longDiag / 2;
  float halfShort = shortDiag / 2;

  ofVec3f vertex;
  ofVec2f texCoord;
  ofVec3f normal;

  std:size_t vertexOffset = 0;

  // FRONT
  normal.set(0, 0, 1);

  texCoord.x = 0.5;
  texCoord.y = 1;

  vertex.x = 0;
  vertex.y = halfLong;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 1;
  texCoord.y = 0.5;

  vertex.x = halfShort;
  vertex.y = 0;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0.5;
  texCoord.y = 0;

  vertex.x = 0;
  vertex.y = -halfLong;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0;
  texCoord.y = 0.5;

  vertex.x = -halfShort;
  vertex.y = 0;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  mesh.addIndex(0 + vertexOffset);
  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(2 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  vertexOffset = mesh.getNumVertices();

  // BACK
  normal.set(0, 0, -1);

  texCoord.x = 0.5;
  texCoord.y = 1;

  vertex.x = 0;
  vertex.y = halfLong;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 1;
  texCoord.y = 0.5;

  vertex.x = halfShort;
  vertex.y = 0;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0.5;
  texCoord.y = 0;

  vertex.x = 0;
  vertex.y = -halfLong;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0;
  texCoord.y = 0.5;

  vertex.x = -halfShort;
  vertex.y = 0;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  mesh.addIndex(0 + vertexOffset);
  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(2 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  vertexOffset = mesh.getNumVertices();

  // TOP
  normal.set(0, 1, 0);

  texCoord.x = 0.5;
  texCoord.y = 1;

  vertex.x = 0;
  vertex.y = halfLong;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 1;
  texCoord.y = 0.5;

  vertex.x = halfShort;
  vertex.y = halfLong;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0.5;
  texCoord.y = 0;

  vertex.x = 0;
  vertex.y = halfLong;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0;
  texCoord.y = 0.5;

  vertex.x = -halfShort;
  vertex.y = halfLong;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  mesh.addIndex(0 + vertexOffset);
  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(2 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  vertexOffset = mesh.getNumVertices();

  // BOTTOM
  normal.set(0, -1, 0);

  texCoord.x = 0.5;
  texCoord.y = 1;

  vertex.x = 0;
  vertex.y = -halfLong;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 1;
  texCoord.y = 0.5;

  vertex.x = halfShort;
  vertex.y = -halfLong;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0.5;
  texCoord.y = 0;

  vertex.x = 0;
  vertex.y = -halfLong;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0;
  texCoord.y = 0.5;

  vertex.x = -halfShort;
  vertex.y = -halfLong;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  mesh.addIndex(0 + vertexOffset);
  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(2 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  vertexOffset = mesh.getNumVertices();

  // LEFT TOP FRONT
  normal.set(-1/sqrt(2), 0.5, 0.5);

  texCoord.x = 0.5;
  texCoord.y = 1;

  vertex.x = 0;
  vertex.y = halfLong;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 1;
  texCoord.y = 0.5;

  vertex.x = -halfShort;
  vertex.y = halfLong;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0.5;
  texCoord.y = 0;

  vertex.x = -2 * halfShort;
  vertex.y = 0;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0;
  texCoord.y = 0.5;

  vertex.x = -halfShort;
  vertex.y = 0;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  mesh.addIndex(0 + vertexOffset);
  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(2 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  vertexOffset = mesh.getNumVertices();

  // LEFT TOP BACK
  normal.set(-1/sqrt(2), 0.5, -0.5);

  texCoord.x = 0.5;
  texCoord.y = 1;

  vertex.x = 0;
  vertex.y = halfLong;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 1;
  texCoord.y = 0.5;

  vertex.x = -halfShort;
  vertex.y = halfLong;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0.5;
  texCoord.y = 0;

  vertex.x = -2 * halfShort;
  vertex.y = 0;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0;
  texCoord.y = 0.5;

  vertex.x = -halfShort;
  vertex.y = 0;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  mesh.addIndex(0 + vertexOffset);
  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(2 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  vertexOffset = mesh.getNumVertices();

  // LEFT BOTTOM FRONT
  normal.set(-1/sqrt(2), -0.5, 0.5);

  texCoord.x = 0.5;
  texCoord.y = 1;

  vertex.x = 0;
  vertex.y = -halfLong;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 1;
  texCoord.y = 0.5;

  vertex.x = -halfShort;
  vertex.y = -halfLong;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0.5;
  texCoord.y = 0;

  vertex.x = -2 * halfShort;
  vertex.y = 0;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0;
  texCoord.y = 0.5;

  vertex.x = -halfShort;
  vertex.y = 0;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  mesh.addIndex(0 + vertexOffset);
  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(2 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  vertexOffset = mesh.getNumVertices();

  // LEFT BOTTOM BACK
  normal.set(-1/sqrt(2), -0.5, -0.5);

  texCoord.x = 0.5;
  texCoord.y = 1;

  vertex.x = 0;
  vertex.y = -halfLong;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 1;
  texCoord.y = 0.5;

  vertex.x = -halfShort;
  vertex.y = -halfLong;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0.5;
  texCoord.y = 0;

  vertex.x = -2 * halfShort;
  vertex.y = 0;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0;
  texCoord.y = 0.5;

  vertex.x = -halfShort;
  vertex.y = 0;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  mesh.addIndex(0 + vertexOffset);
  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(2 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  vertexOffset = mesh.getNumVertices();

  // RIGHT TOP FRONT
  normal.set(1/sqrt(2), 0.5, 0.5);

  texCoord.x = 0.5;
  texCoord.y = 1;

  vertex.x = 0;
  vertex.y = halfLong;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 1;
  texCoord.y = 0.5;

  vertex.x = halfShort;
  vertex.y = halfLong;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0.5;
  texCoord.y = 0;

  vertex.x = 2 * halfShort;
  vertex.y = 0;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0;
  texCoord.y = 0.5;

  vertex.x = halfShort;
  vertex.y = 0;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  mesh.addIndex(0 + vertexOffset);
  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(2 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  vertexOffset = mesh.getNumVertices();

  // RIGHT TOP BACK
  normal.set(1/sqrt(2), 0.5, -0.5);

  texCoord.x = 0.5;
  texCoord.y = 1;

  vertex.x = 0;
  vertex.y = halfLong;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 1;
  texCoord.y = 0.5;

  vertex.x = halfShort;
  vertex.y = halfLong;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0.5;
  texCoord.y = 0;

  vertex.x = 2 * halfShort;
  vertex.y = 0;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0;
  texCoord.y = 0.5;

  vertex.x = halfShort;
  vertex.y = 0;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  mesh.addIndex(0 + vertexOffset);
  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(2 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  vertexOffset = mesh.getNumVertices();

  // RIGHT BOTTOM FRONT
  normal.set(1/sqrt(2), -0.5, 0.5);

  texCoord.x = 0.5;
  texCoord.y = 1;

  vertex.x = 0;
  vertex.y = -halfLong;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 1;
  texCoord.y = 0.5;

  vertex.x = halfShort;
  vertex.y = -halfLong;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0.5;
  texCoord.y = 0;

  vertex.x = 2 * halfShort;
  vertex.y = 0;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0;
  texCoord.y = 0.5;

  vertex.x = halfShort;
  vertex.y = 0;
  vertex.z = halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  mesh.addIndex(0 + vertexOffset);
  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(2 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  vertexOffset = mesh.getNumVertices();

  // RIGHT BOTTOM BACK
  normal.set(1/sqrt(2), -0.5, -0.5);

  texCoord.x = 0.5;
  texCoord.y = 1;

  vertex.x = 0;
  vertex.y = -halfLong;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 1;
  texCoord.y = 0.5;

  vertex.x = halfShort;
  vertex.y = -halfLong;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0.5;
  texCoord.y = 0;

  vertex.x = 2 * halfShort;
  vertex.y = 0;
  vertex.z = 0;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  texCoord.x = 0;
  texCoord.y = 0.5;

  vertex.x = halfShort;
  vertex.y = 0;
  vertex.z = -halfLong;

  mesh.addVertex(vertex);
  mesh.addTexCoord(texCoord);
  mesh.addNormal(normal);

  mesh.addIndex(0 + vertexOffset);
  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  mesh.addIndex(1 + vertexOffset);
  mesh.addIndex(2 + vertexOffset);
  mesh.addIndex(3 + vertexOffset);

  vertexOffset = mesh.getNumVertices();

  return mesh;
}

void RhombododdyPrimitive::set(float sizeArg) {
    set(sizeArg, resolution);
}

vector<ofIndexType> RhombododdyPrimitive::getSideIndices( int sideIndex ) const {
    //
    // FIXME: This hasn't been updated from ofBoxPrimitive
    //
  if(sideIndex < 0 || sideIndex >= SIDES_TOTAL) {
    ofLogWarning("RhombododdyPrimitive") << "getSideIndices(): faceIndex out of bounds, returning SIDE_FRONT";
    sideIndex = SIDE_FRONT;
  }

  return getIndices(strides[sideIndex][0], strides[sideIndex][0] + strides[sideIndex][1]);
}

ofMesh RhombododdyPrimitive::getSideMesh(int sideIndex) const {
    //
    // FIXME: This hasn't been updated from ofBoxPrimitive
    //
  if(sideIndex < 0 || sideIndex > SIDES_TOTAL) {
    ofLogWarning("RhombododdyPrimitive") << "getSideMesh(): faceIndex out of bounds, using SIDE_FRONT";
    sideIndex = SIDE_FRONT;
  }
  int startIndex  = strides[sideIndex][0];
  int endIndex    = startIndex+strides[sideIndex][1];

  int startVertIndex  = vertices[sideIndex][0];
  int endVertIndex    = startVertIndex + vertices[sideIndex][1];

  return getMesh().getMeshForIndices( startIndex, endIndex, startVertIndex, endVertIndex );
}

void RhombododdyPrimitive::setResolution(int res) {
  resolution = res;
}

void RhombododdyPrimitive::setMode( ofPrimitiveMode mode ) {
    // only supports triangles //
    setResolution(resolution);
}

int RhombododdyPrimitive::getResolution() const {
  return resolution;
}

float RhombododdyPrimitive::getSize() const {
    return size;
}
