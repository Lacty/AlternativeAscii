
#include "ofxSceneManager.h"
#include "gameMain.h"


void GameMain::setup() {
  // gameMain.jsonから設定を読み込む
  ofxJSONElement json;
  json.open("game.json");
  string j_path = json["gameMainPath"].asString();
  json.open(j_path);
}

void GameMain::update(float deltaTime) {}

void GameMain::draw() {
  ofDrawBitmapString("Game Main", 20, 20);
}
