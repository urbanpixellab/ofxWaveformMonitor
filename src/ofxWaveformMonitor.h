//
//  ofxWaveformMonitor.h
//  WaveformMonitor
//
//  Created by Enrico Becker on 26.05.15.
//
//

#ifndef __WaveformMonitor__ofxWaveformMonitor__
#define __WaveformMonitor__ofxWaveformMonitor__

#include <stdio.h>
#include "ofxOpenCv.h"
#include "ofMain.h"

class ofxWaveformMonitor{
public:
    ofxWaveformMonitor();
    ~ofxWaveformMonitor();
    void init(int w,int h,int quality);
    void calculate(ofPixels &p);
    void draw();
    void createGrid();
    
private:
    int inputWidth;
    int inputHeight;
    int resolution;
    ofImage monitor;
    ofFbo grid;
};

#endif /* defined(__WaveformMonitor__ofxWaveformMonitor__) */
