
#include "ofApp.h"


void ofApp::setup() {
  GUI::get()->setup();
  cam_.setPosition(0, 0, 300);
  player_.setup(0);
}

void ofApp::update() {
  player_.update();
}

void ofApp::draw() {
  cam_.begin();
  
  // カメラの影響を受けるものを描画
  player_.draw();
  
  cam_.end();
  
  // カメラの影響を受けないuiなどの描画はここから
  GUI::get()->draw();
}
