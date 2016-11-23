
#include "player.h"


// 暫定 ペラーメータなどは適当なので後で修正すること
void Player::setup(int ID) {
  id_ = ID;
  joy_.setup(id_);
  maxHP_ = 100;
  currentHP_ = maxHP_;
  jumpPow_.set(0, 10);
  state_.push_back(make_shared<StandingState>());
}

void Player::handleInput() {
  shared_ptr<PlayerState> state = state_.back()->handleInput(*this, joy_);
  if (state) {
    if (state == PlayerState::finish) {
      // エラー : 前の状態が存在しない
      assert(state_.at(1) != nullptr);
      
      // 前の状態に戻す
      state_.pop_back();
    } else {
    
      // 状態を遷移させる
      state_.push_back(state);
    }
    
    state_.back()->entry(*this);
  }
}

void Player::update() {
  // 入力に対して状態を変化させる
  handleInput();
  
  // 現在の状態を更新する
  state_.back()->update(*this, joy_);
}

void Player::draw() {
  // 暫定
  ofDrawBox(pos_, 50);
  
  // 状態にに合わせて描画を更新させるなら変更する
  // state_.back()->draw();
}

const int Player::getMaxHP()     const { return maxHP_;     }
const int Player::getCurrentHP() const { return currentHP_; }

const ofVec2f& Player::getPos() const { return pos_; }
const ofVec2f& Player::getVel() const { return vel_; }
const ofVec2f& Player::getJumpPow() const { return jumpPow_; }

const int Player::getID() const { return id_; }

void Player::setPos(const ofVec2f& pos) { pos_.set(pos); }
void Player::setVel(const ofVec2f& vel) { vel_.set(vel); }

void Player::addState(const shared_ptr<PlayerState>& state) {
  state_.push_back(state);
}