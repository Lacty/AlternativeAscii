
#include "Timer.h"


void Timer::setMaxTime(int maxTime) { maxTime_ = maxTime; }
int Timer::getMaxTime() { return maxTime_; }

void Timer::setLimit(float limit) { limit_ = limit; }
int Timer::getLimit() { return limit_; }

void Timer::setFontSize(int fontSize) { fontSize_ = fontSize; }
int Timer::getFontSize() { return fontSize_; }

void Timer::setFontScale(int fontScale) { fontScale_ = fontScale; }
int Timer::getFontScale() { return fontScale_; }

void Timer::reset() { startTime_ = currentTime_; }

void  Timer::setup() {
  guiSetup();
  fontSetup();
  loadMaxTime();
  reset();
  ofAddListener(ofEvents().update, this, &Timer::update);
}

void Timer::update(ofEventArgs &args) {
  currentTime_ = ofGetElapsedTimef();
  limit_ = maxTime_ - (currentTime_ - startTime_);
  ofLog() << ofGetElapsedTimef();
}

void Timer::draw() {
  drawTimer();
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
  startTime_ = 0;
  ImGui::GetIO().MouseDrawCursor = false;
}

// �t�H���g�ǂݍ���
void Timer::fontSetup() {
  loadFontScale();
  loadFontSize();
  font_.loadFont("consolab.ttf", fontSize_);
}

// xml�t�@�C�����琧�����Ԃ̍ő�l�����[�h
void Timer::loadMaxTime() {
  if (xml_.loadFile("Game/TimerSettings.xml")) {
    setMaxTime(xml_.getValue("group:MaxTime", 0));
    setLimit(maxTime_); // �ő�l�̃��[�h�Ɠ����ɐ������Ԃɓ����l����
  }
}

// xml�t�@�C������t�H���g�T�C�Y�̃��[�h
void Timer::loadFontSize() {
  if (xml_.loadFile("Game/TimerSettings.xml")) {
    setFontSize(xml_.getValue("group:FontSize", 0));
  }
}

// xml�t�@�C������`��T�C�Y�̃��[�h
void Timer::loadFontScale() {
  if (xml_.loadFile("Game/TimerSettings.xml")) {
    setFontScale(xml_.getValue("group:FontScale", 0));
  }
}

void Timer::saveFontScale() {
  if (xml_.saveFile("Game/TimerSettings.xml")) {
    xml_.setValue("group:FontScale", fontScale_);
    xml_.save("Game/TimerSettings.xml");
  }
}

// ��ʏ㕔�A�Z���^�[�ɕ\��
void Timer::drawTimer() {
  ofPushMatrix();
  ofPushStyle();

  ofSetColor(255, 255, 0);
  string text;
  // �\������text�̒��g���c�莞�ԂŐ؂�ւ���
  if (!isTimeup()) { text = ofToString((int)limit_); }
  else { text = ofToString(0); }
  float fontWidth = font_.stringWidth(text);
  float fontHeight = font_.stringHeight(text);

  ofTranslate(ofGetWidth() / 2, 0);
  ofScale((ofGetWidth() / fontScale_), (ofGetHeight() / fontScale_), 1);
  font_.drawString(text, -fontWidth / 2, fontHeight); // �^�C�}�[�̕`��

  ofPopStyle();
  ofPopMatrix();
}

void Timer::drawParam() {
  ImGui::Begin("TimerState");
  ImGui::SetWindowSize(ofVec2f(200, 200));
  ImGui::SliderFloat("Scale", &fontScale_, 0, 500);
  if (ImGui::Button("Time_Reset")) {
    reset();
  }
  if (ImGui::Button("Save")) {
    saveFontScale();
  }
  if (ImGui::Button("Load")) {
    loadFontScale();
  }
  ImGui::End();
}
