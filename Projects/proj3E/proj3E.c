/* CS 212 - Sabrina Zhang
Stacks and Polish Notation 

Referenced Lab Code for Stack implementation
 
*/
#include <stdio.h>
#include <stdlib.h>

#define STACK_CAPACITY 20

typedef struct {
    /* Stack holds an array with a counter for top ie last value */
    int top; // this is a index number
    double array[STACK_CAPACITY]; 
} Stack;

Stack * createStack()
{ /* Initalizing stack */
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    (*stack).top = 0;
    for (int i = 0; i < STACK_CAPACITY; i++)
    {
        (*stack).array[i] = 0;
    }
    return stack;
}

void push(Stack * stack, double item)
{ /* Pushing stack items by index assigment */
    (*stack).array[(*stack).top] = item;
    (*stack).top++; 
    // increment top by one for the next stack index
}

double pop(Stack* stack)
{ // decrement top by one back to where it holds a value and return 
    (*stack).top--; 
    return (*stack).array[(*stack).top];
}

typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
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
    int flag = 0; //  is decimal
    int place = 1;
    int flag2 = 0; // is fraction
    
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


double operation (MathOperation op, double v, double v2)
{ /* Moved switch (op) out of main*/
    double result = 0.;
        {
        switch (op)
        {
        case ADD: result = v+v2;
         break;
        case MULT: result = v*v2;
         break;
        case SUBTRACT: result = v-v2;
         break;
        case UNSUPPORTED:
          IssueBadOperationError();
        }
    }   
    return result;
}

void pushStack(Stack * stack, char *str)
{ /* take a string and read it into StringtoDouble returns double */
    double value;
    value = StringToDouble(str);
    push(stack, value);
}

void runStack(Stack * stack, char *operand)
{ /* Calculate operation then put it back into stack */
        double v;
        MathOperation op;
        double v2;
        double result = 0.;

        op = GetOperation(operand);
        v2 = pop(stack);
        v = pop(stack);
        result = operation(op, v, v2);
        push(stack, result);
}   

int main(int argc, char *argv[])
{
    double result;
    Stack * stack = createStack();

    for (int i = 1; i < argc; i++)
    { // dereferences argv[i] with the star key
      // equivalently *argv[i] = argv[i][0] 
        if (*argv[i] != '+' && *argv[i] != '-' && *argv[i] != 'x')
        {
            pushStack(stack, argv[i]);
        }
        else 
        {
            runStack(stack, argv[i]);
        }
    }

    result = pop(stack);
    printf("The total is %d\n",  (int) result);
    free(stack);

    return 0;
}
