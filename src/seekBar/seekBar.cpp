
#include "seekBar.h"


void SeekBar::setup(const string& path) {
  // jsonから設定を読み込む
  ofxJSON json;
  json.open(path);
  
  // シークバーの高さ
  height_   = json["Root"]["height"].asInt();
  // バーの横幅
  barWidth_ = json["Bar"]["width"].asInt();
  
  // -----------------------------------------------------------------
  // 色の読み込み //
  for (int i = 0; i < 3; i++) {
    rootColor_[i]   = json["Root"]["color"][i].asFloat();
    seekedColor_[i] = json["Seeked"]["color"][i].asFloat();
    barColor_[i]    = json["Bar"]["color"][i].asFloat();
  }
}

void SeekBar::draw(int maxTime, int limitTime) {
  int         halfBarWidth (barWidth_ * 0.5);
  ofVec2f     barPos       ((ofGetWidth() - ((ofGetWidth() / maxTime) * limitTime)) - halfBarWidth,
                            ofGetHeight() - height_);
  ofVec2f     barSize      (barWidth_, height_);
  
  ofRectangle root         (0, ofGetHeight() - height_, ofGetWidth(), height_);
  ofRectangle seeked       (0, ofGetHeight() - height_, barPos.x, height_);
  ofRectangle bar          (barPos, barPos + barSize);

  // -----------------------------------------------------------------
  // ROOT
  // -----------------------------------------------------------------
  ofNoFill();
  ofSetColor(100, 100, 100);
  ofDrawRectangle(root);
  
  ofFill();
  ofSetColor(rootColor_);
  ofDrawRectangle(root);
  
  // -----------------------------------------------------------------
  // SEEKED BAR
  // -----------------------------------------------------------------
  ofNoFill();
  ofSetColor(100, 100, 100);
  ofDrawRectangle(seeked);
  
  ofFill();
  ofSetColor(seekedColor_);
  ofDrawRectangle(seeked);
  
  // -----------------------------------------------------------------
  // BAR
  // -----------------------------------------------------------------
  ofNoFill();
  ofNoFill();
  ofSetColor(100, 100, 100);
  ofDrawRectangle(bar);
  
  ofFill();
  ofSetColor(barColor_);
  ofDrawRectangle(bar);
}

void SeekBar::drawParam() {
  ImGui::Begin("SeekBar");
  
  ImGui::DragInt("Height", &height_);
  ImGui::DragInt("Bar Width", &barWidth_);
  
  ImGui::ColorEdit3("Root Color", &rootColor_.r);
  ImGui::ColorEdit3("Seeked Color", &seekedColor_.r);
  ImGui::ColorEdit3("Bar Color", &barColor_.r);
  
  ImGui::End();
}
