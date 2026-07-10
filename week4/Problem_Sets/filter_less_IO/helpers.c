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

int filterSepia(int sepiaColor)
{
    if (sepiaColor > 255)
        sepiaColor = 255;
    return sepiaColor;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed +
                .769 * image[i][j].rgbtGreen +
                .189 * image[i][j].rgbtBlue);

            int sepiaGreen = round(.349 * image[i][j].rgbtRed +
                .686 * image[i][j].rgbtGreen +
                .168 * image[i][j].rgbtBlue);

            int sepiaBlue = round(.272 * image[i][j].rgbtRed +
                .534 * image[i][j].rgbtGreen +
                .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = filterSepia(sepiaRed);
            image[i][j].rgbtGreen = filterSepia(sepiaGreen);
            image[i][j].rgbtBlue = filterSepia(sepiaBlue);
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
