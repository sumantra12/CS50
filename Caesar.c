//available needed libraries
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>



int main
//Command line arguments
(int argc, string argv[])
{

    //if number of command arguments are 2, then program will proceed
    if
    (argc == 2)
    {
        //declared variables
        int k, n;
        char character_reader, cyrpt_text;
        string text;

        //checks the string value argument ex. command line argument was 12, 1 or 13
        k = atoi(argv[1]);

        //get_string receives the plaintext from user
        text = get_string("Enter plaintext: ");

        printf("ciphertext: ");

        //calculates the lenght of the string
        n = strlen(text);

        //for loop itterates the string value util the null key
        for
        (int w = 0; w < n; w = w + 1)
        {
        
            //reads each character from the get_string text and passes to conditions 
            character_reader = text[w];
        
            //checks if its a word
            if
            (isalpha(character_reader))
            {
            
                //changes letter if uppercase by using ASCII
                cyrpt_text = 'A';
 
                //checks if the word is lowercase
                if
                (islower(character_reader))
                {
                    //changes letter character if lowercase
                    cyrpt_text = 'a';
                }
                //prints the cipherd text with the new formula that is able to change any ASCII key
                //for example it takes each letter - by the crypt_text ASCII ads the argv(k) value and does modulus 26 and adds back the cyrpt_text
                printf("%c", (character_reader - cyrpt_text + k) % 26 + cyrpt_text);

            }
            //if the character isn't a ASCII letter upper or lower case it'll just print out the character
            else
            {

                printf("%c", character_reader);

            }


        }

        
    }

    //else if not 2, program will crash and give error
    else if
    (argc != 2)
    {

        printf("Usage: ./caesar key\n");
        return 1;//return 1 as error

    }


    printf("\n");


}
