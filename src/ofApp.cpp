#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    fbo.allocate(ofGetWidth(), ofGetHeight());
    fbo.begin();
    ofClear(0,0,0);
    fbo.end();
    
    offsetX = 8;
    hue = 0;
    alpha = 255;
    paused = false;
    
    ofSeedRandom();
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    fbo.readToPixels(pixels);
    image.setFromPixels(pixels);
    image.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(!paused){
        fbo.begin();
//        fbo.draw(offsetX, 0);
//        texture.draw(offsetX, 0);
        image.draw(offsetX, 0);
        
        ofColor col;
        for (int i = 0; i < fbo.getHeight(); i++){
            hue = ofMap(ofRandom(0, ofGetHeight()), 0, ofGetHeight(), 0, 255);
            col.setHsb(hue, 255, 255);
            col.a = alpha;
            ofSetColor(col);
            
            ofDrawCircle(0, i, 8);
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
            fbo.begin();
            ofClear(0);
            fbo.end();
            break;
        case 'p':
            paused = !paused;
            break;
        case 'a':
            alpha = alpha==255 ? 200 : 255;
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