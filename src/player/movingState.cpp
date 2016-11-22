
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
    // 注意 プレイヤーの位置を直接いじるのではなく
    // ベクトルを使用して移動させるのが望ましい
    ofVec2f newLocation = player.getPos();
    newLocation.x -= ofGetLastFrameTime() * 50;
    player.setPos(newLocation);
  }
  else
  if (input.isPushing(Input::Right)) {
    ofVec2f newLocation = player.getPos();
    newLocation.x += ofGetLastFrameTime() * 50;
    player.setPos(newLocation);
  }
}

void MovingState::entry(Player& player) {}