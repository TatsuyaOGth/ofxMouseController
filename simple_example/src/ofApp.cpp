#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowShape(ofGetScreenWidth() / 3, ofGetScreenHeight() / 3);
    
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
    mouseController.setMousePos(x * 3, y * 3);
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
    s << "key" << endl;
    s << "UP    : jump" << endl;
    s << "LEFT  : move left" << endl;
    s << "RIGHT : move right" << endl;
    s << "ESC   : exit";
    ofDrawBitmapString(s.str(), 10, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_UP:     vy = -5; break;
        case OF_KEY_LEFT:   vx -= 5; break;
        case OF_KEY_RIGHT:  vx += 5; break;
        case ' ': mouseController.setMouseButton(OFX_MOUSE_CONTROLLER_BUTTON_RIGHT); break;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
