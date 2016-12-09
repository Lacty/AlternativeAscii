
#pragma once
#include "ofMain.h"
#include "ofxImGui.h"
#include "ofxJSONElement.h"


class SeekBar {
private:
  int height_;
  int barWidth_;
  
  ofColor_<float> rootColor_;
  ofColor_<float> seekedColor_;
  ofColor_<float> barColor_;
  
public:
  
  void setup(const string& path);
  
  void draw(int maxTime, int limitTime);
  void drawParam();
};
