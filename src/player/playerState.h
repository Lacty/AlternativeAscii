
#pragma once
#include "ofxJoystick.h"
#include "input.h"


class Player;

class PlayerState {
public:
  virtual ~PlayerState() {};
  
  virtual shared_ptr<PlayerState> handleInput(Player& player, ofxJoystick& input) { return nullptr; }
  
  virtual void update(Player& player, ofxJoystick& input) {};
  virtual void entry(Player& player) {};
  
  static shared_ptr<PlayerState> finish;
};

// 攻撃を受けることが可能な状態
class PassiveState : public PlayerState {
public:
  shared_ptr<PlayerState> handleInput(Player& player, ofxJoystick& input) override;
  void update(Player& player, ofxJoystick& input) override;
  void entry(Player& player) override;
};

class StandingState : public PassiveState {
public:
  shared_ptr<PlayerState> handleInput(Player& player, ofxJoystick& input) override;
  void update(Player& player, ofxJoystick& input) override;
  void entry(Player& player) override;
};

class MovingState : public PassiveState {
public:
  shared_ptr<PlayerState> handleInput(Player& player, ofxJoystick& input) override;
  void update(Player& player, ofxJoystick& input) override;
  void entry(Player& player) override;
};

class JumpingState : public MovingState {
protected:
  bool isJumping_;  // ジャンプ状態の判定
public:
  shared_ptr<PlayerState> handleInput(Player& player, ofxJoystick& input) override;
  void update(Player& player, ofxJoystick& input) override;
  void entry(Player& player) override;
};

class AttackingState : public PlayerState {
private:
  float start_;
  float end_;
  
  bool finish();

public:
  shared_ptr<PlayerState> handleInput(Player& player, ofxJoystick& input) override;
  void update(Player& player, ofxJoystick& input) override;
  void entry(Player& player) override;
};

class JumpingAttackState : public JumpingState {
private:
  float start_;
  float end_;
  
  bool finish();
  
public:
  shared_ptr<PlayerState> handleInput(Player& player, ofxJoystick& input) override;
  void update(Player& player, ofxJoystick& input) override;
  void entry(Player& player) override;
};

class MovingAttackState :public MovingState {
private:
	float start_;
	float end_;

	bool finish();

public:
	shared_ptr<PlayerState> handleInput(Player& player, ofxJoystick& input) override;
	void update(Player& player, ofxJoystick& input) override;
	void entry(Player& player) override;
};
