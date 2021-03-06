#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    ofSetColor(0);
    
    stringstream s;
    s << "ofxMouseController DEMO" << endl;
    s << "push direction keys." << endl;
    s << "perform action" << endl;
    s << "- KEY UP    : " << endl;
    s << "- KEY LEFT  : move left" << endl;
    s << "- KEY RIGHT : move right" << endl;
    s << "- KEY 1     : left click" << endl;
    s << "- KEY 2     : right click" << endl;
    s << "- KEY 3     : dragg";
    ofDrawBitmapString(s.str(), 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    float x = ofxMouseController::getMousePosX();
    float y = ofxMouseController::getMousePosY();
    
    switch (key) {
        case OF_KEY_UP:     ofxMouseController::setPos(x, y - 5);    break;
        case OF_KEY_DOWN:   ofxMouseController::setPos(x, y + 5);    break;
        case OF_KEY_LEFT:   ofxMouseController::setPos(x - 5, y);    break;
        case OF_KEY_RIGHT:  ofxMouseController::setPos(x + 5, y);    break;
        case '1': ofxMouseController::click();        break;
        case '2': ofxMouseController::clickRight();   break;
        case '3': ofxMouseController::buttonDown();   break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case '3': ofxMouseController::buttonUp();     break;
    }
}

