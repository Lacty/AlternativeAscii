
#include "ofApp.h"


void ofApp::setup() {
  gui_.setup();
  cam_.setPosition(0, 0, 300);
  
  p1_.setup(0);
  p2_.setup(1);
  
  p1_.setOther(&p2_);
  p2_.setOther(&p1_);
}

void ofApp::update() {
  p1_.update();
  p2_.update();
}

void ofApp::draw() {
  cam_.begin();
  // カメラの影響を受けるものを描画
  p1_.draw();
  p2_.draw();
  
  p1_.drawCollision();
  p2_.drawCollision();
  
  cam_.end();
  
  // --
  
  gui_.begin();
  // カメラの影響を受けないuiなどの描画はここから
  p1_.drawParam();
  p2_.drawParam();
  
  gui_.end();
}
