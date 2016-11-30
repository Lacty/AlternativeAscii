
#pragma once
#include "ofMain.h"
#include "ofxImGui.h"
#include "ofxXmlSettings.h"
#include <chrono>


class Timer {
private:
  float limit_;  // 表示される残り時間
  float currentTime_;
  float startTime_; // 計測開始時の時間を保存
  float fontSize_;
  ofTrueTypeFont font_; // 表示する際のフォントとサイズを入れる箱
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
  void drawParam();
};
