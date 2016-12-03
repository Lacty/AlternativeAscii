
#include "ofMain.h"
#include "ofApp.h"

#include "ofxJSONElement.h"


int main( ){
  ofxJSONElement json;
  json.open("user.json");
  int w = json["window"]["width"].asInt();
  int h = json["window"]["height"].asInt();
  int f = json["window"]["fullScreen"].asInt();
  int fps = json["window"]["frameLimit"].asInt();
  
  ofSetupOpenGL(w, h, f ? OF_FULLSCREEN : OF_WINDOW);
  ofSetFrameRate(fps);
  
  ofRunApp(new ofApp());
}
