
#include "stage.h"


float Stage::Right  = 0;
float Stage::Left   = 0;
float Stage::Bottom = 0;
float Stage::Top    = 0;

void Stage::setup(const string &path) {
  ofxJSON json;
  
  // jsonを読み込めなかったらエラー
  assert(json.open(path));
  
  Right  = json["Right"].asFloat();
  Left   = json["Left"].asFloat();
  Bottom = json["Botton"].asFloat();
  Top    = json["Top"].asFloat();
}
