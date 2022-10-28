#include <iostream>
#include "imageio.h"
#include "box.h"

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

int main(){
    box();
}