//
//  ofxWaveformMonitor.cpp
//  WaveformMonitor
//
//  Created by Enrico Becker on 26.05.15.
//
//

#include "ofxWaveformMonitor.h"

ofxWaveformMonitor::ofxWaveformMonitor()
{
    inputWidth = 1280;
    inputHeight = 720;
    monitor.allocate(inputWidth, inputHeight, OF_IMAGE_COLOR);
    grid.allocate(inputWidth, inputHeight,GL_RGBA);
    resolution = 10;
    createGrid();
}

ofxWaveformMonitor::~ofxWaveformMonitor()
{
}

void ofxWaveformMonitor::init(int w,int h, int quality)
{
    inputWidth = w;
    inputHeight = h;
    resolution = quality;
    monitor.allocate(inputWidth, inputHeight, OF_IMAGE_COLOR);
    grid.allocate(inputWidth, inputHeight,GL_RGBA);
    createGrid();
}

void ofxWaveformMonitor::calculate(ofPixels &p)
{
    monitor.setColor(ofColor::black);
    for (int i = 0; i < inputWidth * inputHeight; i += resolution)
    {
        int bright = (p.getColor(i % inputWidth, i / inputWidth).getBrightness() / 256) * inputHeight;
        monitor.setColor(i % inputWidth, bright, ofColor(75,255,75));
    }
    monitor.update();
}

void ofxWaveformMonitor::draw()
{
    ofSetColor(255,255,255);
    monitor.draw(0, inputHeight, inputWidth,-inputHeight);
    grid.draw(0, 0);
}

void ofxWaveformMonitor::createGrid()
{
    grid.begin();
    ofClear(0, 0, 0,0);
    float offsetY = inputHeight / 10.0;
    ofSetColor(255,0,0);
    for (int i = 0; i < 11; i++)
    {
        ofLine(0, i * offsetY, inputWidth, i * offsetY);
        ofDrawBitmapString(ofToString(i * 10), 0, i * offsetY);
    }
    grid.end();
}