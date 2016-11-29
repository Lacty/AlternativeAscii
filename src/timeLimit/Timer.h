﻿
#pragma once
#include "ofMain.h"
#include "ofxImGui.h"
#include "ofxXmlSettings.h"
#include <chrono>


class Timer {
private:
<<<<<<< HEAD
  int limit_;  // 表示される残り時間
  float startTime_; // 計測開始時の時間を保存
=======
  float limit_;  // �\�������c�莞��
  float currentTime_;
  float startTime_; // �v���J�n���̎��Ԃ�ۑ�
>>>>>>> wem-branch
  float fontSize_;
  ofTrueTypeFont font_; // 表示する際のフォントとサイズを入れる箱
  ofxXmlSettings xml_;

<<<<<<< HEAD
  // 以下gui用
  ofxPanel gui_;
  ofxFloatSlider fontScale_;
  ofxIntSlider maxTime_;
  ofxButton reset_;
  ofxButton save_;
  ofxButton load_;
=======
  float fontScale_;
  int maxTime_;
>>>>>>> wem-branch

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

<<<<<<< HEAD
  void resetElapsed();  // タイマーリセット
=======
  void setFontScale(int fontScale);
  int getFontScale();

  void reset();
>>>>>>> wem-branch
  void setup();
  void update(ofEventArgs &args);
  void draw();
  bool isTimeup();
  void drawParam();
};
