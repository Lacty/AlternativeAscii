

#pragma once
#include "scene.h"


class GameTitle : public ofxScene {
private:
  ofTrueTypeFont font_;
  
  // "push any key"のようなnaviの文字列
  string navi_;
  
public:
  void setup() override;
  void update(float deltaTime) override;
  void draw() override;
};
