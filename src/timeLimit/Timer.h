
#pragma once
#include "ofMain.h"
#include "ofxImGui.h"
#include "ofxXmlSettings.h"
#include <chrono>


class Timer {
private:
  float limit_;  // �\�������c�莞��
  float currentTime_;
  float startTime_; // �v���J�n���̎��Ԃ�ۑ�
  float fontSize_;
  ofTrueTypeFont font_; // �\������ۂ̃t�H���g�ƃT�C�Y�����锠
  ofxXmlSettings xml_;

  float fontScale_;
  int maxTime_;

  void guiSetup();
  void fontSetup();
  void loadMaxTime();
  void loadFontSize();
  void loadFontScale();
  void saveFontScale();
  void drawTimer();
  void drawParam();
public:
  void setLimit(float time);
  int getLimit();

  void setMaxTime(int maxTime);
  int getMaxTime();

  void setFontSize(int fontSize);
  int getFontSize();

  void setFontScale(int fontScale);
  int getFontScale();

  void reset();
  void setup();
  void update(ofEventArgs &args);
  void draw();
  bool isTimeup();
};
