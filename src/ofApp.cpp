
#include "ofApp.h"
#include "scene/gameTitle.h"
#include "scene/gameMain.h"

// test scenes
#include "scene/p/sceneP.h"
#include "scene/wem/sceneWem.h"
#include "scene/yanai/sceneYanai.h"


void ofApp::setup() {
  ofxJSONElement json;
  json.open("game.json");

  sceneMgr_ = ofxSceneManager::instance();
  
  // シーンを追加
  sceneMgr_->addScene(new GameTitle(), TITLE);
  sceneMgr_->addScene(new GameMain(),  GAME);
  
  // test scenes
  sceneMgr_->addScene(new SceneP(),     SCENE_P);
  sceneMgr_->addScene(new SceneWem(),   SCENE_WEM);
  sceneMgr_->addScene(new SceneYanai(), SCENE_YANAI);
  
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
  
  if (ImGui::Button("scene change to GameTitle"))  { sceneMgr_->goToScene(TITLE);       }
  if (ImGui::Button("scene change to GameMain"))   { sceneMgr_->goToScene(GAME);        }
  if (ImGui::Button("scene change to SceneP"))     { sceneMgr_->goToScene(SCENE_P);     }
  if (ImGui::Button("scene change to SceneWem"))   { sceneMgr_->goToScene(SCENE_WEM);   }
  if (ImGui::Button("scene change to SceneYanai")) { sceneMgr_->goToScene(SCENE_YANAI); }
  ImGui::End();
  gui_.end();
}
