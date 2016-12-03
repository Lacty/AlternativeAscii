
#pragma once
#include "ofMain.h"
#include "ofxImGui.h"
#include "player/player.h"


class ofApp : public ofBaseApp {
private:
  ofxImGui gui_;

  ofCamera cam_;
  Player p1_;
  Player p2_;
  
public:
  void setup();
  
  void update();
  void draw();
};
