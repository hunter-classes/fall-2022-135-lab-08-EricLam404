#include <iostream>
#include "imageio.h"

void invert()
{

    std::string input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); 
    
    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            out[row][col] = 255 - img[row][col];
        }
    }
    
    writeImage("taskA.pgm",out, h, w);
}

void invert_half()
{

    std::string input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); 
    
    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if(col > (w/2)){
                out[row][col] = 255 - img[row][col];
            }
            else {
                out[row][col] = img[row][col];
            }
        }
    }
    
    writeImage("taskB.pgm",out, h, w);
}

void box()
{

    std::string input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); 
    
    int out[MAX_H][MAX_W];
    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if(col >= w/4 && col <= w*3/4 && row >= h/4 && row <= h*3/4){
                out[row][col] = 255;
            }
            else{
                out[row][col] = img[row][col];
            }
        }
    }
    
    writeImage("taskC.pgm",out, h, w);
}

void frame()
{

    std::string input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); 
    
    int out[MAX_H][MAX_W];

    int left = w/4;
    int right = w*3/4;
    int top = h/4;
    int bottom = h*3/4;
    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if(row == top && col >= left && col <= right){
                out[row][col] = 255;
            }
            else if(row == bottom && col >= left && col <= right){
                out[row][col] = 255;
            }
            else if(col == left && row >= top && row <= bottom){
                out[row][col] = 255;
            }
            else if(col == right && row >= top && row <= bottom){
                out[row][col] = 255;
            }
            else{
                out[row][col] = img[row][col];
            }
        }
    }
    
    writeImage("taskD.pgm",out, h, w);
}

void scale()
{
    std::string input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); 
    
    int out[MAX_H][MAX_W];

    int x, y;
    for(int row = 0; row < h/2; row++) {
        for(int col = 0; col < w/2; col++) {
            x = row*2;
            y = col*2;
            out[x][y] = img[row][col];
            out[x+1][y] = img[row][col];
            out[x][y+1] = img[row][col];
            out[x+1][y+1] = img[row][col];
        }
    }
    
    writeImage("taskE.pgm", out, h, w);
}

void pixelate()
{
    std::string input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); 
    
    int out[MAX_H][MAX_W];

    int x, y;
    for(int row = 0; row < h/2; row++) {
        for(int col = 0; col < w/2; col++) {
            x = row*2;
            y = col*2;
            int average = (img[x][y] + img[x+1][y] + img[x][y+1] + img[x+1][y+1]) / 4;
            out[x][y] = average;
            out[x+1][y] = average;
            out[x][y+1] = average;
            out[x+1][y+1] = average;
        }
    }
    
    writeImage("taskF.pgm", out, h, w);
}