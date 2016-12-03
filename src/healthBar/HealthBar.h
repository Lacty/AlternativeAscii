
#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "player.h"

class HealthBar {
private:
  float currentScale_; // ・ｽ・ｽ・ｽﾝＨ・ｽo・ｽo・ｽ[・ｽﾌ抵ｿｽ・ｽ・ｽ
  float tempHealth_; // ・ｽ・ｽ・ｽe・ｽO・ｽﾌＨ・ｽo・ｽ・ｽ・ｽ齊橸ｿｽﾛ托ｿｽ・ｽ・ｽ・ｽﾄゑｿｽ・ｽ・ｽ・ｽ・ｽ
  float damageScale_;  // ・ｽ_・ｽ・ｽ・ｽ[・ｽW・ｽo・ｽ[・ｽﾌ抵ｿｽ・ｽ・ｽ・ｽ・ｽ・ｽ齊橸ｿｽﾛ托ｿｽ・ｽ・ｽ・ｽﾄゑｿｽ・ｽ・ｽ・ｽ・ｽ
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
