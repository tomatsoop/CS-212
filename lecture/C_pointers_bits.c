// This is a global variable
#include <stdio.h>

int max(int n1, int n2); // function prototypes
// declaring the functtion before use
int change(int amt);

int g_x; // global variable declared outside the function bodies

int main(void){

    int x, result; // local variables: declared inside function body
    printf("Enter a value:");
    scanf("%d", &x);
    g_x = 10; // global variables can be accessed inside any function 

    result = max(g_x, x);
    
    printf("%d is the largest of %d and %d\n", result, g_x, x);

    result = change(10);
    printf("g_x's value was %d and now is %d\n", result, g_x);

    return 0;
}


int max(int n1, int n2){ // A function with two parameters
    int val; //local variable
    val = n1;
    if (n2 > n1){
        val = n2;
    }

    return val;
}

int change(int amt){
    int val;
    val = g_x; // g_x is a global variable that can be accessed from anywhere
    g_x += amt; 
    return val;


}
/* A variable's scope defines when its name has meaning
A scope defines the set of program code blocks in whcih a variable
is bound to (associated with) a program memory location and can be used
by program code. 

Declaring a varibale outside any function body creates a global variable.
Global variables remain permantely in scope and can be used by any code 
in the program because they're always bound to one specific memory locattin

Every global variable  must  have a unique name, its unique name identifies 
a speceifc storage location in a program memory for the entire duration
of the program


Local variables and parameters are only in scope inside the functioni in 
which they are defined

A program's address space represents storage location for everything  it
needs in its execution, namely storage for its instructions and data

A programs adress space can be thought as an array of adddressable bytes;
each used address in the program's address space stores all or part of a 
program instruction or data value

The programs instrcuction are stored in the  code section of memory
ie the functions and instructions are stored  int eh code section
local variabls and parameers live  inthe stack, 

Local varibables and parameters reside in teh portion  of memeory for the 
stack. Because the amount of stack space grows and shrinks over th program's
execution as fufnctions are called and returned from, the stack part of memory 
typically allocated near teh bottom of the memorry (at the highest memory addresses)
to leave space for it to change. Stack storange space for local variables and
parameters exsists only when the functtion is active (within the stack frame
for the function's activation on the stack)

Global variables are stored int eh data section, unlike the stack, the data 
region does not grow or shrink, storage space for globals persists for the 
entire run of the program

The Heap portion of memory is the part of a progrram's address space associated with 
dynamic memory allocation. The heap is typically located far from theh stack 
memeory and grows into higher addresses as more space is dynamically allocated
by running the program. 



C pointers 
C's pointer varibales provide a level of indirection to accessing program memory.
Through pointer variables, a C programmer can:

implement functioins whose parameters can modify values in the caller's
stack frame

dynamically allocate (and deallocate) program memory at runtime when the progra
needs it

efficently pass large data structures to functions

create linked dynamic data structures 

interpret bytes of porgram memory in different ways

A pointer variable stores the addresss of a memory location in which a value is a
specific type that can be stores

// a pointer stores teh address of a memory location of a value

For example, a pointer varibale can store teh value of an int address at which 
the interger value 12 is stored. The pointer variable points to (refers to)
the value. A pointer provides a level of indirection for accessing values 
stored  in memory

Through the pointer variable, ptr, the value (12) stored in the memory location
it points to can be indirectly accessed. C programs most frequently use pointer 
varibales for:
1. "Pass by pointer" parameters, for writing functons that can modify their
arugment's value through a pointer parameter 

2. Dynamic memory allocation, for writing porgrams that allocate (and free) 
space as the program runs. Dynamic memory  is commonly used for dynamically
allocating arrays. It is useful when a programmer doesn't know the size of a 
data strucure at compile time (eg the array size depends on the user input
run time) It also enables data structures to be resized as the program runs.


Rules for Using pointer Varibales
Similar to using varibales, howeveer we need to think about two types:
The type of pointer variable and the type stored in the memory address to 
which the pointer variable points

1. First, declare a pointer variable using type_name *var_name
Ex:
int *ptr; // stores the memory addrerss of an int ("ptr points to an int")

char *cptr; // stores the memory address of a char (cptr "points to a char")


Pointer types:
Note that although ptr and cptr are both pointers, they reer to different types:

The type of ptr is "pointer to int" (int *) It can point to a memory location
that stores an int value

The type of cptr is "pointer to char" (char *). It can point to a memory location
that stores a char value

2. Initialize the pointer variable (make it point to something)
Pointer variables sore address valeus. A pointer should be initailized to
store the address of a memory location whose type matches the type to which
the pointer variable points. 
One way to initialize a pointer is to use the address operator (&) with a 
ariable to get the variable's addess value

int x;
char ch;

ptr = &x; // ptr gets the addresss of x, pointer "points to" x
cptr = &ch; // cptr gets the address of ch, pointer "pointns to" ch 

Invalid pointer:
cptr = &x; 
Error: cptr can holld a char memory location
// &x is the address of an int

All pointer variables can also be assigned a specail value NULL, which 
represents an invalid address. While the nulll pointner (one whwose value is NULL)
should nevere be used o access memory, the valueu NULL is usefull for testing
a pointer variable to see if itt points to a valid memory address. 
That is, C programmers will commonly check a pointer to see that its value
isnt NULL before accessig the memory location to which it poits to.
To set a pointer to NULL:
ptr = NULL;
cptr = NULL;
Any pointer can be given the special value NULL, which indicates that it 
doesn't refer to any particular address.

3. Finally, use the pointer variable: the deference operator (*) follows 
a pointer variable to the locattion in memory that it points to and accessses
the value at that location:
ptr = &x; // initalizes ptr to the address of X (ptr points to variable x)
*ptr = 8; // The memory location of ptr points tot us assigned to 8 

*/

// Pointer exmaples

int *ptr1, *ptr2, x, y;

x = 8;
ptr2 = &x;
ptr11 = NULL;
// In this case ptr2 is assigned at the address of x 
// which x stores the value of 8

*ptr2 = 10; // The memory location ptr2 points to is assigned 10
y = *ptr2 + 3;
// y is assigned waht ptr2 points to plus 3

/* 
In this case innt *ptr1, *ptr2 creates the memory for the Pointer
and the space for ptr2 was orignally assigned to 8, then reassigned to the
the value 10 when *ptr2 was declared to = 10
*/

ptr1 = ptr2;
// ptr1 gets the address value stored in ptr2 (both  will now point at 10)

*ptr1 = 100;
// The value of ptr1 and ptr2 now is 100

ptr1 = &y; // changes what it points to
*ptr1 = 80;
ptr1; //now points at the address of y which holds the value 80

ptr = 20; // error: This assigns ptr to point to address 20
ptr = &x;
*ptr = 20;
// Correct: this assigns 20 to the memory pointed to by ptr

/*
ptr points to a memory location we can name as a variable by  doing 
ptr = &var_name;
and we can add a value to that variable by using *ptr = value
*/




// Pointers and functions 
/*
Pointer Parameters provide a mechanism through which functions can 
modify arugment values. The commonly used pass by pointer patterrn 
uses a pointer function parameter that gets the value of the address
of some storage location passed to it by the caller. For example, the 
caller could pass the address of one of it local variables.
By dereferencing the pointer parameter inside the function, the function
can modify the value at the storage locaton to which it points


Steps to implementing and calling a function with a pass by pointer
parameter:
1. Declare the function parameter to be a pointer to the variable type:

int change_value(int *input)

2. When making the function call, pass the address of a variable as the arugment
int x;
change_value(&x);

In the preceeding example, since teh parameter's type is int *, the address passed
must be the address of an int variable

3. In the body of the function, derefence the pointer parameter to change the argument's 
value:
*input = 100; // The location input points to (x's memory) is assigned to 100

*/

#include <stdio.h>
int change_value(int *input);

int main(void){
    int x;
    int y;

    x = 30;
    y = change_value(&x);
    printf("x: %d y: %d\n", x, y);  // prints x: 100 y: 30

    return 0;
}

/*
Changes the value of the argument
input: a pointer to the value to change
returns: the original value of the argument 
*/

int change_value(int *input){
    int val;
    val = *input; // val gets the value input points to
    if (val < 100){
        *input = 100;
    }
    else{
        *input = val * 2;
    }
    return val;
}

/*
The input parameter gets a copy of the value of its argument (the address of x).
The value of x is 30 when the function call is made. inside the hchange value 
function, the parameter is dereferenced to assign the value 100 to the memory
location pointed to by the parameter (*input = 100; meanning "the location input
points gets the value 100")

Since the parameter stores the address of a local variable in the main function's
stac frame, through derferencing the parameter, teh valuue stored in the caller's 
variable can be changed. When the function returns, the arugment's value reflects 
the change made to it through the pointer prameter (the value of x in main was changed
to 100 by the change_value function through its input parameter)


*/

/*
Think of memory as one big array made up of bytes
with addresses that we can address it

These addresses how you get to a specific location,
like a room numbers of a hotel
The pointer is the address, that tells us where to get something
pointer is a number that describes a location in memory

* - take whats located at this and use it
& - give me the address of this object

int i = 5

int *p = &i

somewhere in memory, you will have a location p
that has type address of i, and say 24 is the address 
of i, p now equals 24

*p = 15 
this will change the value of i to 15

int j = 10;
p = &j

star p equals address i
star p is whatever p is refering to
p is the value of what p is addressing to 

pointer is the index value to that location
*/


/*





*/