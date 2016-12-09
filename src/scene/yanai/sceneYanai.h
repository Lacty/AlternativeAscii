

#pragma once
#include "../scene.h"
#include "../../player/player.h"

#include "../../stage/stage.h"

#include "../../timeLimit/timer.h"
#include "../../seekBar/seekBar.h"


class SceneYanai : public ofxScene {
private:
  ofCamera cam_;
  
  static const int NUM_PLAYER = 2;
  Player players_[NUM_PLAYER];
  
  Timer timer_;
  SeekBar seekBar_;
  
public:
  void setup() override;
  void update(float deltaTime) override;
  void draw() override;
};
