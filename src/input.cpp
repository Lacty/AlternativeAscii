
#include "input.h"


int Input::Left  = 0;
int Input::Right = 0;
int Input::Up    = 0;
int Input::Down  = 0;
int Input::X     = 0;
int Input::Y     = 0;
int Input::A     = 0;
int Input::B     = 0;

void Input::setup(const string& path) {
  ofxJSONElement json;
  json.open(path);
  Left  = json["Left" ].asInt();
  Right = json["Right"].asInt();
  Up    = json["Up"   ].asInt();
  Down  = json["Down" ].asInt();
  X     = json["X"    ].asInt();
  Y     = json["Y"    ].asInt();
  A     = json["A"    ].asInt();
  B     = json["B"    ].asInt();
}
