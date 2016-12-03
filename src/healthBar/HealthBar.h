
#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "player.h"

class HealthBar {
private:
  float currentScale_; // �E��E��E�݂g�E�o�E�o�E�[�E�̒��E��E�
  float tempHealth_; // �E��E��E�e�E�O�E�̂g�E�o�E��E��E�ꎞ�ۑ��E��E��E�Ă��E��E��E��E�
  float damageScale_;  // �E�_�E��E��E�[�E�W�E�o�E�[�E�̒��E��E��E��E��E�ꎞ�ۑ��E��E��E�Ă��E��E��E��E�
  ofxXmlSettings xml_;

  float scaleX_;
  float scaleY_;

  void drawLeft();
  void drawRight();
  void loadFile();
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
};
