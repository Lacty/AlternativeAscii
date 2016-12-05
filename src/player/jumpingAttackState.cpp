
#include "playerState.h"
#include "player.h"


const int FLOOR = 0;

shared_ptr<PlayerState> JumpingAttackState::handleInput(Player& player, ofxJoystick& input) {
  // 攻撃モーションが終わるか、ジャンプ状態ではなくなったら終了
  if (finish() || player.getPos().y < FLOOR) {
    // 注意 攻撃用判定を全部消す
    // 後続する攻撃に対応できないので要修正
    player.getAttackCol().clear();

    // 攻撃モーションが終わったら前の状態に戻す
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

  // 注意 攻撃用テストコードなので要修正
  // 一度に発動できる攻撃が一つの場合にのみ有効
  player.getAttackCol().push_back({ ofVec2f(30, 0), ofVec2f(20, 10) });
}

bool JumpingAttackState::finish() {
  // 攻撃モーションを開始してからend_時間経ったかどうかを返す
  return ofGetElapsedTimef() - start_ >= end_;
}
