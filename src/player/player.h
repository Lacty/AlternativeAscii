
#pragma once
#include "ofMain.h"
#include "ofxJoystick.h"
#include "gui.h"
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

  ofxPanel gui_;
  ofxLabel label_;

  ofxIntSlider HP_;
  ofxIntSlider maxHP_;
  
  ofxVec2Slider pos_;
  ofxVec2Slider vel_;
  ofxVec2Slider jumpPow_;
  
  ofxFloatSlider speed_;
  
  ofxToggle showCol_;
  list<Collision> passiveCol_;
  list<Collision> attackCol_;
  
  void setupGui();
  
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
  
  // ダメージを食らう場合この関数を通してダメージを受ける
  // 受けたダメージ量を返す
  int damage(int damage);
  
  
  Player* getOther();
  
  const int getID();
  
  const int getMaxHP();
  const int getHP();
  
  const ofVec2f& getPos();
  const ofVec2f& getVel();
  const ofVec2f& getJumpPow();
  
  const float getSpeed();
  
  list<Collision>& getPassiveCol();
  list<Collision>& getAttackCol();
  
  void setPos(const ofVec2f& pos);
  void setVel(const ofVec2f& vel);
  
  // tips. 状態遷移する際に先に状態を追加しておきたい場合使用する
  void addState(const shared_ptr<PlayerState>& state);
};
