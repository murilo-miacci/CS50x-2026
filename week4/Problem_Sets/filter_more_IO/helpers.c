#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed +
                image[i][j].rgbtBlue +
                image[i][j].rgbtGreen) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            copy[i][j] = image[i][j];
    }

    int directions[9][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 0}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int amount = 0;

            for (int k = 0; k < 9; k++)
            {
                int di = directions[k][0];
                int dj = directions[k][1];

                int ni = i + di;
                int nj = j + dj;

                if (0 <= ni && ni < height &&
                    0 <= nj && nj < width)
                {
                    sumRed += copy[ni][nj].rgbtRed;
                    sumGreen += copy[ni][nj].rgbtGreen;
                    sumBlue += copy[ni][nj].rgbtBlue;
                    amount ++;
                }
            }

            int averageRed = round((float)sumRed/amount);
            int averageGreen = round((float)sumGreen/amount);
            int averageBlue = round((float)sumBlue/amount);

            image[i][j].rgbtRed = averageRed;
            image[i][j].rgbtGreen = averageGreen;
            image[i][j].rgbtBlue = averageBlue;
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            copy[i][j] = image[i][j];
    }

    const int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    const int Gy[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redGx = 0, redGy = 0;
            int greenGx = 0, greenGy = 0;
            int blueGx = 0, blueGy = 0;

            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    int ni = i + k - 1;
                    int nj = j + l - 1;

                    int red = 0, green = 0, blue = 0;
                    
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        red = copy[ni][nj].rgbtRed;
                        green = copy[ni][nj].rgbtGreen;
                        blue = copy[ni][nj].rgbtBlue;
                    }

                    redGx += red * Gx[k][l];
                    redGy += red * Gy[k][l];

                    greenGx += green * Gx[k][l];
                    greenGy += green * Gy[k][l];

                    blueGx += blue * Gx[k][l];
                    blueGy += blue * Gy[k][l];
                }
            }

            int fullred = round(sqrt(redGx * redGx + redGy * redGy));
            if (fullred > 255) fullred = 255;

            int fullgreen = round(sqrt(greenGx * greenGx + greenGy * greenGy));
            if (fullgreen > 255) fullgreen = 255;

            int fullblue = round(sqrt(blueGx * blueGx + blueGy * blueGy));
            if (fullblue > 255) fullblue = 255;

            image[i][j].rgbtRed = fullred;
            image[i][j].rgbtGreen = fullgreen;
            image[i][j].rgbtBlue = fullblue;
        }
    }
}