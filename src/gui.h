
#pragma once
#include "ofMain.h"
#include "ofxGui.h"


class GUI {
private:
  GUI() = default;
  
  ofxPanel gui_;
  
  struct Panel {
    ofxToggle show;
    ofxPanel  panel;
  };
  vector<Panel> panels_;
  
public:
  static GUI* get();
  
  void setup();
  void draw();
  
  // GUIへ登録
  void add(const string& name, ofxPanel& panel);
};
