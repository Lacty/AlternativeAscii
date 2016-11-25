
#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"
#include <chrono>


class Timer {
private:
  int limit_;  // �\�������c�莞��
  float startTime_; // �v���J�n���̎��Ԃ�ۑ�
  float fontSize_;
  ofTrueTypeFont font_; // �\������ۂ̃t�H���g�ƃT�C�Y�����锠
  ofxXmlSettings xml_;

  // �ȉ�gui�p
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

  void resetElapsed();  // �^�C�}�[���Z�b�g
  void setup();
  void update(ofEventArgs &args);
  void draw();
  bool isTimeup();
};
