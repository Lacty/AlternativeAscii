
#include "playerState.h"
#include "player.h"


shared_ptr<PlayerState> PassiveState::handleInput(Player& player, ofxJoystick& input) {}

void PassiveState::update(Player& player, ofxJoystick& input) {
  Player* other = player.getOther();
  
  for (auto& o_col : other->getAttackCol()) {
    for (auto& p_col : player.getPassiveCol()) {
      ofRectangle atk;
      ofRectangle pas;
      {
        ofVec2f pos = ofVec2f(other->getPos()) + o_col.offset_ - (o_col.size_ / 2);
        atk = ofRectangle(pos, pos + o_col.size_);
      }
      {
        ofVec2f pos = ofVec2f(player.getPos()) + p_col.offset_ - (p_col.size_ / 2);
        pas = ofRectangle(pos, pos + p_col.size_);
      }
      
      // 攻撃が当たっていたら
      if (atk.intersects(pas)) {
        // 暫定
        // 受けた攻撃の威力によってダメージを決める
        
        player.damage(10);
      }
    }
  }
}
void PassiveState::entry(Player& player) {}
