

#pragma once
#include "../scene.h"
#include "../../player/player.h"


class SceneWem : public ofxScene {
private:
  ofCamera cam_;
  
  static const int NUM_PLAYER = 2;
  Player players_[NUM_PLAYER];
  
public:
  void setup() override;
  void update(float deltaTime) override;
  void draw() override;
};
