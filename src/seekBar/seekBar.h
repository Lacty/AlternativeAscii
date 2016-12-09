
#pragma once
#include "ofMain.h"
#include "ofxImGui.h"
#include "ofxJSONElement.h"


// シークバーを描画するクラス
// Timer依存
class SeekBar {
private:
  int height_;
  int barWidth_;
  
  ofColor_<float> rootColor_;
  ofColor_<float> seekedColor_;
  ofColor_<float> barColor_;
  
public:
  
  // jsonファイルのパスを指定して生成
  void setup(const string& path);
  
  // 描画
  // "試合時間"と"残り時間"を与えてください
  void draw(int maxTime, int limitTime);
  
  // Guiの描画
  void drawParam();
};
