#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale
(int height, int width, RGBTRIPLE image[height][width])
{
    //variable declaration
    int h, w;

    //nested loop representing 2D array of height and width of image
    for
    (h = 0; h < height; h = h + 1)
    {

        for
        (w = 0; w < width; w = w + 1)
        {
            //the RGB pixels are equal to the images height and width
            RGBTRIPLE pixel = image[h][w];
            int gray = round((pixel.rgbtRed + pixel.rgbtBlue + pixel.rgbtGreen) / 3.0);//averages the red green and blue pixels to
            image[h][w].rgbtRed = image[h][w].rgbtBlue = image[h][w].rgbtGreen = gray;

        }

    }

}

//sets limits for the pixels so not overflow
int lim
(int max)
{

    if
    (max > 255)
    {

        max = 255;
    }

    return max;

}


// Convert image to sepia
void sepia
(int height, int width, RGBTRIPLE image[height][width])
{
    int h, w;
    
    //nested loop itterates of 2D array of height and width of pixel
    for
    (h = 0; h < height; h = h + 1)
    {

        for
        (w = 0; w < width; w = w + 1)
        {

            //pixel is equal to the image h and w- 2D array
            RGBTRIPLE pixel = image[h][w];
            int originalGreen = pixel.rgbtGreen;//variable declarationg 
            int originalRed = pixel.rgbtRed;
            int originalBlue = pixel.rgbtBlue;
            
            
            //formula rounded and set to limit of 255 for each red, green and blue to change to sepia        
            image[h][w].rgbtBlue = lim(round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue));
            image[h][w].rgbtRed = lim(round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue));
            image[h][w].rgbtGreen = lim(round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue));


        }
    }

    return;
}

//changes right most pixels with left most pixels 
void swapper
(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    //temporary variable used 
    RGBTRIPLE temporary_variable = *pixel1;

    *pixel1 = *pixel2;

    *pixel2 = temporary_variable;

}

// Reflect image horizontally
void reflect
(int height, int width, RGBTRIPLE image[height][width])
{
    int h, w;
    
    //itterates over height and width of the 2D array
    for
    (h = 0; h < height; h = h + 1)
    {

        for
        (w = 0; w < width / 2;  w = w + 1)
        {
            //uses swapper function to reflect image 
            swapper(&image[h][w], &image[h][width - w - 1]);

        }

    }

    return;
}


// Blur image
void blur
(int height, int width, RGBTRIPLE image[height][width])
{

    //variable declaraction
    int h, w;
    int avgred;
    int avgblue;
    int avggreen;
    float pixelcounter;

    //temporary variable for height adn width
    RGBTRIPLE temporary[height][width];
    
    //itterates of over hegiht and width
    for
    (h = 0; h < height; h = h + 1)
    {

        for
        (w = 0; w < width; w = w + 1)
        {
            //intialized to 0 for counters
            avgred = 0;
            avggreen = 0;
            avgblue = 0;
            pixelcounter = 0;
            int i, j;
            
            
            for
            (i = -1; i < 2; i = i + 1)
            {

                for
                (j = -1; j < 2; j = j + 1)
                {
                    //makes sures if the height and width of the picture aren't going beyond the limit of the jpg photo
                    if
                    (h + i < 0 || h + i > height - 1)
                    {

                        continue;
                    }

                    else if
                    (w + j < 0 || w + j > width - 1)
                    {

                        continue;
                    }
                    
                    //changes the pixels value by averaging the color pixels with neighbouring 8 bytes
                    avgred = avgred + image[h + i][w + j].rgbtRed;
                    avggreen = avggreen + image[h + i][w + j].rgbtGreen;
                    avgblue = avgblue + image[h + i][w + j].rgbtBlue;
                    pixelcounter = pixelcounter + 1;

                }


            }
            
            //rounds the value of colours and pixelcounter 
            temporary[h][w].rgbtBlue = round(avgblue / pixelcounter);
            temporary[h][w].rgbtGreen = round(avggreen / pixelcounter);
            temporary[h][w].rgbtRed  = round(avgred / pixelcounter);

        }


    }

    //itterates over the height and width again to change pixels with neigbouring pixels to blur
    for
    (h = 0; h < height; h = h + 1)
    {

        for
        (w = 0; w < width; w = w + 1)
        {

            image[h][w].rgbtBlue = temporary[h][w].rgbtBlue;
            image[h][w].rgbtGreen = temporary[h][w].rgbtGreen;
            image[h][w].rgbtRed = temporary[h][w].rgbtRed;

        }



    }



    return;
}
