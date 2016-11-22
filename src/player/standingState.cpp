
#include "playerState.h"
#include "player.h"


shared_ptr<PlayerState> StandingState::handleInput(Player& player, ofxJoystick& input) {
  
  // ジャンプボタンが押されたらジャンプ状態に繊維
  if (input.isPressed(2)) {
    // 移動状態を先に追加
    player.addState(make_shared<MovingState>());
    return make_shared<JumpingState>();
  }
  
  // 移動ボタンが押されたら移動状態に繊維
  if (input.isPressed(15)) {
    return make_shared<MovingState>();
  }
  else
  if (input.isPressed(13)) {
    return make_shared<MovingState>();
  }
  
  return nullptr;
}

void StandingState::update(Player& player, ofxJoystick& input) {}

void StandingState::entry(Player& player) {}