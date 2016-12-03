
#include "healthBar.h"


void HealthBar::setBarScale(float x, float y) {
  scaleX_ = x;
  scaleY_ = y;
}

// １Ｒ毎に呼び出して下さい
void HealthBar::setup(Player &player) {
  guiSetup();
  loadParam(); // デフォルトの設定を最初に読み込む
  tempHealth_ = player.getMaxHP();  // 比較用ＨＰに最大値を代入
  currentScale_ = scaleX_; // バーの元の長さをロードして代入
  ofAddListener(ofEvents().update, this, &HealthBar::update);
}

void HealthBar::update(ofEventArgs &args) {
  if (damageScale_ != 0) {
    for (int i = 0; i < ofGetFrameRate() / 4; i++) {
      damageScale_ = damageScale_ - (damageScale_ / ofGetFrameRate() / 4);
    }
  }
}

void HealthBar::draw(Player &player) {
  // プレイヤー番号に応じて表示位置をズラす
  switch (player.getID()) {
  case 0:
    drawLeft();
    if (player.getHP() != tempHealth_) {
      setDamageScale(player);
    }
    updateLeft(player);
    break;

  case 1:
    drawRight();
    if (player.getHP() != tempHealth_) {
      setDamageScale(player);
    }
    updateRight(player);
    break;

  default:  // 例外の数字が入力された場合は１Ｐ側を表示
    drawLeft();
    if (player.getHP() != tempHealth_) {
      setDamageScale(player);
    }
    updateLeft(player);
    break;
  }
}

void HealthBar::drawParam() {
  ImGui::Begin("HealthBar_State");

  ImGui::SetWindowSize(ofVec2f(200, 200));
  ImGui::SliderFloat("Scale_X", &scaleX_, 0.0f, 1.0f);
  ImGui::SliderFloat("Scale_Y", &scaleY_, 0.0f, 1.0f);
  if (ImGui::Button("Save")) { saveParam(); }
  if (ImGui::Button("Load")) { loadParam(); }

  ImGui::End();
}

// 1Pなら
void HealthBar::drawLeft() {
  ofDrawRectangle(0, 0,
    (ofGetWidth() / 2) * currentScale_,
    (ofGetHeight() / 2) * scaleY_);
}

// 2Pなら
void HealthBar::drawRight() {
  ofDrawRectangle(ofGetWidth() - ((ofGetWidth() / 2) * currentScale_), 0,
    (ofGetWidth() / 2) * currentScale_,
    (ofGetHeight() / 2) * scaleY_);
}

void HealthBar::guiSetup() {
  ImGui::GetIO().MouseDrawCursor = false;
  xmlSetting(); // 変数:xml_ のアクセスするファイルを指定
}

void HealthBar::xmlSetting() {
  xml_.loadFile("Game/HealthBarSettings.xml");
  xml_.saveFile("Game/HealthBarSettings.xml");
}

void HealthBar::saveParam() {
  xml_.setValue("group:ScaleX", scaleX_);
  xml_.setValue("group:ScaleY", scaleY_);
  xml_.save("Game/HealthBarSettings.xml");
}

void HealthBar::loadParam() {
  setBarScale(xml_.getValue("group:ScaleX", 0.0f),
    xml_.getValue("group:ScaleY", 0.0f));
}

// 減少後のＨＰバーの長さを求める
float HealthBar::remnant(Player &player) {
  float restHealth = (float)player.getHP() / (float)player.getMaxHP();  // 現在ＨＰが最大ＨＰの何％になったか
  float newBarScale = scaleX_ * restHealth;  // 元のバーの長さから同じ％分だけ長さを短くする
  return newBarScale;
}

void HealthBar::setDamageScale(Player &player) {
  float damageCurrent = currentScale_ - remnant(player); // 赤ゲージの長さ(現在の長さ - 被ダメ計算後の長さ)
  currentScale_ = remnant(player); // ＨＰバーの長さを更新
  damageScale_ = damageCurrent;
}

// １ＰのＨＰ減少時
void HealthBar::updateLeft(Player &player) {
  // ダメージの赤いバーの表示
  ofPushStyle();
  ofSetColor(255, 0, 0);
  ofDrawRectangle((ofGetWidth() / 2) * currentScale_, 0,
    (ofGetWidth() / 2) * damageScale_,
    (ofGetHeight() / 2) * scaleY_);
  ofPopStyle();
  tempHealth_ = player.getHP();  // 現在ＨＰの更新
}

// ２ＰのＨＰ減少時
void HealthBar::updateRight(Player &player) {
  // ダメージの赤いバーの表示
  ofPushStyle();
  ofSetColor(255, 0, 0);
  ofDrawRectangle(ofGetWidth() - ((ofGetWidth() / 2) * (currentScale_ + damageScale_)), 0,
    (ofGetWidth() / 2) * damageScale_,
    (ofGetHeight() / 2) * scaleY_);
  ofPopStyle();
  tempHealth_ = player.getHP();  // 現在ＨＰの更新
}
