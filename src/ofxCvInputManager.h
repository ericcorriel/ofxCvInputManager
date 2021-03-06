/*
 * ofxCvInputManager.h
 *
 *  Created on: Jun 20, 2012
 *      Author: spta32
 *      TODO inputs with different size
 */

#ifndef OFXCVINPUTMANAGER_H_
#define OFXCVINPUTMANAGER_H_

#include "ofxCvVideoInput.h"

class ofxCvInputManager {
public:
	ofxCvInputManager();
	virtual ~ofxCvInputManager();

	void setup(float w, float h);

	void addInputSource(ofxCvInputSource * source){
		inputs.push_back(source);
	}

//	//get color image to work with
//	ofxCvColorImage * getInputImage();
	unsigned char * getPixels(){
		return inputs[inputIdx]->getPixels();
	}

	//update manager -> eg. play current input player
	bool update();

	void draw(float x = 0,float y = 0);
	void drawExtraData(float x = 0, float y = 0);

	void setPaused(bool paused);

	void debugStop(){
		if(bStopable)
			setPaused(true);

	}

	void togglePaused(){
		bPlay = !bPlay;
		setPaused(!bPlay);
	}

	bool isNewFrame(){
		return inputs[inputIdx]->isNewFrame();
	}

	void nextFrame();
	void previousFrame();

	virtual void keyPressed(ofKeyEventArgs & e);
	virtual void keyReleased(ofKeyEventArgs & e){}

protected:
	float width, height;

	bool bPlay, bNewFrame, bChangeSettings;
	bool eNextFrame;
	bool ePrevFrame;
	bool eFirstFrame;

	bool bStopable;

	int inputIdx;
	vector<ofxCvInputSource *> inputs;
};

#endif /* OFXCVINPUTMANAGER_H_ */
