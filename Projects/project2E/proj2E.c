#include <stdio.h>
#include <stdlib.h>
/*
fopen, fread, fseek, fprintf, fclose 
*/

int main(){
    
FILE *infile = fopen("./2E_binary_file", "rb");
FILE *outfile = fopen("2E_out_file", "w");

infile = fopen("./2E_binary_file", "rb");
if (infile == NULL)
{
    printf("Error: unable open file %s\n", "2E_binary_file");
    exit(1);
}

if (outfile == NULL) 
{
    printf("Error: unable to open outfile\n");
    exit(1);
}
int x = 0;
char ch;
while ((ch = fgetc(infile)) != EOF)
{
    if (x % 5 == 0)
    {
        fseek(infile, 5, SEEK_CUR);
        x++;
    }
    else if (x == 50)
    {
        fclose(outfile);
    }
    {
        fprintf(outfile, "%d\n", ch);
    }
        

  
  
    
    
}
}