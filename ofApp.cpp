#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofNoFill();
	ofEnableDepthTest();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 2);

	ofColor color;
	for (int len = 300; len <= 300; len += 100) {

		for (int i = 0; i < 6; i++) {

			if (i < 4) {

				ofRotateX(90);
			}
			else if (i < 5) {

				ofRotateY(90);
			}
			else {

				ofRotateY(180);
			}

			for (int k = 0; k < 12; k++) {

				auto location = glm::vec3(ofRandom(-len * 0.5, len * 0.5), ofRandom(-len * 0.5, len * 0.5), len * 0.5);
				auto radius = (int)(ofRandom(200) + ofGetFrameNum() * 3) % 100;

				auto alpha = 255;
				if (radius > 80) {

					alpha = ofMap(radius, 80, 100, 255, 128);
				}

				color.setHsb(ofRandom(255), 200, 255);
				ofSetColor(color, alpha);

				int deg_start = ofRandom(360);
				ofNoFill();
				ofBeginShape();
				for (int deg = deg_start; deg < deg_start + 360; deg += 120) {

					auto point = location + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

					if (point.y > len * 0.5) { point.y = len * 0.5; }
					if (point.y < -len * 0.5) { point.y = -len * 0.5; }
					if (point.x > len * 0.5) { point.x = len * 0.5; }
					if (point.x < -len * 0.5) { point.x = -len * 0.5; }

					ofVertex(point);
				}
				ofEndShape(true);

				alpha = 128;
				if (radius > 80) {

					alpha = ofMap(radius, 80, 100, 128, 0);
				}

				ofFill();
				ofSetColor(color, alpha);
				ofBeginShape();
				for (int deg = deg_start; deg < deg_start + 360; deg += 120) {

					auto point = location + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

					if (point.y > len * 0.5) { point.y = len * 0.5; }
					if (point.y < -len * 0.5) { point.y = -len * 0.5; }
					if (point.x > len * 0.5) { point.x = len * 0.5; }
					if (point.x < -len * 0.5) { point.x = -len * 0.5; }

					ofVertex(point);
				}
				ofEndShape(true);
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}