
#include "playerState.h"
#include "player.h"


shared_ptr<PlayerState> AttackingState::handleInput(Player& player, ofxJoystick& input) {
  if (finish()) {
    // 注意 攻撃用判定を全部消す
    // 後続する攻撃に対応できないので要修正
    player.getAttackCol().clear();
    
    // 攻撃モーションが終わったら前の状態に戻す
    return PlayerState::finish;
  }
  return nullptr;
}


void AttackingState::update(Player& player, ofxJoystick& input) {}

void AttackingState::entry(Player& player) {
  start_ = ofGetElapsedTimef();
  end_   = 0.1f;
  
  // 注意 攻撃用テストコードなので要修正
  // 一度に発動できる攻撃が一つの場合にのみ有効
  player.getAttackCol().push_back({ofVec2f(30, 0), ofVec2f(20, 10)});
}

bool AttackingState::finish() {
  // 攻撃モーションを開始してからend_時間経ったかどうかを返す
  return ofGetElapsedTimef() - start_ >= end_;
}
