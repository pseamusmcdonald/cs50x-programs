#include "helpers.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int h = 0; h < width; h++) {
            int avColor = round((image[i][h].rgbtBlue+image[i][h].rgbtGreen+image[i][h].rgbtRed) / 3);
            image[i][h].rgbtBlue = image[i][h].rgbtGreen = image[i][h].rgbtRed = avColor;
        }
    }
    return;
}


void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempPIX[1][1];
    for (int i = 0; i < height; i++) {
        int widthTemp = width;
        for (int h = 0; h < width/2; h++) {
            if (h != widthTemp) {
                tempPIX[0][0] = image[i][h];
                image[i][h] = image[i][widthTemp];
                image[i][widthTemp] = tempPIX[0][0];
            }
            widthTemp--;
        }
    }
    return;
}


void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int h = 0; h < width; h++) {
            int avBlue = 0;
            int avGreen = 0;
            int avRed = 0;
            int pixCount = 0;

            for (int g = -1; g < 2; g++) {
                if (i+g >= 0 && i+g < height) {
                    for (int f = -1; f < 2; f++) {
                        if (h+f >= 0 && h+f < width) {
                            avBlue += image[i+g][h+f].rgbtBlue;
                            avGreen += image[i+g][h+f].rgbtGreen;
                            avRed += image[i+g][h+f].rgbtRed;
                            pixCount++;
                        }
                    }
                }
            }

            avBlue = avBlue / pixCount;
            avGreen = avGreen / pixCount;
            avRed = avRed / pixCount;
            image[i][h].rgbtBlue = avBlue;
            image[i][h].rgbtGreen = avGreen;
            image[i][h].rgbtRed = avRed;
        }
    }
    return;
}


void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int a = 0; a < height; a++) {
        for (int b = 0; b < width; b++) {
            temp[a][b] = image[a][b];
        }
    }

    // Filter Kernel Keys

    int kernKeyX[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int kernKeyY[3][3] = {
        { -1, -2, -1 },
        { 0, 0, 0 },
        { 1, 2, 1 }
    };

    // Take each pixel, gather surrounding pixels,

    for (int i = 0; i < height; i++) {
        for (int h = 0; h < width; h++) {
            int xBlue = 0;
            int xGreen = 0;
            int xRed = 0;
            int yBlue = 0;
            int yGreen = 0;
            int yRed = 0;

            for (int g = -1; g < 2; g++) {
                if (i+g >= 0 && i+g < height) {
                    for (int f = -1; f < 2; f++) {
                        if (h+f >= 0 && h+f < width) {
                            xBlue += kernKeyX[g+1][f+1]*temp[i+g][h+f].rgbtBlue;
                            xGreen += kernKeyX[g+1][f+1]*temp[i+g][h+f].rgbtGreen;
                            xRed += kernKeyX[g+1][f+1]*temp[i+g][h+f].rgbtRed;
                            yBlue += kernKeyY[g+1][f+1]*temp[i+g][h+f].rgbtBlue;
                            yGreen += kernKeyY[g+1][f+1]*temp[i+g][h+f].rgbtGreen;
                            yRed += kernKeyY[g+1][f+1]*temp[i+g][h+f].rgbtRed;
                        }
                    }
                }
            }

            if ((floor(hypot(xBlue, yBlue))) > 255) image[i][h].rgbtBlue = 255;
            else image[i][h].rgbtBlue = floor(hypot(xBlue, yBlue));
            if ((floor(hypot(xGreen, yGreen))) > 255) image[i][h].rgbtGreen = 255;
            else image[i][h].rgbtGreen = floor(hypot(xGreen, yGreen));
            if ((floor(hypot(xRed, yRed))) > 255) image[i][h].rgbtRed = 255;
            else image[i][h].rgbtRed = floor(hypot(xRed, yRed));
        }
    }
    return;
}
