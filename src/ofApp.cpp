#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //jelly.load("jellyfishes.mov");
    //jelly.play();

    cam.setup(imageWidth, imageHeight);
    img.allocate(imageWidth, imageHeight, OF_IMAGE_COLOR);
    videoPixels.allocate(videoWidth, videoHeight, OF_PIXELS_RGB);
}

//--------------------------------------------------------------
void ofApp::update(){
    //jelly.update();
    cam.update();
    if(cam.isFrameNew()){
            videoPixels = cam.getPixels();
            //int slice = videoWidth/2;
            if(mouseX < videoWidth){
                int slice = mouseX;
            }else{
                int slice = videoWidth/2;
            }
            for(int y = 0; y < videoHeight; y ++){
                auto col = videoPixels.getColor(slice, y);
                img.setColor(drawPositionX, y, col);
            }
            drawPositionX --;
            if(drawPositionX < 0){
                drawPositionX = imageWidth - 1;
            }
}

    img.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    //jelly.draw(0,0);
    img.draw(0,0);

    ofPushStyle();
    ofSetColor(255, 0, 0);
    ofDrawLine(slice, 0, slice, videoHeight);
    ofPopStyle();
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
