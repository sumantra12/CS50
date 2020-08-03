#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


int main(void)
{

    //variables declared
    float words;
    int sentences;
    int letters;
    int j, grade;

    float avg_l;
    float avg_s;

    words = 0;
    sentences = 0;
    letters = 0;

    string text = get_string("Enter text to be evaluated:\n");

    //calculates the length of the string(text being inputted)
    j = strlen(text);

    //for loop runs string input and checks letters, words and sentences.
    //variable w has to be less than strlen(text) to be able to stop and read the entire text until the null character(\0)
    for
    (int w = 0; w < j; w = w + 1)
    {

        //checks the number of letter
        if
        (isalpha(text[w]))
        {
            letters++;

        }

        //number of sentences, if their is ., ? or !
        if
        (text[w] == '!' || text[w] == '.' || text[w] == '?')
        {

            sentences++;
        }

        //checks for number of words, be calculting the spaces in the text
        if
        ((w == 0 && text[w] != ' ') || (w != j - 1 && text[w] == ' ' && text[w + 1] != ' '))
        {

            words++;
        }


    }

    //calculates the average of letters and sentences
    avg_l = letters / words * 100;
    avg_s = sentences / words * 100;

    //calculates the grade with the formula combined with the average letters and sentences
    grade = round(0.0588 * avg_l - 0.296 * avg_s - 15.8);


    //checks if less than 1 and prints before grade 1
    if
    (grade < 16 && grade >= 1)
    {
        
        printf("Grade %i\n", grade);
        
    }

    //prints 16+ if grade not 1-15
    else if
    (grade >= 16)
    {

        printf("Grade 16+\n");
    }

    //prints the grade level between 1-15
    else
    {
    
        printf("Before Grade 1\n");
        
    }


}
