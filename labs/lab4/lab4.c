#include <stdio.h>

int main()
{
    char userInput[14] = { 'a','a','b','b','b','b','b','a', 'c', 'x', 'y', 'b', 'z', 'z'};
    char toCount[6] = { 'a', 'b', 'c', 'x', 'y', 'z' };
    
    /*
    Count the number of times each character from toCount
    occurs in userInput and print it
    */
    int counted[6] = {0,0,0,0,0,0};
    for (int i = 0; i < 100; i++)
    {
        for (int k = 0; k < 6; k++)
        {
            if (userInput[i] == toCount[k])
            {
                counted[k]++;
            }
        }
    }
    for (int j = 0; j < 6; j++)
    {
        printf("%c has %d occurances. \n", toCount[j], counted[j]);

    }
}