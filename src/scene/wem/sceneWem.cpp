
#include "sceneWem.h"


void SceneWem::setup() {
  // sceneWem.jsonから設定を読み込む
  ofxJSON json;
  json.open("game.json");
  string j_path = json["sceneWemPath"].asString();
  json.open(j_path);
  
  cam_.setPosition(0, 0, 300);
  
  for (int i = 0; i < NUM_PLAYER; i++) {
    players_[i].setup(i);
  }
  players_[0].setOther(&players_[1]);
  players_[1].setOther(&players_[0]);
}

void SceneWem::update(float deltaTime) {
  for (int i = 0; i < NUM_PLAYER; i++) {
    players_[i].update();
  }
}

void SceneWem::draw() {
  ofDrawBitmapString("Game Main", 20, 20);
  
  cam_.begin();
  for (int i = 0; i < NUM_PLAYER; i++) {
    players_[i].draw();
    players_[i].drawCollision();
  }
  cam_.end();
  
  for (int i = 0; i < NUM_PLAYER; i++) {
    players_[i].drawParam();
  }
}
