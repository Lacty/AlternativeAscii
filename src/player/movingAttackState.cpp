
#include "playerState.h"
#include "player.h"


shared_ptr<PlayerState> MovingAttackState::handleInput(Player& player, ofxJoystick& input) {
	if (finish()) {
		player.getAttackCol().clear();

		return PlayerState::finish;
	}
	return nullptr;
}


void MovingAttackState::update(Player& player, ofxJoystick& input) {
	MovingState::update(player, input);
}

void MovingAttackState::entry(Player& player) {
	start_ = ofGetElapsedTimef();
	end_ = 0.5f;

	ofLog() << "attack";

	player.getAttackCol().push_back({ ofVec2f(30, 0), ofVec2f(20, 10) });
}

bool MovingAttackState::finish() {
	return ofGetElapsedTimef() - start_ >= end_;
}
