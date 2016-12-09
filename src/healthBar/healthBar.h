﻿
#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxImGui.h"
#include "player.h"

class HealthBar {
private:
  float currentScale_; // 現在ＨＰバーの長さ
  float tempHealth_; // 被弾前のＨＰを一時保存しておく箱
  float damageScale_;  // ダメージバーの長さを一時保存しておく箱
  ofxXmlSettings xml_;

  float scaleX_;
  float scaleY_;

  void drawLeft();
  void drawRight();
  float remnant(Player &player);
  void setDamageScale(Player &player);
  void updateLeft(Player &player);
  void updateRight(Player &player);
  void setBarScale(float x, float y);
  void guiSetup();
  void xmlSetting();
  void saveParam();
  void loadParam();
public:
  void setup(Player &player);
  void update(ofEventArgs &args);
  void draw(Player &player);
  void drawParam();
};
