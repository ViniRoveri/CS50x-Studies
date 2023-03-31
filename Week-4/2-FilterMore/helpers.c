#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            RGBTRIPLE pixel = image[i][j];

            const float averageBrightness = (pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0;

            image[i][j].rgbtBlue = round(averageBrightness);
            image[i][j].rgbtGreen = round(averageBrightness);
            image[i][j].rgbtRed = round(averageBrightness);
        }
    }
}

// Reflect image horizontally
void swapPixels(RGBTRIPLE *firstPixel, RGBTRIPLE *secondPixel){
    const RGBTRIPLE copyFirstPixel = *firstPixel;
    *firstPixel = *secondPixel;
    *secondPixel = copyFirstPixel;
}
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width / 2; j++){
            RGBTRIPLE *pixel = &image[i][j];
            RGBTRIPLE *pixelToSwap = &image[i][width - 1 - j];

            swapPixels(pixel, pixelToSwap);
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int numberPixelsToConsider = 9;
            RGBTRIPLE pixelsToConsider[numberPixelsToConsider];

            int consideredPixels = 0;
            for(int k = -1; k <= 1; k++){
                for(int l = -1; l <= 1; l++){
                    const int heightPixel = i + k;
                    const int widthPixel = j + l;

                    const bool pixelIsLegal =
                    heightPixel >= 0 &&
                    heightPixel < height &&
                    widthPixel >= 0 &&
                    widthPixel < width;

                    if(pixelIsLegal){
                        pixelsToConsider[consideredPixels] = image[heightPixel][widthPixel];
                        consideredPixels++;
                    }
                }
            }


            int redsToConsider[consideredPixels];
            int greensToConsider[consideredPixels];
            int bluesToConsider[consideredPixels];
            for(int k = 0; k < consideredPixels; k++){
                const RGBTRIPLE pixelToConsider = pixelsToConsider[k];

                redsToConsider[k] = pixelToConsider.rgbtRed;
                greensToConsider[k] = pixelToConsider.rgbtGreen;
                bluesToConsider[k] = pixelToConsider.rgbtBlue;
            }

            float totalRed = 0;
            float totalGreen = 0;
            float totalBlue = 0;
            for(int k = 0; k < consideredPixels; k++){
                totalRed += redsToConsider[k];
                totalBlue += bluesToConsider[k];
                totalGreen += greensToConsider[k];
            }

            const float averageRed = totalRed / consideredPixels;
            const float averageGreen = totalGreen / consideredPixels;
            const float averageBlue = totalBlue / consideredPixels;

            newImage[i][j].rgbtRed = round(averageRed);
            newImage[i][j].rgbtGreen = round(averageGreen);
            newImage[i][j].rgbtBlue = round(averageBlue);
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j] = newImage[i][j];
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gxWeigths[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int gyWeigths[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    RGBTRIPLE newImage[height][width];

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int numberPixelsToConsider = 9;
            RGBTRIPLE pixelsToConsider[numberPixelsToConsider];

            int consideredPixels = 0;
            for(int k = -1; k <= 1; k++){
                for(int l = -1; l <= 1; l++){
                    const int heightPixel = i + k;
                    const int widthPixel = j + l;

                    const bool pixelIsLegal =
                    heightPixel >= 0 &&
                    heightPixel < height &&
                    widthPixel >= 0 &&
                    widthPixel < width;

                    if(pixelIsLegal){
                        pixelsToConsider[consideredPixels] = image[heightPixel][widthPixel];
                    }else{
                        pixelsToConsider[consideredPixels].rgbtRed = 0;
                        pixelsToConsider[consideredPixels].rgbtGreen = 0;
                        pixelsToConsider[consideredPixels].rgbtBlue = 0;
                    }

                    consideredPixels++;
                }
            }

            int redsToConsider[consideredPixels];
            int greensToConsider[consideredPixels];
            int bluesToConsider[consideredPixels];
            for(int k = 0; k < consideredPixels; k++){
                const RGBTRIPLE pixelToConsider = pixelsToConsider[k];

                redsToConsider[k] = pixelToConsider.rgbtRed;
                greensToConsider[k] = pixelToConsider.rgbtGreen;
                bluesToConsider[k] = pixelToConsider.rgbtBlue;
            }

            float gxRed = 0;
            float gxGreen = 0;
            float gxBlue = 0;
            float gyRed = 0;
            float gyGreen = 0;
            float gyBlue = 0;
            for(int k = 0; k < consideredPixels; k++){
                gxRed += redsToConsider[k] * gxWeigths[k];
                gxBlue += bluesToConsider[k] * gxWeigths[k];
                gxGreen += greensToConsider[k] * gxWeigths[k];

                gyRed += redsToConsider[k] * gyWeigths[k];
                gyBlue += bluesToConsider[k] * gyWeigths[k];
                gyGreen += greensToConsider[k] * gyWeigths[k];
            }

            float finalRed = sqrt(pow(gxRed, 2) + pow(gyRed, 2));
            float finalGreen = sqrt(pow(gxGreen, 2) + pow(gyGreen, 2));
            float finalBlue = sqrt(pow(gxBlue, 2) + pow(gyBlue, 2));
            if(finalRed > 255){
                finalRed = 255;
            }
            if(finalGreen > 255){
                finalGreen = 255;
            }
            if(finalBlue > 255){
                finalBlue = 255;
            }

            newImage[i][j].rgbtRed = round(finalRed);
            newImage[i][j].rgbtGreen = round(finalGreen);
            newImage[i][j].rgbtBlue = round(finalBlue);
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j] = newImage[i][j];
        }
    }
}
