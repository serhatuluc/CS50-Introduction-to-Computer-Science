#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed  + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = temp;

            int temp1 = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = temp1;

            int temp2 = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = temp2;
        }
    }

    return;
}

int get_average_for_blur(int i, int j, int height, int width, RGBTRIPLE image[height][width], char colour)
{
    //From here it loops on copy of image to find the average for every pixel
    int green_sum = 0;
    int blue_sum = 0;
    int red_sum = 0;
    float count = 0;


    //forming 9 pixel using for loop
    for (int k = i - 1; k < i + 2; k++)
    {
        for (int l = j - 1; l < j + 2 ; l++)
        {
            if (k < height && l < width && k > -1 && l > -1)
            {
                green_sum += image[k][l].rgbtGreen;
                blue_sum += image[k][l].rgbtBlue;
                red_sum += image[k][l].rgbtRed;
                count++;
            }
        }
    }

    if (colour == 'g')
    {
        return round(green_sum / count);
    }

    if (colour == 'r')
    {
        return round(red_sum / count);
    }

    if (colour == 'b')
    {
        return round(blue_sum / count);
    }
    return 1;
}







// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Made a copy of image so that it can find the average correct
    RGBTRIPLE new_image[height][width];
    for (int m = 0; m < height; m++)
    {
        for (int n = 0; n < height; n++)
        {
            new_image[m][n] = image[m][n];
        }
    }


    // firs two loop are created to work on every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //replacing averages to original image
            image[i][j].rgbtGreen = get_average_for_blur(i, j, height, width, new_image, 'g');
            image[i][j].rgbtBlue = get_average_for_blur(i, j, height, width, new_image, 'b');
            image[i][j].rgbtRed = get_average_for_blur(i, j, height, width, new_image, 'r');
        }
    }
    return;
}

int get_for_edge(int i, int j, int height, int width, RGBTRIPLE image[height][width], char colour)
{
    //From here it loops on copy of image to find the average for every pixel
    int green_sum_gx = 0;
    int blue_sum_gx = 0;
    int red_sum_gx = 0;

    int green_sum_gy = 0;
    int blue_sum_gy = 0;
    int red_sum_gy = 0;


    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};


    //forming 9 pixel using for loop
    for (int k = i - 1, x = 0; k < i + 2; k++, x++)
    {
        for (int l = j - 1, y = 0; l < j + 2 ; l++, y++)
        {
            if (k < height && l < width && k > -1 && l > -1)
            {
                green_sum_gx += image[k][l].rgbtGreen * gx[x][y];
                blue_sum_gx += image[k][l].rgbtBlue * gx[x][y] ;
                red_sum_gx += image[k][l].rgbtRed *  gx[x][y];

                green_sum_gy += image[k][l].rgbtGreen * gy[x][y];
                blue_sum_gy += image[k][l].rgbtBlue * gy[x][y] ;
                red_sum_gy += image[k][l].rgbtRed *  gy[x][y];
            }
        }
    }

    if (colour == 'g')
    {
        int green_result = round(sqrt(green_sum_gx * green_sum_gx + green_sum_gy * green_sum_gy));
        if (green_result > 255)
        {
            return 255;
        }
        else
        {
            return green_result;
        }
    }

    if (colour == 'r')
    {
        int red_result = round(sqrt(red_sum_gx * red_sum_gx + red_sum_gy * red_sum_gy));
        if (red_result > 255)
        {
            return 255;
        }
        else
        {
            return red_result;
        }
    }

    if (colour == 'b')
    {
        int blue_result = round(sqrt(blue_sum_gx * blue_sum_gx + blue_sum_gy * blue_sum_gy));
        if (blue_result > 255)
        {
            return 255;
        }
        else
        {
            return blue_result;
        }
    }
    return 1;
}





// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Made a copy of image so that it can find the average correct
    RGBTRIPLE new_image[height][width];
    for (int m = 0; m < height; m++)
    {
        for (int n = 0; n < height; n++)
        {
            new_image[m][n] = image[m][n];
        }
    }


    // firs two loop are created to work on every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //replacing averages to original image
            image[i][j].rgbtGreen = get_for_edge(i, j, height, width, new_image, 'g');
            image[i][j].rgbtBlue = get_for_edge(i, j, height, width, new_image, 'b');
            image[i][j].rgbtRed = get_for_edge(i, j, height, width, new_image, 'r');
        }
    }
    return;
}
