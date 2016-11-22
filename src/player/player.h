
#pragma once
#include "ofMain.h"
#include "ofxJoystick.h"
#include "playerState.h"


class Player {
private:
  ofxJoystick joy_;

  int currentHP_;
  int maxHP_;
  
  ofVec2f pos_;
  ofVec2f jumpPow_;
  ofVec2f vel_;
  
  int id_;
  
  // プレイヤーの状態をスタックするdeque
  deque<shared_ptr<PlayerState>> state_;
  
  // 入力に対してプレイヤーの状態を変更させる
  void handleInput();
  
public:
  Player() = default;
  
  // プレイヤーを生成する時に呼ぶ
  // IDは1p 2pを示す 0~1を指定
  void setup(int ID);
  
  void update();
  void draw();
  
  const int getMaxHP() const;
  const int getCurrentHP() const;
  
  const ofVec2f& getPos() const;
  const ofVec2f& getVel() const;
  const ofVec2f& getJumpPow() const;
  
  const int getID() const;
  
  void setPos(const ofVec2f& pos);
  void setVel(const ofVec2f& vel);
  
  // tips. 状態遷移する際に先に状態を追加しておきたい場合使用する
  void addState(const shared_ptr<PlayerState>& state);
};