
#pragma once
#include "ofMain.h"
#include "ofxJoystick.h"
#include "ofxImGui.h"
#include "playerState.h"


struct Collision {
  ofVec2f offset_;
  ofVec2f size_;
};

class Player {
private:
  Player* other_;

  ofxJoystick joy_;
  
  int id_;
  
  int HP_;
  int maxHP_;
  
  ofVec2f pos_;
  ofVec2f vel_;
  ofVec2f jumpPow_;
  
  float speed_;

  bool isJumpingAttack_;

  bool showCol_;
  list<Collision> passiveCol_;
  list<Collision> attackCol_;
  
  // プレイヤーの状態をスタックするdeque
  deque<shared_ptr<PlayerState>> state_;
  
  // 入力に対してプレイヤーの状態を変更させる
  void handleInput();
  
  void move();
  
public:
  Player() = default;
  
  // プレイヤーを生成する時に呼ぶ
  // IDは1p 2pを示す 0~1を指定
  void setup(int ID);
  void setOther(Player* other);
  
  void update();
  void draw();
  void drawCollision();
  void drawParam();
  
  // ダメージを食らう場合この関数を通してダメージを受ける
  // 受けたダメージ量を返す
  int damage(int damage);
  
  
  Player* getOther();
  
  const int getID() const;
  
  const int getMaxHP() const;
  const int getHP() const;

  const ofVec2f& getPos() const;
  const ofVec2f& getVel() const;
  const ofVec2f& getJumpPow() const;
  
  const float getSpeed() const;
  
  list<Collision>& getPassiveCol();
  list<Collision>& getAttackCol();
  
  void setPos(const ofVec2f& pos);
  void setVel(const ofVec2f& vel);
  
  // tips. 状態遷移する際に先に状態を追加しておきたい場合使用する
  void addState(const shared_ptr<PlayerState>& state);

  bool onFloor(); // ジャンプ判定(着地判定)
  void setJumpingAttack(bool state);
  bool getJumpingAttack();
};

inline void Player::setJumpingAttack(bool state) { isJumpingAttack_ = state; }
inline bool Player::getJumpingAttack() { return isJumpingAttack_; }
