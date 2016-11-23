
#include "gui.h"


GUI* GUI::get() {
  static GUI instance;
  return &instance;
}

void GUI::setup() {
  gui_.setup();
}

void GUI::add(const string &name, ofxPanel &panel) {
  panels_.emplace_back(Panel());
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
