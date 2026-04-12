/*
CS 212 - Sabrina Zhang, 10/27/2025
I/O Stream 
References: 
Command line arguments: https://www.geeksforgeeks.org/cpp/command-line-arguments-in-c-cpp/
*/
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    FILE *infile = fopen(argv[1], "r");
    FILE *outfile = fopen(argv[2], "w");

    if (argc != 3)
    {
        printf("Error: invalid number of argument");
        exit(1);
    }
    if (infile == NULL)
    {
        printf("Error: unable to open %s\n", argv[1]);
        exit(1);
    }

    if (outfile == NULL)
    {
        printf("Error: unable to open %s\n", argv[2]);
        exit(1);
    }
    
    char ch;
    int buffer[5];
    int x = 0;
    while (x != 5)
    {   
        fread(buffer, sizeof(int), 5, infile);
        for (int i = 0; i < 5; i++)
        {
            fprintf(outfile,"%d\n", buffer[i]);
        }
        fseek(infile, 20,SEEK_CUR);

        x++;
    }
  
    fclose(outfile);
    return 0;
    }
   

