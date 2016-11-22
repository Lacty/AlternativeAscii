
#include "playerState.h"
#include "player.h"


// 注意 ステージのパラーメータは別でちゃんと用意すること
const int FLOOR = 0;

shared_ptr<PlayerState> JumpingState::handleInput(Player& player, ofxJoystick& input) {
  if (player.getPos().y <= FLOOR) {
    // 着地していたら前の状態に繊維させる
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