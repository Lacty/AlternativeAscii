
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
  // 配列に空のPanelを追加
  panels_.emplace_back(Panel());
  
  // 与えられた名前でトグルを追加
  panels_.back().panel.setup();
  gui_.add(panels_.back().show.setup(name, false));
  panels_.back().panel = panel;
}

void GUI::draw() {
  gui_.draw();
  
  for (auto& panel : panels_) {
    if (panel.show) {
      panel.panel.draw();
    }
  }
}
