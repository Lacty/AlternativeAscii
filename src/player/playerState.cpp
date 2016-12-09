
#include "playerState.h"
#include "player.h"


shared_ptr<PlayerState> PlayerState::finish = make_shared<PlayerState>();

void PlayerState::draw(Player& player) {
  ofSetColor(255, 255, 255);
  ofDrawBox(player.getPos(), 50, 50, 0);
}
