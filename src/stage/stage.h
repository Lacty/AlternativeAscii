
#pragma once
#include "ofMain.h"
#include "ofxJSONElement.h"


class Stage {
public:
  static float Right;
  static float Left;
  static float Bottom;
  static float Top;
  
  static void setup(const string& path);
};
