
#pragma once
#include "ofMain.h"
#include "ofxImGui.h"
#include "ofxSceneManager.h"
#include "ofxJSONElement.h"


class ofApp : public ofBaseApp {
private:
  ofxSceneManager* sceneMgr_;
  float acc_;
  
  ofxImGui gui_;
  
public:
  void setup();
  
  void update();
  void draw();
};
