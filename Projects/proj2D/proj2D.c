/*
CS 212 - Sabrina Zhang 
Project 2D - Math operations
Notes: 
- Chatgpt used for debugging and syntax error questions

- The line:
// else if ((*str >= '0' && *str <= '9') == 0)

Referenced code from ChatGPT: How to detect ASCII character between 
0 and 9 (in terms of ASCII equivalent values)

*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
   UNSUPPORTED
} MathOperation;

void IssueBadNumberError()
{
    printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}
void IssueBadOperationError()
{
    printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}

MathOperation GetOperation(char *op)
{
    if (*(op + 1) != '\0')
    {
        return UNSUPPORTED;
    }
    else if (*op == '+')
    {
        return ADD;
    }
    else if (*op == 'x')
    {
        return MULT;
    }
    else if (*op == '-')
    {
        return SUBTRACT;
    }
    else if (*op == '/')
    {
        return DIV;
    }   
    else
    {
        return UNSUPPORTED;
    }
}



double StringToDouble(char *str)
{   int value = 0;
    int current = 0;
    int operator = 1;
    int decimal = 0;
    int currentDecimal = 0;
    int flag = 0; 
    int place = 1;
    int flag2 = 0; 
    
    while (*str != '\0')
    {  
        if (*str == '-')
        {
           if (flag2 == 0 && flag != 1)
           {
                flag2 = 1;
                operator = -1;
                str++;
           }
           else
           {
                IssueBadNumberError();
           }

        }
        else if (*str == '.')
        {
      
            if (flag == 0)
            {
                flag = 1;
                str++;
            }
            else
            {
                IssueBadNumberError();
            }
        }
        else if ((*str >= '0' && *str <= '9') == 0)
        //  Refer to Doc
        {
            
            IssueBadNumberError();
        }
        else if (flag == 1)
        {
            currentDecimal = *str - '0';
            decimal = (decimal * 10) + currentDecimal;
            place = place * 10;
            str++;
        }
        
        else
        {
            current = *str - '0';
            value = (value * 10) + current;
            str++;
        }
        }

    if (flag == 1)
    {
        double frac = 0;
        double total = 0;
        frac = (double) decimal/place;
        total = value + frac;
        
        return (double) total * operator;
    }
    else
    {
        return (double) operator * value;
    }
    
}

int main(int argc, char *argv[])
{
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
    double v2 = StringToDouble(argv[3]);
    double result = 0.;
    switch (op)
    {
        case ADD:
         result = v+v2;
         break;
        case MULT:
         result = v*v2;
         break;
        case SUBTRACT:
         result = v-v2;
         break;
        case DIV:
         result = v/v2;
         break;
        case UNSUPPORTED:
          IssueBadOperationError();
         
    }
   
    printf("%d\n",  (int) result);
 
    return 0;
}