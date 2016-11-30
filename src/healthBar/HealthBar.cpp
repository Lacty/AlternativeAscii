
#include "HealthBar.h"


void HealthBar::setBarScale(float x, float y) {
  scaleX_ = x;
  scaleY_ = y;
}

// �P�q���ɌĂяo���ĉ�����
void HealthBar::setup(Player &player) {
  loadFile(); // �f�t�H���g�̐ݒ����ŏ��ɓǂݍ���
  tempHealth = player.getMaxHP();  // ���r�p�g�o�ɍő��l������
  currentScale = scaleX_; // �o�[�̌��̒��������[�h���đ���
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
  // �v���C���[�ԍ��ɉ����ĕ\���ʒu���Y����
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

  default:  // ���O�̐��������͂��ꂽ�ꍇ�͂P�o�����\��
    drawLeft();
    if (player.getHP() != tempHealth) {
      setDamageScale(player);
    }
    updateLeft(player);
    break;
  }
}

// 1P�Ȃ�
void HealthBar::drawLeft() {
  ofDrawRectangle(0, 0,
    (ofGetWidth() / 2) * currentScale_,
    (ofGetHeight() / 2) * scaleY_);
}

// 2P�Ȃ�
void HealthBar::drawRight() {
  ofDrawRectangle(ofGetWidth() - ((ofGetWidth() / 2) * currentScale_), 0,
    (ofGetWidth() / 2) * currentScale_,
    (ofGetHeight() / 2) * scaleY_);
}

void HealthBar::loadFile() {
  if (xml_.loadFile("Game/HealthBarSettings.xml")) {
    setBarScale(xml_.getValue("group:ScaleX", 0.0),
                xml_.getValue("group:ScaleY", 0.0));
  }
}

// �������̂g�o�o�[�̒��������߂�
float HealthBar::remnant(Player &player) {
  float restHealth = (float)player.getHP() / (float)player.getMaxHP();  // ���݂g�o���ő��g�o�̉����ɂȂ�����
  float newBarScale = scaleX_ * restHealth;  // ���̃o�[�̒������瓯�����������������Z������
  return newBarScale;
}

void HealthBar::setDamageScale(Player &player) {
  float damageCurrent = currentScale - remnant(player); // �ԃQ�[�W�̒���(���݂̒��� - ���_���v�Z���̒���)
  currentScale = remnant(player); // �g�o�o�[�̒������X�V
  damageScale = damageCurrent;
}

// �P�o�̂g�o������
void HealthBar::updateLeft(Player &player) {
  // �_���[�W�̐Ԃ��o�[�̕\��
  ofPushStyle();
  ofSetColor(255, 0, 0);
  ofDrawRectangle((ofGetWidth() / 2) * currentScale_, 0,
    (ofGetWidth() / 2) * damageScale_,
    (ofGetHeight() / 2) * scaleY_);
  ofPopStyle();
  tempHealth = player.getHP();  // ���݂g�o�̍X�V
}

// �Q�o�̂g�o������
void HealthBar::updateRight(Player &player) {
  // �_���[�W�̐Ԃ��o�[�̕\��
  ofPushStyle();
  ofSetColor(255, 0, 0);
  ofDrawRectangle(ofGetWidth() - ((ofGetWidth() / 2) * (currentScale_ + damageScale_)), 0,
    (ofGetWidth() / 2) * damageScale_,
    (ofGetHeight() / 2) * scaleY_);
  ofPopStyle();
  tempHealth = player.getHP();  // ���݂g�o�̍X�V
}
