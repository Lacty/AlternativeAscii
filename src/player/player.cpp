
#include "player.h"


// 暫定 ペラーメータなどは適当なので後で修正すること
void Player::setup(int ID) {
  // パラメータの初期化
  id_ = ID;
  joy_.setup(id_);
  maxHP_ = 100;
  HP_ = maxHP_;
  jumpPow_ = ofVec2f(0, 10);
  speed_ = 100.0f;
  
  setupGui();
  
  // 基底の立ち状態を追加
  state_.push_back(make_shared<StandingState>());
}

void Player::setupGui() {
  gui_.setup();
  
  // guiへパラメータを追加
  gui_.add(label_.setup("Player :", ofToString(id_)));
  gui_.add(HP_.setup("HP", HP_, 0, maxHP_));
  gui_.add(maxHP_.setup("MaxHP", maxHP_, 0, 1000));
  gui_.add(pos_.setup("Position", pos_, ofVec2f(-1000, -1000), ofVec2f(1000, 1000)));
  gui_.add(vel_.setup("Velocity", vel_, ofVec2f(-100, -100), ofVec2f(100, 100)));
  gui_.add(jumpPow_.setup("JumpPower", jumpPow_, ofVec2f(0, 0), ofVec2f(0, 100)));
  
  // GUIへ登録
  GUI::get()->add("Player" + ofToString(id_), gui_);
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

void Player::move() {
  // 加速度分移動させる
  pos_ = ofVec2f(pos_) + ofVec2f(vel_);
}

void Player::update() {
  // 入力に対して状態を変化させる
  handleInput();

  // 現在の状態を更新する
  state_.back()->update(*this, joy_);
  
  move();
}

void Player::draw() {
  // 暫定
  ofDrawBox(static_cast<ofPoint>(pos_), 50);
  
  // 状態にに合わせて描画を更新させるなら変更する
  // state_.back()->draw();
}

const int Player::getID() { return id_; }

const int Player::getMaxHP() { return maxHP_; }
const int Player::getHP()    { return HP_;    }

const ofVec2f& Player::getPos() { return pos_; }
const ofVec2f& Player::getVel() { return vel_; }
const ofVec2f& Player::getJumpPow() { return jumpPow_; }

const float Player::getSpeed() { return speed_; }

void Player::setPos(const ofVec2f& pos) { pos_ = pos; }
void Player::setVel(const ofVec2f& vel) { vel_ = vel; }

void Player::addState(const shared_ptr<PlayerState>& state) {
  state_.push_back(state);
}
