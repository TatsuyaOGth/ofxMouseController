#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowShape(ofGetScreenWidth() / 3, ofGetScreenHeight() / 3);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    x = ofGetWidth() * 0.5;
    y = 10;
    vx = 0;
    vy = 0;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    vy += 0.3;
    vx *= 0.9;
    x += vx;
    y += vy;
    if (x < 5) {
        x = 10;
        vx *= -1;
        vx *= 0.7;
    }
    if (x > ofGetWidth() - 5) {
        x = ofGetWidth() - 5;
        vx *= -1;
        vx *= 0.7;
    }
    if (y < 5) {
        y = 10;
        vy *= -1;
    }
    if (y > ofGetHeight() - 5) {
        y = ofGetHeight() - 5;
        vy *= -1;
        vy *= 0.7;
    }
    
    // set mouse position
    mouse.setPos(x * 3, y * 3);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    
    ofFill();
    ofSetColor(0);
    ofCircle(x, y, 8);
    
    stringstream s;
    s << "ofxMouseController DEMO" << endl;
    s << "this is the your mouse." << endl;
    s << "perform action" << endl;
    s << "- KEY UP    : jump" << endl;
    s << "- KEY LEFT  : move left" << endl;
    s << "- KEY RIGHT : move right" << endl;
    s << "- KEY 1     : left click" << endl;
    s << "- KEY 2     : right click" << endl;
    s << "- KEY ESC   : exit";
    ofDrawBitmapString(s.str(), 10, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_UP:     vy = -5;    break;
        case OF_KEY_LEFT:   vx -= 5;    break;
        case OF_KEY_RIGHT:  vx += 5;    break;
        case '1': mouse.click();        break;
        case '2': mouse.clickRight();   break;
        //case '3': mouse.buttonDown();   break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        //case '3': mouse.buttonUp();     break;
    }
}

