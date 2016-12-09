
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

inline void Timer::setMaxTime(int maxTime) { maxTime_ = maxTime; }

inline int Timer::getMaxTime() { return maxTime_; }

inline void Timer::setLimit(float limit) { limit_ = limit; }
inline int Timer::getLimit() { return limit_; }

inline void Timer::setFontSize(int fontSize) { fontSize_ = fontSize; }
inline int Timer::getFontSize() { return fontSize_; }

inline void Timer::setFontScale(int fontScale) { fontScale_ = fontScale; }
inline int Timer::getFontScale() { return fontScale_; }

inline void Timer::reset() { startTime_ = currentTime_; }
