/*
CS 212 - Sabrina Zhang
Project 2F - String reversal 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(char *s)
{   /*Count the number of characters and iterate
    through s indices, then add placefor the null byte, and */
    int x = 0;
    while (*s != '\0')
    {
        s++;
        x++;
    }
    return x + 1;
}

void str_reverse(char *str)
{   //Take the length of str
    int length = my_strlen(str);

    char temp[length];
    // Assign a empty array the length of str
    int x = 0;
   
    for (int i = 0; i <= length; i++)
    { 
        if (str[length - i] == '\0')
        { // base case incase of null just go to the next ch
            i++;
        }
        else
        {/*set the temp index from left to right
         incrementing by minus i from total length
         ie : 7,6,5,4,3,2,1*/
        
            temp[x] = str[length - i];
            x++;
        }
    }
    temp[x] = '\0';
// set the null byte in temp at the end (x = length of str '\0' inclusive)
    for (int i = 0; i <= my_strlen(temp); i++)
    {
// and iterate through each index in str and replace it with temp[i]
        str[i] = temp[i];
    }
}

int main()
{
    char *str = malloc(strlen("hello world")+1);
    char *str2 = malloc(strlen("cs 212")+1);
    strcpy(str, "hello world");
    strcpy(str2, "cs 212");
    str_reverse(str);
    str_reverse(str2);
    if (strcmp(str, "dlrow olleh") == 0)
    {
        if (strcmp(str2, "212 sc") == 0)
        {
            printf("Congrats!  You have successfully reversed \"hello world\" to \"%s\"\n", str);
            exit(EXIT_SUCCESS);
        }
    }

    printf("Project does not work yet.  You reversed \"hello world\" to \"%s\" and \"cs 212\" to \"%s\"\n", str, str2);
    exit(EXIT_FAILURE);
}
