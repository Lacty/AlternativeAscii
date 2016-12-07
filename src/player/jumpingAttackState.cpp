
#include "playerState.h"
#include "player.h"


const int FLOOR = 0;

shared_ptr<PlayerState> JumpingAttackState::handleInput(Player& player, ofxJoystick& input) {
  // �U�����[�V�������I��邩�A�W�����v��Ԃł͂Ȃ��Ȃ�����I��
  if (finish() || player.getPos().y < FLOOR) {
    // ���� �U���p�����S������
    // �㑱����U���ɑΉ��ł��Ȃ��̂ŗv�C��
    player.getAttackCol().clear();

    // �U�����[�V�������I�������O�̏�Ԃɖ߂�
    return PlayerState::finish;
  }

  return nullptr;
}

void JumpingAttackState::update(Player& player, ofxJoystick& input) {
  JumpingState::update(player, input);
}

void JumpingAttackState::entry(Player& player) {
  start_ = ofGetElapsedTimef();
  end_ = 0.5f;

  // ���� �U���p�e�X�g�R�[�h�Ȃ̂ŗv�C��
  // ��x�ɔ����ł���U������̏ꍇ�ɂ̂ݗL��
  player.getAttackCol().push_back({ ofVec2f(30, 0), ofVec2f(20, 10) });
}

bool JumpingAttackState::finish() {
  // �U�����[�V�������J�n���Ă���end_���Ԍo�������ǂ�����Ԃ�
  return ofGetElapsedTimef() - start_ >= end_;
}
