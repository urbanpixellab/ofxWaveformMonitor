#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grabber.initGrabber(1280,720);
    waveform.init(1280,720,10);
    waveform.calculate(grabber.getPixelsRef());
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    waveform.calculate(grabber.getPixelsRef());
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    waveform.draw();
    ofSetColor(255,255,255);
    grabber.draw(0,0,160,90);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 170, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
