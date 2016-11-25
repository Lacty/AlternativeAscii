
#include "Timer.h"


void Timer::setMaxTime(int maxTime) { maxTime_ = maxTime; }
int Timer::getMaxTime() { return maxTime_; }

void Timer::setLimit(int limit) { limit_ = limit; }
int Timer::getLimit() { return limit_; }

void Timer::setFontSize(int fontSize) { fontSize_ = fontSize; }
int Timer::getFontSize() { return fontSize_; }

// 経過時間に制限時間の最大値を代入(毎試合最初に呼び出す想定)
void Timer::resetElapsed() { ofResetElapsedTimeCounter(); }

void  Timer::setup() {
  fontSetup();
  loadMaxTime();
  guiSetup();
  ofAddListener(ofEvents().update, this, &Timer::update);
}

void Timer::update(ofEventArgs &args) {
  // 最大時間 - 経過時間を表示用変数に代入
  limit_ = maxTime_ - (ofGetElapsedTimef() - startTime_);
}

void Timer::draw() {
  drawTimer();
  gui_.draw();
}

bool Timer::isTimeup() {
  if (limit_ > 0) {
    return false;
  }
  else {
    return true;
  }
}

void Timer::guiSetup() {
  reset_.addListener(this, &Timer::resetElapsed);
  save_.addListener(this, &Timer::saveFile);
  load_.addListener(this, &Timer::loadFile);

  gui_.setup();
  gui_.add(fontScale_.setup("FontScale", 100, 0, 1000));
  gui_.add(maxTime_.setup("MaxTime", 60, 0, 99));
  gui_.add(reset_.setup("Time_Reset!"));
  gui_.add(save_.setup("Save_To_File"));
  gui_.add(load_.setup("Loda_From_File"));
  // xmlにセーブしてある値を最初に呼び出しておく
  gui_.loadFromFile("Game/TimerSettings.xml");
}

// フォント読み込み
void Timer::fontSetup() {
  loadFontSize();
  font_.loadFont("consolab.ttf", fontSize_);
}

// xmlファイルから制限時間の最大値をロード
void Timer::loadMaxTime() {
  if (xml_.loadFile("Game/TimerSettings.xml")) {
    setMaxTime(xml_.getValue("group:MaxTime", 0));
    setLimit(maxTime_); // 最大値のロードと同時に制限時間に同じ値を代入
  }
}

// xmlファイルからフォントサイズのロード
void Timer::loadFontSize() {
  if (xml_.loadFile("Game/TimerSettings.xml")) {
    setFontSize(xml_.getValue("group:FontSize", 0));
  }
}

// 画面上部、センターに表示
void Timer::drawTimer() {
  ofPushMatrix();
  ofPushStyle();

  ofSetColor(255, 255, 0);
  string text;
  // 表示するtextの中身を残り時間で切り替える
  if (!isTimeup()) { text = ofToString((int)limit_);  }
  else { text = ofToString(0); }
  float fontWidth = font_.stringWidth(text);
  float fontHeight = font_.stringHeight(text);

  ofTranslate(ofGetWidth() / 2, 0);
  ofScale((ofGetWidth() / fontScale_), (ofGetHeight() / fontScale_), 1);
  font_.drawString(text, -fontWidth / 2, fontHeight); // タイマーの描画

  ofPopStyle();
  ofPopMatrix();
}

void Timer::saveFile() {
  gui_.saveToFile("Game/TimerSettings.xml");
}

void Timer::loadFile() {
  gui_.loadFromFile("Game/TimerSettings.xml");
}
