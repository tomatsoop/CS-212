/*
CS 212 - Word counter reading from File
ChatGPT used during debugging for the comparison if statement and malloc
Prompt: "Why does this not trigger if (*text != '.' || ',' || ' ' || '\n')
ChatGPT: Use  if (*text != '.' && *text != ',' && *text != ' ' && *text != '\n')"

Prompt: Why is it that malloc a empty index prints random value?
ChatGPT: Memory is reserved but not initalized. Use a for loop to 
store every value in the index as 0. 

Prompt: Error on Valgrind: Conditional jump or move depends on 
uninitazlied value. memory address.. compstr function
What is this error saying 

Chatgpt: Intialize the null byte at the end of readfile function
for the malloc text.

Correction: archive[fileSize] = '\0'; in readfile


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long filesize(FILE *file)
{
    long size;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
    return size;
}   

char *readfile(FILE *fptr)
{
    // Size of the file
    long fileSize = filesize(fptr);

    // Memory allocate space the size of the file
    char *archive = malloc((fileSize * sizeof(char)) + 1);
    fread(archive, 1, fileSize, fptr);
   // read the file into the malloc of archive
    archive[fileSize] = '\0';
    fclose(fptr);
    return archive;

}


int *compstr(int argc, char *array[], char *text)
{   // compare argv (array of words) vs text (current word pointer)
// This takes the number of arguments from main, an array from main,
// which is the list of words we are searchign for, and the file 
// inpput stored in text

    int args = argc - 2; // skip the file variable
    
    // malloc a array the number of arugments entered - 2 (for file input and exe)
    int *index = malloc(args * sizeof(int));
    
    // Chatgpt used here, code self written.
    for (int i = 0; i < args; i++)
    {
        index[i] = 0;
    }
    int k = 0;

    while (*text != '\0')
    {
        //Initalize a temp word holder
        char current[100];
        
        // Chatgpt used here. Conditional part was copied
        if (*text != '.' && *text !=','  && *text !=' ' && *text !='\n')
        { /* check for end of string conditionals and index 
             each charater in current */
            current[k] = *text;
            text++;
            k++;
        }
     
        else
        {/* End of string conditional met.  
            Set end of current to null byte.
            Compare string to each argument in argv via indexing */
            current[k] = '\0';
            
            for (int i = 0, k = 2; i < args; i++, k++)
            {   /* main condition is based on each argument value
                   stored in array[k] */
                int length = strlen((array[k])); 
                int count = strncmp((array[k]), current, length);

            /* Check for entire word on both and not half the string */
                if (count == 0 && strlen(current) == strlen(array[k]))
                { 
                    index[i] += 1;   
                }
            }
            /*Reset text pointer and reset k index*/
            text++;
            k = 0;
        }
    }
    return index;
    }

void statement(int argc, char *argv[], int *count)
/* Prints the out statement based on index value from 
   compstr and entered arguments */
{
    int argNum = argc - 2; // for exe and file name
    for (int i = 0, k = 2; i < argNum; i ++, k++)
    {
        printf("The word \"%s\" occurs %d times.\n", argv[k], count[i]);
    }
}

int main(int argc, char *argv[])
{   
    FILE *infile = fopen(argv[1], "r");
        if (argc < 2)
        {
            printf("Error: Invalid number of arguments");
            exit(1);
        }
        if (infile == NULL)
        {
            printf("Error: unable to open %s\n", argv[1]);
            exit(1);
        }
    /*  archive stores the file as an entire text
        index stores the count of each occurance   */

    char *archive = readfile(infile);
    int *index = compstr(argc, argv, archive);
    /*statement runs the file for print output*/
    statement(argc, argv, index);
    free(archive);
    free(index);
}