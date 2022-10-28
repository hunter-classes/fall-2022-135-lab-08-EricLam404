#include <iostream>
#include "imageio.h"
#include "frame.h"

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

int main(){
    frame();
}