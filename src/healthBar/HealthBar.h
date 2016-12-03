
#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "player.h"

class HealthBar {
private:
  float currentScale; // ���݂g�o�o�[�̒���
  float tempHealth; // ���e�O�̂g�o���ꎞ�ۑ����Ă�����
  float damageScale;  // �_���[�W�o�[�̒������ꎞ�ۑ����Ă�����
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
