
#include "ofMain.h"
#include "ofApp.h"
#include "ofxJSONElement.h"

#include "input.h"


int main( ){
  ofxJSON json;
  json.open("user.json");
  
  // jsonからウィンドウの初期値を読み込む
  int w = json["Window"]["width"].asInt();
  int h = json["Window"]["height"].asInt();
  bool f = json["Window"]["fullScreen"].asBool();
  int fps = json["Window"]["frameLimit"].asInt();
  
  // 設定されたボタン番号を読み込む
  string path = json["Input"]["path"].asString();
  Input::setup(path);
  
  // 読み込んだ初期値からウィンドウを作成
  ofSetupOpenGL(w, h, f ? OF_FULLSCREEN : OF_WINDOW);
  ofSetFrameRate(fps);
  
  ofRunApp(new ofApp());
}
