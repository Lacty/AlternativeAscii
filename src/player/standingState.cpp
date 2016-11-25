
#include "playerState.h"
#include "player.h"


shared_ptr<PlayerState> StandingState::handleInput(Player& player, ofxJoystick& input) {
  
  // ジャンプボタンが押されたらジャンプ状態に繊維
  if (input.isPressed(Input::A)) {
    // 移動状態を先に追加
    player.addState(make_shared<MovingState>());
    return make_shared<JumpingState>();
  }
  
  // 移動ボタンが押されたら移動状態に繊維
  if (input.isPressed(Input::Left)) {
    return make_shared<MovingState>();
  }
  else
  if (input.isPressed(Input::Right)) {
    return make_shared<MovingState>();
  }
  
  // 攻撃
  if (input.isPressed(Input::X)) {
    return make_shared<AttackingState>();
  }
  
  return nullptr;
}

void StandingState::update(Player& player, ofxJoystick& input) {
  ofVec2f newVel = player.getVel();
  
  // 加速度が一定以下になったら加速度を0にする
  if (newVel.x <= 0.1 && newVel.x >= -0.1) {
    newVel.x = 0;
  }

  // 加速度を減速させる
  player.setVel(newVel * 0.8f);
}

void StandingState::entry(Player& player) {}
