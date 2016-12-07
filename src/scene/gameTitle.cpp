
#include "gameTitle.h"


void GameTitle::setup() {
  // gameTitle.jsonから設定を読み込む
  ofxJSONElement json;
  json.open("game.json");
  string j_path = json["gameTitlePath"].asString();
  json.open(j_path);
  
  // fontの設定をjsonから読み込む
  string path = json["Navi"]["fontPath"].asString();
  int size = json["Navi"]["fontSize"].asInt();
  font_.load(path, size);
  
  // 表示するnaviの文字列を読み込む
  navi_ = json["Navi"]["string"].asString();
}

void GameTitle::update(float deltaTime) {}

void GameTitle::draw() {
  // 文字列から描画時のサイズを算出
  float w = font_.stringWidth(navi_);
  
  // naviを描画
  ofPushMatrix();
  ofTranslate(ofGetWidth() * 0.5 - w * 0.5, ofGetHeight() * 0.7);
  font_.drawString(navi_, 0, 0);
  ofPopMatrix();
}
