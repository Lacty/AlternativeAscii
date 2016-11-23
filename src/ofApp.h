
#pragma once
#include "ofMain.h"
#include "gui.h"
#include "player/player.h"


class ofApp : public ofBaseApp {
private:
  ofCamera cam_;
  Player player_;
  
public:
  void setup();
  
  void update();
  void draw();
};
