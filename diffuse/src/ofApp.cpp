#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

	sphere.setScale(10);

	box.setPosition(400, 0, 0);
	box.tilt(30);

	light.setPointLight();
	light.setPosition(500, 400, 400);
	light.setDiffuseColor(ofFloatColor(.8f, .4, .2));
	light.setAttenuation(1);

	material.setShininess(0);

	if(!ofIsGLProgrammableRenderer()){
		ofEnableLighting();
		ofSetSmoothLighting(true);
	}else{
		shader.load("diffuse");
	}

	renderFlat = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofEnableDepthTest();

	cam.begin();

	if(ofIsGLProgrammableRenderer()){
		shader.begin();
		shader.setUniform3f("lightPos", light.getPosition().x, light.getPosition().y, light.getPosition().z);
		shader.setUniform3f("lightColor", light.getDiffuseColor().r, light.getDiffuseColor().g, light.getDiffuseColor().b);
		shader.setUniform1i("doFlat", (int)renderFlat);
	}else{
		if(renderFlat)
			glShadeModel(GL_FLAT);
		else
			glShadeModel(GL_SMOOTH);
		light.enable();
		material.begin();
	}

	sphere.draw();
	box.draw();

	if(ofIsGLProgrammableRenderer()){
		shader.end();
	}else{
		material.end();
		light.disable();
	}

	cam.end();

	ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	renderFlat = !renderFlat;
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
