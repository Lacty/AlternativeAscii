
#include "playerState.h"
#include "player.h"


shared_ptr<PlayerState> MovingState::handleInput(Player& player, ofxJoystick& input) {
  if (!input.isPushing(Input::Left) &&
      !input.isPushing(Input::Right))
  {
    // 移動ボタンが押されてなければ前の状態に繊維
    return PlayerState::finish;
  }
  
  if (input.isPressed(Input::A)) {
    // ジャンプ状態に繊維
    return make_shared<JumpingState>();
  }
  
  return nullptr;
}

void MovingState::update(Player& player, ofxJoystick& input) {
  // 移動ボタンに応じてプレイヤーを移動させる
  if (input.isPushing(Input::Left)) {
    ofVec2f newVel = player.getVel();
    newVel.x = -(player.getSpeed() * ofGetLastFrameTime());
    player.setVel(newVel);
  }
  else
  if (input.isPushing(Input::Right)) {
    ofVec2f newVel = player.getVel();
    newVel.x = player.getSpeed() * ofGetLastFrameTime();
    player.setVel(newVel);
  }
}

void MovingState::entry(Player& player) {}
