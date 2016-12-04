
#include "ofApp.h"
#include "scene/gameTitle.h"
#include "scene/gameMain.h"


void ofApp::setup() {
  ofxJSON json;
  json.open("game.json");

  sceneMgr_ = ofxSceneManager::instance();
  
  // シーンを追加
  sceneMgr_->addScene(new GameTitle(), TITLE);
  sceneMgr_->addScene(new GameMain(),  GAME);
  
  // 指定したデフォルトのシーンへ遷移
  sceneMgr_->goToScene(json["defaultScene"].asInt(), false, false);
  
  // 遷移のフェード時間を設定
  sceneMgr_->setCurtainDropTime(json["fade"]["dropTime"].asFloat());
  sceneMgr_->setCurtainRiseTime(json["fade"]["riseTime"].asFloat());
  
  acc_ = json["acceleration"].asFloat();
  
  gui_.setup();
}

void ofApp::update() {
  float dt = ofGetLastFrameTime() * acc_;
  sceneMgr_->update(dt);
}

void ofApp::draw() {
  gui_.begin();
  sceneMgr_->draw();
  
  ImGui::Begin("Root");
  ImGui::Text("%s", string("width  :" + ofToString(ofGetWidth())).c_str());
  ImGui::Text("%s", string("height :" + ofToString(ofGetHeight())).c_str());
  ImGui::Text("%s", string("FPS :" + ofToString(ofGetFrameRate() , 1)).c_str());
  
  ImGui::SliderFloat("Acceleration", &acc_, 0, 5);
  
  if (ImGui::Button("scene change to GameTitle")) { sceneMgr_->goToScene(TITLE); }
  if (ImGui::Button("scene change to GameMain"))  { sceneMgr_->goToScene(GAME);  }
  ImGui::End();
  gui_.end();
}
