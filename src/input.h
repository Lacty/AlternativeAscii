
#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"


class Input {
public:
  static int Left;
  static int Right;
  static int Up;
  static int Down;
  static int X;
  static int Y;
  static int A;
  static int B;
  
  static void setup(const string& path);
};