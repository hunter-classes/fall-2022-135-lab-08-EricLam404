#include <iostream>
#include "imageio.h"
#include "scale.h"

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

int main(){
    pixelate();
}