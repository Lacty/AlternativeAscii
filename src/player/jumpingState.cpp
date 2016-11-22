
#include "playerState.h"
#include "player.h"


// ���� �X�e�[�W�̃p���[���[�^�͕ʂł����Ɨp�ӂ��邱��
const int FLOOR = 0;

shared_ptr<PlayerState> JumpingState::handleInput(Player& player, ofxJoystick& input) {
  if (player.getPos().y <= FLOOR) {
    // ���n���Ă�����O�̏�Ԃɑ@�ۂ�����
    return PlayerState::finish;
  }
  
  return nullptr;
}

void JumpingState::update(Player& player, ofxJoystick& input) {
  // �W�����v���ł��ړ���Ԃ��X�V����
  MovingState::update(player, input);
  
  // �b�� �x�N�g�����g�p�����W�����v�̏���
  ofVec2f newVel = player.getVel();
  
  newVel.y -= 0.8;
  ofVec2f newLocation = player.getPos() + newVel;
  if (newLocation.y <= FLOOR) {
    newLocation.y = FLOOR;
    newVel.y -= newVel.y;
  }
  player.setPos(newLocation);
  player.setVel(newVel);
}

void JumpingState::entry(Player& player) {
  ofVec2f newVel = player.getVel() + player.getJumpPow();
  player.setVel(newVel);
}