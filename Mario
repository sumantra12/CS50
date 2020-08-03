#include <stdio.h>
#include <cs50.h>

int main(void){

    // h represents height
    int h;
    

    do{

        //asks user to input the height of the pyramid
        h = get_int("What height for the pyramid would you like: ");


    }while(h < 1 || h > 8);
    
    

    //this loop is used to print next line for each row of the pyramid depending on the height
    for(int i=0; i< h; i=i+1){




        //this nested loop prints the spaces to make the pyramid left sided.
        //the formula used to find the no. of spaces would be inputted height - no. rows - 1
        for(int k=0; k < h - i - 1; k=k+1){
            printf(" ");
        }

        //to print a pyramid like block, the columns number has to be less or equalto than the row numbner for each height
        for(int j=0; j<= i; j=j+1){


            printf("#");
        }

        printf("\n");



    }
    
    

}
