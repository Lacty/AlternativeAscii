
#include "gui.h"


// インスタンスの作成
// staticなので一度呼べば一行目は呼ばれない
GUI* GUI::get() {
  static GUI instance;
  
  return &instance;
}

void GUI::setup() {
  gui_.setup();
}

void GUI::add(const string &name, ofxPanel &panel) {
  // 配列Panelを追加
  panels_.push_back(ofxPanel());
  panels_.back().setup();
  panels_.back() = panel;
  
  show_.push_back(ofxToggle());
  
  // 与えられた名前でトグルを追加
  gui_.add(show_.back().setup(name, false));
}

void GUI::draw() {
  gui_.draw();
  
  for (int i = 0; i < show_.size(); i++) {
    if (show_[i]) {
      panels_[i].draw();
    }
  }
}
