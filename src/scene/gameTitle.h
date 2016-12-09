

#pragma once
#include "scene.h"
#include "ofxJoystick.h"
#include "input.h"


class GameTitle : public ofxScene {
private:
  ofTrueTypeFont font_;
  
  // "push any key"のようなnaviの文字列
  string navi_;
  
  ofxJoystick joy_;
  
public:
  void setup() override;
  void update(float deltaTime) override;
  void draw() override;
};
