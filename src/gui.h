
#pragma once
#include "ofMain.h"
#include "ofxGui.h"


class GUI {
private:
  GUI() = default;
  
  ofxPanel gui_;
  
  deque<ofxToggle> show_;
  deque<ofxPanel>  panels_;
  
public:
  static GUI* get();
  
  void setup();
  void draw();
  
  // GUIへ登録
  void add(const string& name, ofxPanel& panel);
};
