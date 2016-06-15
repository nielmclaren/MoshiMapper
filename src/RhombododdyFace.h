#pragma once

class RhombododdyFace {
public:
  const static int TOP = 0;
  const static int BOTTOM = 1;
  const static int FRONT = 2;
  const static int BACK = 3;
  const static int LEFT_TOP_FRONT = 4;
  const static int LEFT_BOTTOM_FRONT = 5;
  const static int RIGHT_TOP_FRONT = 6;
  const static int RIGHT_BOTTOM_FRONT = 7;
  const static int LEFT_TOP_BACK = 8;
  const static int LEFT_BOTTOM_BACK = 9;
  const static int RIGHT_TOP_BACK = 10;
  const static int RIGHT_BOTTOM_BACK = 11;

  static string getDisplayName(int face) {
    switch (face) {
      case TOP:
        return "top";
      case BOTTOM:
        return "bottom";
      case FRONT:
        return "front";
      case BACK:
        return "back";
      case LEFT_TOP_FRONT:
        return "left top front";
      case LEFT_BOTTOM_FRONT:
        return "left bottom front";
      case RIGHT_TOP_FRONT:
        return "right top front";
      case RIGHT_BOTTOM_FRONT:
        return "right bottom front";
      case LEFT_TOP_BACK:
        return "left top back";
      case LEFT_BOTTOM_BACK:
        return "left bottom back";
      case RIGHT_TOP_BACK:
        return "right top back";
      case RIGHT_BOTTOM_BACK:
        return "right bottom back";
    }
  };
};

