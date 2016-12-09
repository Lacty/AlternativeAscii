
#include "playerState.h"
#include "player.h"


shared_ptr<PlayerState> MovingAttackState::handleInput(Player& player, ofxJoystick& input) {
	if (finish()) {
		player.getAttackCol().clear();
		return PlayerState::finish;
	}
	return nullptr;
}

void MovingAttackState::update(Player& player, ofxJoystick& input) {}

void MovingAttackState::entry(Player& player) {
	if (player.getVel().x < 0) { attackWay_ = 0; }
	else if (player.getVel().x > 0) { attackWay_ = 1; }

	//その場で止まるようにする
	player.setVel(ofVec2f(0, 0));

	start_ = ofGetElapsedTimef();
	end_ = 0.1f;

	player.getAttackCol().push_back({ ofVec2f(attackPos_[attackWay_], 0), attackAria_ });
}

bool MovingAttackState::finish() {
	return ofGetElapsedTimef() - start_ >= end_;
}
