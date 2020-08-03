#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    
    float d;
    
    //do loop makes sure that dollar amount input is higher than 0
    do
    {
     
        d = get_float("Enter the amount of dollars: ");   
        
        
    }
    while// this boolean allows the loop to keep on prompting for dollar amount util they give higher than 0
    (d <= 0);
    
    //coverts dollars to cents
    int cents = round(d * 100);
    
    //counter variable used to count all the coins 
    int c = 0;
    
    //checks how many 25 cents are need and subtracts from total if needed 
    while
    (cents >= 25)
    {
        
        cents = cents - 25;
        c++;
        
    }
    
    //checks how many 10 cents are need and subtracts from total if needed 
    while
    (cents >= 10)
    {
        
        cents = cents - 10;
        c++;
        
    }
    
    //checks how many 5 cents are need and subtracts from total if needed 
    while
    (cents >= 5)
    {
        
        cents = cents - 5;
        c++;
        
    }
    
    //checks how many 1 cents are need and subtracts from total if needed 
    while
    (cents >= 1)
    {
        
        cents = cents - 1;
        c++;
        
        
    }
    
    //prints our the least amount of coins needed in change to user 
    printf("The least number coins in change are %i\n", c);
    
    
}
