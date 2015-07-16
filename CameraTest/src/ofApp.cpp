#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //背景色
    ofBackground(0, 0, 0);
    //フレームレート
    ofSetFrameRate(30);
    ofSetWindowTitle("video test");
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    camera.initGrabber(ofGetWidth(), ofGetHeight());
    camera.setDeviceID(0);
    
    nowImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    lastImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    camera.update();
    unsigned char *nowPixels = camera.getPixels();
    unsigned char *lastPixels = lastImage.getPixels();
    
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            int index = (y*width + x) * 3;
            int R = int(nowPixels[index]) - int(lastPixels[index]);
            int G = int(nowPixels[index+1]) - int(lastPixels[index+1]);
            int B = int(nowPixels[index+2]) - int(lastPixels[index+2]);
            if (R*R + G*G + B*B >= 70*70) {
                nowImage.setColor(x, y, ofColor(0, 255, 0));
            } else {
                nowImage.setColor(x, y, ofColor(nowPixels[index], nowPixels[index+1], nowPixels[index+2]));
            }
            lastImage.setColor(x, y, ofColor(nowPixels[index], nowPixels[index+1], nowPixels[index+2]));
        }
    }
    lastImage.update();
    nowImage.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofScale(-1, 1);
    nowImage.draw(-width, 0);
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
