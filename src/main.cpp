
#include "ofMain.h"
#include "ofApp.h"
#include "ofxXmlSettings.h"


int main( ){
  ofxXmlSettings xml;
  xml.loadFile("user.xml");
  xml.pushTag("Window");
  
  int  w      = xml.getValue("Width", 1024);
  int  h      = xml.getValue("Height", 768);
  bool fullSc = xml.getValue("FullScreen", 0);
  int  fps    = xml.getValue("FrameRate", 60);
  
	ofSetupOpenGL(w, h, fullSc ? OF_FULLSCREEN : OF_WINDOW);
  ofSetFrameRate(fps);
  
	ofRunApp(new ofApp());
}
