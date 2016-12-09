
#include "playerState.h"
#include "player.h"


shared_ptr<PlayerState> JumpingState::handleInput(Player& player, ofxJoystick& input) {
  // ジャンプ状態で攻撃ボタンが押されたら、ジャンプ攻撃状態に遷移
  if (input.isPressed(Input::X) && !player.getJumpingAttack()) {
    player.setJumpingAttack(true);
    return make_shared<JumpingAttackState>();
  }

  if (player.onFloor()) {
    // 着地していたら前の状態に繊維させる
    ofVec2f newLocation = player.getPos();
    newLocation.y = 0;  // ステージの数値を決めるまでの仮の値
    player.setPos(newLocation);

    ofVec2f newVel = player.getVel();
    newVel.y = 0;
    player.setVel(newVel);
    isJumping_ = false;
    player.setJumpingAttack(false);

    return PlayerState::finish;
  }

  return nullptr;
}

void JumpingState::update(Player& player, ofxJoystick& input) {
  // ジャンプ中でも移動状態を更新する
  MovingState::update(player, input);

  // 暫定 ベクトルを使用したジャンプの処理
  ofVec2f newVel = player.getVel();
  newVel.y -= 0.8;

  player.setVel(newVel);
}

void JumpingState::entry(Player& player) {
  if (!isJumping_) {
    ofVec2f newVel = player.getVel() + player.getJumpPow();
    player.setVel(newVel);
  }
  isJumping_ = true;
}
