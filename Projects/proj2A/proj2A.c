/*
CS 212 - proj2A : Factor counter
Sabrina Zhang 

*/


#include <stdio.h>

int main(){

    for (int i = 2; i < 1000; i++)
    {
        int the_number = i;
        int num_factors = 0;
        for (int j = 2; j < i - 1; j++)
        {
            if (the_number % j == 0)
            {
                num_factors++;
            
                while (the_number % j == 0)
                {
                    the_number = the_number / j;
                }
            }    
        }

        if (num_factors == 3)
        {
            printf("%d has three factors\n", i);
    
        }
    }

}
