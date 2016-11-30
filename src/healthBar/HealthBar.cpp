
#include "HealthBar.h"


void HealthBar::setBarScale(float x, float y) {
  scaleX_ = x;
  scaleY_ = y;
}

// １Ｒ毎に呼び出して下さい
void HealthBar::setup(Player &player) {
  loadFile(); // デフォルトの設定を最初に読み込む
  tempHealth = player.getMaxHP();  // 比較用ＨＰに最大値を代入
  currentScale = scaleX_; // バーの元の長さをロードして代入
  ofAddListener(ofEvents().update, this, &HealthBar::update);
}

void HealthBar::update(ofEventArgs &args) {
  if (damageScale != 0) {
    for (int i = 0; i < ofGetFrameRate()/4; i++) {
      damageScale = damageScale - (damageScale / ofGetFrameRate()/4);
    }
  }
}

void HealthBar::draw(Player &player) {
  // プレイヤー番号に応じて表示位置をズラす
  switch (player.getID()) {
  case 0:
    drawLeft();
    if (player.getHP() != tempHealth) {
      setDamageScale(player);
    }
    updateLeft(player);
    break;

  case 1:
    drawRight();
    if (player.getHP() != tempHealth) {
      setDamageScale(player);
    }
    updateRight(player);
    break;

  default:  // 例外の数字が入力された場合は１Ｐ側を表示
    drawLeft();
    if (player.getHP() != tempHealth) {
      setDamageScale(player);
    }
    updateLeft(player);
    break;
  }
}

// 1Pなら
void HealthBar::drawLeft() {
  ofRect(0, 0,
    (ofGetWidth() / 2) * currentScale,
    (ofGetHeight() / 2) * scaleY_);
}

// 2Pなら
void HealthBar::drawRight() {
  ofRect(ofGetWidth() - ((ofGetWidth() / 2) * currentScale), 0,
    (ofGetWidth() / 2) * currentScale,
    (ofGetHeight() / 2) * scaleY_);
}

void HealthBar::loadFile() {
  if (xml_.loadFile("Game/HealthBarSettings.xml")) {
    setBarScale(xml_.getValue("group:ScaleX", 0.0),
                xml_.getValue("group:ScaleY", 0.0));
  }
}

// 減少後のＨＰバーの長さを求める
float HealthBar::remnant(Player &player) {
  float restHealth = (float)player.getHP() / (float)player.getMaxHP();  // 現在ＨＰが最大ＨＰの何％になったか
  float newBarScale = scaleX_ * restHealth;  // 元のバーの長さから同じ％分だけ長さを短くする
  return newBarScale;
}

void HealthBar::setDamageScale(Player &player) {
  float damageCurrent = currentScale - remnant(player); // 赤ゲージの長さ(現在の長さ - 被ダメ計算後の長さ)
  currentScale = remnant(player); // ＨＰバーの長さを更新
  damageScale = damageCurrent;
}

// １ＰのＨＰ減少時
void HealthBar::updateLeft(Player &player) {
  // ダメージの赤いバーの表示
  ofPushStyle();
  ofSetColor(255, 0, 0);
  ofRect((ofGetWidth() / 2) * currentScale, 0,
    (ofGetWidth() / 2) * damageScale,
    (ofGetHeight() / 2) * scaleY_);
  ofPopStyle();
  tempHealth = player.getHP();  // 現在ＨＰの更新
}

// ２ＰのＨＰ減少時
void HealthBar::updateRight(Player &player) {
  // ダメージの赤いバーの表示
  ofPushStyle();
  ofSetColor(255, 0, 0);
  ofRect(ofGetWidth() - ((ofGetWidth() / 2) * (currentScale + damageScale)), 0,
    (ofGetWidth() / 2) * damageScale,
    (ofGetHeight() / 2) * scaleY_);
  ofPopStyle();
  tempHealth = player.getHP();  // 現在ＨＰの更新
}
