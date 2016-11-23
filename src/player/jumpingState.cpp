
#include "playerState.h"
#include "player.h"


// 注意 ステージのパラーメータは別でちゃんと用意すること
const int FLOOR = 0;

shared_ptr<PlayerState> JumpingState::handleInput(Player& player, ofxJoystick& input) {
  if (player.getPos().y < FLOOR) {
    // 着地していたら前の状態に繊維させる
    ofVec2f newLocation = player.getPos();
    newLocation.y = FLOOR;
    player.setPos(newLocation);
    
    ofVec2f newVel = player.getVel();
    newVel.y = 0;
    player.setVel(newVel);
    
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
  ofVec2f newVel = player.getVel() + player.getJumpPow();
  player.setVel(newVel);
}
