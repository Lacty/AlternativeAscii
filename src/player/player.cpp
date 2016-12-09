
#include "player.h"


// 暫定 ペラーメータなどは適当なので後で修正すること
void Player::setup(int ID) {
  // パラメータの初期化
  id_ = ID;
  joy_.setup(id_);
  maxHP_ = 100;
  HP_ = maxHP_;
  jumpPow_.set(0, 10);
  speed_ = 100.0f;
  isJumpingAttack_ = false;

  // 当たり判定用判定を作成
  ofVec2f size(50, 50);
  passiveCol_.push_back({ofVec2f::zero(), size});
  
  // 基底の立ち状態を追加
  state_.push_back(make_shared<StandingState>());
}

void Player::setOther(Player* other) {
  other_ = other;
  
  // 対戦相手が登録されませんでした
  assert(other_ != nullptr);
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
  pos_ += vel_;
}

void Player::update() {
  // 入力に対して状態を変化させる
  handleInput();

  // 現在の状態を更新する
  state_.back()->update(*this, joy_);
  
  move();
}

void Player::draw() {
  state_.back()->draw(*this);
}

void Player::drawCollision() {
  if (!showCol_) { return; }
  
  ofNoFill();
  for (const auto& col : passiveCol_) {
    ofSetColor(60, 240, 60);
    ofVec2f pos = pos_ + col.offset_ - (col.size_ / 2);
    ofDrawRectangle(ofRectangle(pos, pos + col.size_));
  }
  for (const auto& col : attackCol_) {
    ofSetColor(240, 60, 60);
    ofVec2f pos = pos_ + col.offset_ - (col.size_ / 2);
    ofDrawRectangle(ofRectangle(pos, pos + col.size_));
  }
  ofFill();
}

void Player::drawParam() {
  string title = "Player :" + ofToString(id_);
  ImGui::Begin(title.c_str());
  
  ImGui::SliderInt("HP", &HP_, 0, maxHP_);
  ImGui::DragInt("Max HP", &maxHP_);
  
  ImGui::DragFloat2("Position", pos_.getPtr());
  ImGui::DragFloat2("Velocity", vel_.getPtr());
  ImGui::DragFloat2("Jump Power", jumpPow_.getPtr());
  
  ImGui::DragFloat("Speed", &speed_);
  ImGui::Checkbox("Show Collision", &showCol_);
  
  ImGui::End();
}

int Player::damage(int damage) {
  HP_ = HP_ - damage;
  if (HP_ < 0) { HP_ = 0; }
  return damage;
}


Player* Player::getOther() {
  // other_(対戦相手)がぬるぽです
  // setOtherを使って対戦相手を設定してください
  assert(other_ != nullptr);
  return other_;
}

const int Player::getID() const { return id_; }

const int Player::getMaxHP() const { return maxHP_; }
const int Player::getHP()    const { return HP_;    }

const ofVec2f& Player::getPos() const { return pos_; }
const ofVec2f& Player::getVel() const { return vel_; }
const ofVec2f& Player::getJumpPow() const { return jumpPow_; }

const float Player::getSpeed() const { return speed_; }

list<Collision>& Player::getPassiveCol() { return passiveCol_; }
list<Collision>& Player::getAttackCol()  { return attackCol_;  }

void Player::setPos(const ofVec2f& pos) { pos_ = pos; }
void Player::setVel(const ofVec2f& vel) { vel_ = vel; }

void Player::addState(const shared_ptr<PlayerState>& state) {
  state_.push_back(state);
}

bool Player::onFloor() {
  if (getPos().y < Stage::Bottom) { return true; }
  else { return false; }
}
