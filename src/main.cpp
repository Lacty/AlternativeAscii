
#include "ofMain.h"
#include "ofApp.h"
#include "ofxXmlSettings.h"


int main( ){
  ofxXmlSettings xml;
  xml.loadFile("main.xml");
  
  int  w      = xml.getValue("Window:Width",    1024);
  int  h      = xml.getValue("Window:Height",    768);
  bool fullSc = xml.getValue("Window:FullScreen",  0);
  int  fps    = xml.getValue("Window:FrameRate",  60);
  
	ofSetupOpenGL(w, h, fullSc ? OF_FULLSCREEN : OF_WINDOW);
  ofSetFrameRate(fps);
  
	ofRunApp(new ofApp());
}
