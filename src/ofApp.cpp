#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.load("sunset.jpg");
    fbo.allocate(ofGetWidth(), ofGetHeight());
    fbo.begin();
    ofClear(0,0,0);
    fbo.end();
    
    offsetX = 1;
    hue = 0;
    paused = false;
    
    ofSeedRandom();
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
    //offsetX = ofGetMouseX();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    if(!paused){
        fbo.begin();
        fbo.draw(offsetX, 0);
        
        //    image.draw(-498, ofGetHeight()/2 - 250, 500, 500);
        ofColor col;
        for (int i = 0; i < fbo.getHeight(); i++){
            hue = ofMap(ofRandom(0, ofGetHeight()), 0, ofGetHeight(), 0, 255);
            col.setHsb(hue, 255, 255);
            //            col.a = 200;
            ofSetColor(col);
            
            ofDrawCircle(0, i, 1);
        }
        fbo.end();
    }
    
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 'r':
            offsetX = 0;
            fbo.begin();
            ofClear(0);
            fbo.end();
            break;
        case 'p':
            paused = !paused;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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