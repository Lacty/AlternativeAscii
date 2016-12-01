
#include "NavigationBar.h"


void NavigationBar::setup() {
	defaultPos_ = ofVec2f(450, 20);
	barPos_ = ofVec2f(0, 0);
	barSize_ = ofVec2f(1, 8);
	textPos_ = ofVec2f(defaultPos_);
	count_ = 0;
	textSwitch_ = 0;
	moveSwitch_ = 0;

	loadFiles();

	ofAddListener(ofEvents().update, this, &NavigationBar::moveText);
}

void NavigationBar::loadFiles() {
	loadXml();
	loadFont();

	mainBarImage_.load(mainBarFilename_);
	sideBarImage_.load(sideBarFilename_);
}

void NavigationBar::loadXml() {
	xml_.load("settings.xml");
	xml_.pushTag("group");
	int textValue_ = xml_.getNumTags("Navi");
	for (int i = 0; i < textValue_; i++) {
		textList_.push_back(xml_.getValue("Navi", "none", i));
	}
	defaultPos_.x = xml_.getValue("TextStopPosX", 0);
	defaultPos_.y = xml_.getValue("TextStopPosY", 0);
	barPos_.x = xml_.getValue("BarPositionX", 0);
	barPos_.y = xml_.getValue("BarPositionY", 0);
	barSize_.x = xml_.getValue("BarSizeX", 0);
	barSize_.y = xml_.getValue("BarSizeY", 0);
	mainBarFilename_ = xml_.getValue("MainBar", "none");
	sideBarFilename_ = xml_.getValue("SideBar", "none");
	fontSize_ = xml_.getValue("FontSize", 0);
	fontScale_ = xml_.getValue("FontScale", 0);
	fontFilename_ = xml_.getValue("Font", "none");
	waitTime_ = xml_.getValue("TextWaitTime", 0);
	moveValue_ = xml_.getValue("TextMoveValue", 0);
	xml_.popTag();

}

void NavigationBar::loadFont() {
	font_.load(fontFilename_, fontSize_);
}

void NavigationBar::moveText(ofEventArgs &args) {
	switch (moveSwitch_) {
	case 0:
		frameOutTextStart();
		break;

	case 1:
		frameInTextStart();
		break;
	}
}

void NavigationBar::frameOutTextStart() {
	count_ += ofGetLastFrameTime() * 100;
	if (count_ >= waitTime_ * 60) {
		moveTextPos();
		if (textPos_.x <= -ofGetWindowWidth()) {
			frameOutTextEnd();
		}
	}
}

void NavigationBar::frameOutTextEnd() {
	textPos_.x = ofGetWindowWidth();
	count_ = 0;
	moveSwitch_ = 1;
	textSwitch_ += 1;
	if (textSwitch_ >= textList_.size()) { textSwitch_ = 0; }
}

void NavigationBar::frameInTextStart() {
	moveTextPos();
	if (textPos_.x <= ofVec2f(defaultPos_).x) {
		frameInTextEnd();
	}
}

void NavigationBar::frameInTextEnd() {
	textPos_ = ofVec2f(defaultPos_);
	moveSwitch_ = 0;
}

void NavigationBar::moveTextPos() {
	textPos_.x -= float(moveValue_)* (ofGetLastFrameTime() * 100);
}

void NavigationBar::draw() {
	mainBarImage_.draw(ofVec2f(barPos_), ofGetWindowWidth() / ofVec2f(barSize_).x, ofGetWindowHeight() / ofVec2f(barSize_).y);

	drawSwitchText();

	sideBarImage_.draw(ofVec2f(barPos_), ofGetWindowWidth() / ofVec2f(barSize_).x, ofGetWindowHeight() / ofVec2f(barSize_).y);
}

void NavigationBar::drawGUI() {
	ImGui::Begin("NavigationBar");
	if (ImGui::Button("Save")) {
		saveXml();
	}
	if (ImGui::Button("Load")) {
		loadXml();
	}
	ImGui::DragFloat2("TextStopPos", defaultPos_.getPtr());
	ImGui::DragFloat("FontScale", &fontScale_, 1.0f, 500, 1000);
	ImGui::DragInt("TextWaitTime", &waitTime_, 1.0f, 1, 100);
	ImGui::DragFloat("TextMoveValue", &moveValue_, 1.0f, 15, 100);
	ImGui::DragFloat2("BarPosition", barPos_.getPtr());
	ImGui::DragFloat2("BarSize", barSize_.getPtr());
	ImGui::End();
}

void NavigationBar::saveXml() {
	xml_.pushTag("group");
	xml_.setValue("TextStopPosX", defaultPos_.x);
	xml_.setValue("TextStopPosY", defaultPos_.y);
	xml_.setValue("BarPositionX", barPos_.x);
	xml_.setValue("BarPositionY", barPos_.y);
	xml_.setValue("BarSizeX", barSize_.x);
	xml_.setValue("BarSizeY", barSize_.y);
	xml_.setValue("FontScale", fontScale_);
	xml_.setValue("TextWaitTime", waitTime_);
	xml_.setValue("TextMoveValue", moveValue_);
	xml_.popTag();
	xml_.saveFile("settings.xml");
}

void NavigationBar::drawSwitchText() {
	for (textSwitch_; textSwitch_ < textList_.size();) {
		ofSetColor(255, 255, 255);

		drawText(textList_[textSwitch_]);
		break;
	}
}

void NavigationBar::drawText(string& text) {
	ofPushMatrix();

	float fontWidth = font_.stringWidth(text);
	float fontHeight = font_.stringHeight(text);

	ofTranslate(textPos_);
	ofScale((ofGetWindowWidth() / (fontScale_)),
		(ofGetWindowHeight() / fontScale_), 1);
	font_.drawString(text, -fontWidth / 2, fontHeight);

	ofPopMatrix();
}
