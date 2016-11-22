
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
  ofxXmlSettings xml;
  xml.loadFile(path);
  Left  = xml.getValue("Left",  0);
  Right = xml.getValue("Right", 0);
  Up    = xml.getValue("Up",    0);
  Down  = xml.getValue("Down",  0);
  X     = xml.getValue("X",     0);
  Y     = xml.getValue("Y",     0);
  A     = xml.getValue("A",     0);
  B     = xml.getValue("B",     0);
}