
#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"
#include <chrono>


class Timer {
private:
  int limit_;  // 表示される残り時間
  float startTime_; // 計測開始時の時間を保存
  float fontSize_;
  ofTrueTypeFont font_; // 表示する際のフォントとサイズを入れる箱
  ofxXmlSettings xml_;

  // 以下gui用
  ofxPanel gui_;
  ofxFloatSlider fontScale_;
  ofxIntSlider maxTime_;
  ofxButton reset_;
  ofxButton save_;
  ofxButton load_;

  void guiSetup();
  void fontSetup();
  void loadMaxTime();
  void loadFontSize();
  void drawTimer();
  void saveFile();
  void loadFile();
public:
  void setLimit(int time);
  int getLimit();

  void setMaxTime(int maxTime);
  int getMaxTime();

  void setFontSize(int fontSize);
  int getFontSize();

  void resetElapsed();  // タイマーリセット
  void setup();
  void update(ofEventArgs &args);
  void draw();
  bool isTimeup();
};
