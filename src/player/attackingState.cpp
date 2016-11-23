
#include "playerState.h"
#include "player.h"


shared_ptr<PlayerState> AttackingState::handleInput(Player& player, ofxJoystick& input) {
  return nullptr;
}


void AttackingState::update(Player& player, ofxJoystick& input) {}

void AttackingState::entry(Player& player) {}
