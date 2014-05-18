#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetVerticalSync(true);

	ofBackground(0);

	sphere.setScale(10);

	box.setPosition(400, 0, 0);

	light.setPointLight();
	light.setPosition(170, 0, 170);
	light.setDiffuseColor(ofFloatColor(.8f, .4, .2));
	light.setAttenuation(1);

	material.setShininess(0);

	if(!ofIsGLProgrammableRenderer()) {
		ofEnableLighting();
		ofSetSmoothLighting(true);
	} else {
		shader.load("diffuse");
	}

	renderFlat = false;
}

//--------------------------------------------------------------
void ofApp::update() {
	light.rotateAround(.5, ofVec3f(0, 1, 0), ofVec3f(0, 0, 0));
}

//--------------------------------------------------------------
void ofApp::draw() {

	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

	ofEnableDepthTest();

	cam.begin();

	if(ofIsGLProgrammableRenderer() && shader.isLoaded()) {
		shader.begin();
		ofVec3f lightPos = light.getPosition() * cam.getModelViewMatrix();
		shader.setUniform3f("lightPos", lightPos.x, lightPos.y, lightPos.z);
		shader.setUniform3f("lightColor", light.getDiffuseColor().r, light.getDiffuseColor().g, light.getDiffuseColor().b);
		shader.setUniform1i("doFlat", (int)renderFlat);
	} else {
		if(renderFlat)
			glShadeModel(GL_FLAT);
		else
			glShadeModel(GL_SMOOTH);
		light.enable();
		material.begin();
	}

	if(ofIsGLProgrammableRenderer() && shader.isLoaded()) {
		//get normal matrix
		/*
		ofMatrix4x4 normMat4 = sphere.getLocalTransformMatrix();
		ofMatrix3x3 normMat(normMat4._mat[0][0], normMat4._mat[0][1], normMat4._mat[0][2],
		                    normMat4._mat[1][0], normMat4._mat[1][1], normMat4._mat[1][2],
		                    normMat4._mat[2][0], normMat4._mat[2][1], normMat4._mat[2][2]);

		normMat.invert();
		normMat.transpose();
		shader.setUniformMatrix3f("normalMatrix", normMat);
		*/
	}

	sphere.draw();
	box.draw();

	if(ofIsGLProgrammableRenderer() && shader.isLoaded()) {
		shader.end();
	} else {
		material.end();
		light.disable();
	}

	ofSetColor(255);
	sphere.drawNormals(10);
	box.drawNormals(10);

	light.draw();

	cam.end();

	ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	renderFlat = !renderFlat;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
