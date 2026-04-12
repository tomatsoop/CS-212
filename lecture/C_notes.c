#include <stdio.h>
int main(void) {
    // int main is always needed to create a file
    // void tells it we dont need any arugments
    printf("%s\n", "Hello World");
    // %s is a placeholder for string
    // which is replaced  by the arugments passed 
    // at the end
    // %d is a placeholder for a number
    // everyline ends with a semi-colon

    return 0;
}



/*
Run C programs
$ gcc hello.c

# this creates a file called a.out
# That is the executable file for computer code

we can call the script using 
./a.out
^^ This executes our compiled code

*/


/*

Jobs of a Compiler
Inputs
    - Headers and standard libaries 
    - A program that we can read (hello.c)
    - User Arugements
    - Enviroment
What are the intermediant steps:
    - Preprocessing
    - Translating machine code into machine code
        - Into a assembly language
        - do a syntax check
        - removes white spaces
        - remove all your types are correct
Outputs: 
    - Optimized code
    - A executable file (a.out)
    - Error and warning codes
What would we like it to do?
    - Run our code


Compilation
*.c --> CPP --> Compiler --> *.o --> linker --> a.out
C model


C preprocessr Directives
#inlcude - literal inclusion fo a file
#include <foo.h> <-- Standard files in system global files
ie stdio.h etc etc 
$include "foo.h" <-- The file is in your directory 

#define foo bar -- literal replacement of "foo" with "bar"
    Useful for symbolic constants (and other things)
    Use UPPERCASE for constants 
        usually these are at the top of the file 
    

    

#define foo bar -- literal replacement of "foo" with "bar"
useful for symbolic constants (and other things)
use UPPERCASE for constants
    usually these are at the top of the file

Makes things more legible 


printf
int printf(format, .../ args /);
return value is number of characters printed
format is a string constant 
% characers are treated as special


s string
c character
d signed decimals
e scientic notation
f decimal float up to 6 places


printf("%s\n");
raises a warning
compiles into random characters
that prints the memory where it expected
to have the string input to be located
it printed the string founded at that location 


Naming Convetions

camel case:
getInteger() 

C style - underscores
get_interger()

Constants and macros:
UPPERCASE

dont use:
_variable, _Variable or variable_
dont put underscores at the begining or ends

Variable Declarations
Variables must be declared before use

Only have primative type declariton 
char* src, dst*;
only src is a pointer

you need to initalize variables 

Literals 
Expand to fit the number specified
- Suffixes U unsigned, L long, LL longlong

Intergers can be decimal, octal, or hex

Floats defaults to double
Suffixe F float, L long double 
0.5F        1.23L

Characters
Usually represeted as int internally
Can treat them like int, including mamthematics

ctypes.h 
has a lot of functions that 
convert isdigit, is string, isupper, etc

Strings
Must be in double quotees
Convenience type, actually an array of character
- literal characters followed by \0 <--Null byte
----> the memory locattion like when the printf without a argument

'x' character x ---> one byte
"x" string with x in it ----> two bytes, 'x' and '\0'

can be concatenated by compiler 
"hello" "world" can become "hello world"
strings in C are mutable because they are a array of characters

'x' holds fewer bytes compared to "x" 


Stack
Writable not executable
Managed "automatically" by compiler

function in the function state lives in a stack only when its running
when it stops running, it terminates and goes away


Dynamtic data
writable; not executable 
                 

Scopes
local variabels are in the scrope of the fuction 
- cannot use outside block
- only exsists when the function is running

external variables are in scope form
declarationto EOF
- AKA global variables
- Functions defs are external variables


External variables
Definition actually sets aside space for varibale
int data = 5;  // one place
This is allocating an int worth of space in memory and assigning the value 5

extern declares a variable w/o reserving space
- announces types and name 
- like function prototype
- Use in header files

extern int data; // everywhere else


Static variable
static int data;
a variable within a function, but it keeps its value between repeated
calls to this function

The value of a static x is shared across all calls to this function

static local variable:
- keeps value between function calls

static global variable
- Also accessible through repeated function calls
- only accessible insidegiven file
- not even accessible via extern

Linking
Part of the compilation process
Matches all variables with the same name to the sa,e item if the in scope
regardless of what file it is in

Global, Static local, and static global variables can hold a function 
variable value throughout calls 


Operators
Standard math : + - * / %
logical relations > >= < <=
logic/equalities: == !=
Logic Boolean: && ||
    short circuts (B!=0) && ((A/B) > 1)
    No required boolean types
1 is true 
0 is false
Something is true
Nothing is false

If statements
if there is no curly braces, it will run the first line of code

if (foo) {
    // runs when foo is true
}

if (foo) {
    // runs when foo is true
} else if (baar){
    // runs when baar is true
 
} else if (barr){
    // runs when barr is true
 
}

if (3)
    printf("foo");
    printf("bar");
printf("baz");

output: "foobarbaz"

Indentation does not matter in C, printf("bar") is not apart
of the conditional statement
not having if (conditional) {   } missing the curly brackets
will cause it to run the first arguement 

if (0) it will skip the first line

if (3)
    if (0)
        printf("foo");
else printf("bar");

if (0) will not print the foo
here it will print "bar"







*/

/*
Ternary operator
Shortcut way of getting a  value based on an if statement 
(i == 1)       ?        'is' : 'are'
if this    then         this : or else this

Switch statement

switch (flag){
    case 'a':
        a_flag = 1;
        break;
    case 'b':
        b_flag = 1;
        break;

    default:
        error_flag = 1;
        break;

}

for loops

for (int i = 0, sum = 0; i < 10; i++)
{  initalization,      test,    update
    printf("i is now %d\n", i);
    sum += i;
// initalize i as int, sum = 0, while i is less than 10, 
// run this loop and increment i++ by one

}

while loop
while (x > 1){
    x -= 1;

}

use a for loop if you know how long it will take
use a while loop until a condition is met

infinite loops:
while (1)
{
// loops forever
}


for(;)
{
// loops forever
}

Controlling Loops:
break stops the corruent loop and jusmpst s outside the current block
continue jumps the block 

Do while loop:
do {
    x -= 1;
} while (x > 1);
   
Do while loop will execute the block at least once then condition is tested

while do is the condition may never be met

*/

/*
Bit wise operations
C is close to the hardware level
- often used to interface with HW
Need to manipulate binary data 
Operations only work with intergral operands
- char, short, int, long, long long 


Binary Data
Data is stored in words annd registers in a binary format

Word Size - smallest addressable unit of memory

int data type usually takes up a word of space


Number Base review:
Given a decimal (base 10) number 1253_10

3 ones (10^0)
5 tens (10^1)
2 hundreds (10^2)
1 thousands (10^3)

Base 8 (Octal)
Only uses the digits 0 - 7
in C, literal starts with leading 0 
Given a octal (base 8) number 02345

5 ones 
4 eights
3 sixty fours
2 five ehundred twelves

Base 16 (hexadecimal)
Single place has values of 0 - 15
Need digits larger than 9. Use A = 10, B = 11, ..., F = 15
in C, starts  with leading 0x

Given a hexadecimal (base 16) 0x04ES
5 ones
14 sixteens
4 two hundred fifty sixes
0 four thousand ninety sixes

Base 2 Binary
Only uses Zeros and Ones
Given a binary number 
0b 0000 0100 1110 0101

Converting to a Decimal
Multiply and sum up the digit*place value
- 1253 base 10 is 1*1000 + 2 *100 + 5 * 10 + 3 = 1253
- 023455 is 2 * 512 + 3 * 64 + 4 * 8 + 5 = 1235
- 0x04E5 is 0*4096 + 4 * 256 + 14 * 14 + 5 = 1253
- 0b 0000 0100 1110 0101 = 1253

All 4 are the same number and would be identical inside a computer

Converting Binary to Hex
Just group by 4 starting with least significant bit (LSB)
(left side)
0b 0000 0100 1110 0101

Each block of 4 binary digits can be 0-15 
Replace each with a hexadecimal digit
- 0 4 E 5
- 0x04E5

Converting from binary to costal
Just gropu digits by 3s starting with LSB
\
Each block of 3 binary digists can be 0 - 7 


Convert 0x9C1
Convert hex deciaml to binary

1001 1100 0001
c counts up from 10, 11, 12 c = 12
100 011 100 001
4 7 0 1
Need to convert from Binary to Hexadecimal
 wont be on exam for octal
 


During interger overflows, the stack ovoerflows
and restarts to 1
the  value becomes very samll and do not get a warning

*/


/*

Dynamic memory allocation allows C to request more memory as its running
a pointer varibale stores the address of the dynamically allocated space. 

Dynamic memory allocation grant flexibity to progams that
Do not know the size of arrays or other data structures until runtime

need to allow for variety of input sizes (not just up to some fixed capacity)

want to allocate eactly the size of data structures needed for a particular
execution (dont was space
)



Bitwise Operator
& bitwise AND
| bitwise OR
^ Bitwise XOR
<< Left shift
>> right shift
~ Negation

do this bitwise operation for every single input

0101
1101
&
------
0101

AND Operator
Frequently used to turn bits  off (masking)
n = n & 0x7f

Recall bitwise AND is only true if both values are true
turns everything else off

OR operator
Frequently used to turn  bits on
flag_read = 04; // 0100
flag_write = 02; // 0010
flag_execute = 01; // 0001

Bit shifting
Manipulates the postition of bits
x << 2; // shifts bits of x two positions to the left
    same as multiplying by 4
    x >> 3; // shihfts bits of x three position to the right
        same as diviifng  by 8

Left shifts fills with 0 bits 
Rights shifht of unsighted variable fills with 0 bits
Right shit of signed variable fills with signed bit 


Negative numbers
Usually stored using two's complement
    Take the magnitude of the number
    Invert all of the bits (one's complement)
    Add 1 (two's complement)

Converting back uses the same operation

Most significant bit indicates the sign
1 indicates a negative number 

0 - 0000
1 - 0001
2 - 0010 
3 - 0011
4 - 0100

-0 > 1111
-1 > 1110
-2 > 1101
-3 > 1101

negation

Signed numbers  in two's complement
choosing two places below 

-1 would be 111111111111111111
0 would be  000000000000000001 
This is the twos complement that gets rid of -0



take the magnatidue of the number 
invert all the bits 
and add 
00101001
base 10 

leading with 1 is a negative 


Assuming 8 bit twos complement numbers, 
what is the value of 11010110 expressed in base 10 

1. Invert and add 1 

to undo it
subtract 1 and invert

11010110
+
00000001
-----------
11010101
Negate
00101010
2^5 + 2^3 + 2
= 42


#include 

int n = Ob11010110;
printf("%d\n", n)
prints 214
but ints are 32 bytes
Ob11111111111111111111111111010110

ints are 32 bites

alternatively we can assign as char
char n = Ob11010110;

or 
int n = 0xFFFFFFDF;
printf("%d", n);



Functions
Exists from mention to EOF
you cant refer to a function until you have actually named it

Implicit declarations
    Use function protypes 
        name of the function (parameters);

create header files, usually named with '.h' extension
SHould  have no executable code in them 
    funciton protypes 
    holds your file headers

Use:
#include "header_file.h"
// double quote means " " in local file
// < > means look in the global system 

example: foobar.h

#ifndef FOOBAR_H
#define FOOBAR_H
//ifndef means if not defined
then define will run
this works so the file  only runs once
makes sure your include doesnt include more than once


#ifndef FOOBAR_H
#define FOOBAR_H
int sample_func(int a, int b);
double other_func(double);
void no_ret_no_params(void);

#endif

this is one code block that runs entirely only once


int foo(int a, int b);
int bar(int a, int b);
// ^^^ this is the function protype 
// we can chuck these in the header file


int bar(int a, int b){
    return foo(a,b);


int foo(int a, int b){
    return a + b;
}

*/



/*
Preprocessor comands:
These are macros in C
#define forever for (;;)

#define max(A,B)  ((A) > (B) ? (A):(B))

#define  square(x)  x*x
define square(x)   (x) * (x)
// if youre going to make macros, put parenthesises in there

#if,#else,#elif, #endif


((A) > (B) ? (A):(B))
if (A) > (B) is true, whatever is after ?
in this case (A)
else whatver is after the : 
so B

#define max(A,B)  ((A) > (B) ? (A):(B))
int x = 5, y = 4, z;
z = max((x++, y));

D: x = 7, y = 4, z= 6;

x++ evalutes after 

try not to use x++



built in macros 
debgging macros 



Stack - local state is kept here 
function parameters 
stack grows and shrinks as your function calls differnet things

Heap - Allocate dynamic memory 
Things not dependent on current state of the program 

Pointer Exmpals
POinters are addresses that point to memory

pointer is a index to an array 

addresses are 
0x0
...
0x10
0x14
0x18
0x20

eahc one has a binding llocation for z[x]
int x = 1, y = 2, z[10];

int iptr; // '*ipter is a int"
iptr = &x; // The value is now the address of x, now we have 2 ways to reference this int

y = *iptr; // can get value using the pointer

in this case, y is now assigned to the value of x, and now got the value of x = 1
so y = 1

*iptr = 0;
This changes the value at the address iptr derefences it  and reassigns the value to 0 

iptr = &z[0];
iptr can point to any intergr

*iptr = *iptr + 10; 
iptr += 10; 

y = *iptr + 2;

int *bptr;

bptr = iptr;
^ this sets one pointer to another

vs 

*bptr = *iptr;
This stores the value of *iptr into what *bptr is pointing to 
This takes the contents of *bptr to be the same as the contents of *iptr
bpter is a interger 
iptr is a interger

*bptr is a address that holds a value



These two are different please look att it 

Dereferencing is store this item at this memory location 

* gives you the value 
we can get what is located at that address or put this value in that address

& gives you the address of that location



command line arguments are pointers to pointers to string

Pointer types 
Pointers must point to specifed variable type




strcmp()

coampares strings 2 strings
int strcmp(const char *s1, const char *s2)
returns 
x > 0 if s1 > s2
x = 

strcat()
concatenamte one string onto the end of the other 


for creating strings, always do length of char + 1 for thhe null byte
at the end for '\0'

Warning! 
strings are defined by '\0' at the end
arrays have a fixed amount of space

be careful that you have suciffent array allocated

us n version bounts to check
strcat() etc

String functions operate on exsisitinig arrays
How do we dynamically allocate memroy for string?

strdup()
#include <string.h>
char * strdup(cosnt cahr *str); // THis goes into the heap
returns a copy of str
returns NULL on error
# define NULL (void *) 0 
needs to be manually cleaned up with free()
dynammically allocated memory needs to be cleared with free()

How does this work?
1. Checks the length of input string
2. Allocates new char[] of the right size
3. Copies old to new

we can allocate with malloc()
#include <stdlib.h>
void *malloc(size_t size)
size_t is a int 
malloc(n * sizeof(int))

int *int_array = malloc(10 * sizeof(int));
char *c_array = malloc(20 * sizeof(char));

need to free(c_array) or free(int_array) when done

stack is a run time state
heap is data that allocates for the memory
heap memory needs to be cleared using free()

global data is stowed in static data
literals are read only libaries
instructions are the code that are in memory 

which means we have pointers to our code, but we cannot write
to this space

it is the only chunk of memory that is exectutable


Function poiniters
functions are executable machine code 
Executable code is stored in memory
Name of function is the location of the code 

Function names are pointers


Declaring functiton pointers
consider strcmp()
    taes two char* as args, returns an int

int (*fptr)(char*, char*)
parents around aorund "*fptr" are immportant


quicksort
built into the standard libary 
no generic type, uses pointers instead
 -c needs to know if we're storing a ch, an int, structs, etc

instead of creating a bajjion for each type, we can use pointers

void qsort(
    void *base,
    size_t nel,
    size_t width,
    int (*compar)(const void*, const void*)

const tells the compiler that the value will not be changed


The story so far... 
primative types 

structs

struct player
{
    double x;
    double y;
    char name[20];
}

struct format

struct <struct tag>
{
    // members
    int x;

};

name is optional (structure tag)
 need at least  one member, 
the end of the struct outside the last } needs a semi colon

structs end with };

creating instances

Once defined, use name to create instances
once a struct is defined, we can create instances of it 
struct player a, b,c;

can create anonymous struct instances
struct {double x, y} p, q, r; <-- dont do this


everything within a struct has its own name space

struct x {int x; } x; <-- dont do this

accessing member varibales 

struct player a,b,c;
a.x 0.0;
a.y = 0.0;
a.alive = TRUE;


initizlizing struct
struct player a = {1.0, 2.3, "Boomer", TRUE}

nestirng structures

struct team {
    struct player boomer, zoomers, dennis
    }


3 types of declarations
struct tag{members};
struct tag{members}
struct tag{members}

if an int is size 4 and char is size 1
how big would you expect the struct be 

struct <example>
{
    char c;
    int i;    
}
memory address only holds 4 bytes at a time
this structure takes up 8 bytes
it is fetched by groups of 4 

Dont hardcode numebrs instead use sizeof(int)
sizeof(char), this makes the code as generic as possible


Using structs
Once declared, behvave like primative types

can be returned foroma  funcion 
can be passed o a function 


void foo(struct player p) { }

this is called PASS BY VALUE

Structs are blocks of data
large structs will take loonger to pass as a parameter

Can do copies with simple =
boomer = zoomer;
CANNOT test for equality (== is invalid)

copies are shallow
changes to structs are local to function 


passing struct as global variable invalidates changing values in the 
local function

Pass by reference
Define function as 
void foo(struct player *p)


inside function foo 
(*p).x = 123.4
(*p) derefences p first before calling tthe value of .x in struct

alternate representation 
p -> x = 123.4 


can be combined

struct army *omyarmy;
my_army = malloc(sizeof(struct army));


arrays of structs 
struct struct


Ddefinee new types in C

"struct" creates a compsite type

can also create new type name 
typedef unsighed int size_t;
note defined type often ends in _t

typedef char * String;
now we can use it as a base type
String word, type[50]


Often times you use this with structs

typedef struct llnode llnode t;

or

typedef struct llnode


typedef struct 
{
float x, y;
} Point; 



Formatted input 

int scanf(const char *format, ...);

input analog to printf()
reads input from stdin
uses format string to determine types
arguemtns must be poointers
    common error

Stops when 
    format string is done 
    input mismatch

returns # of successsfully matched items
returns EOF on EOF not 0 

reads from standard in, it reads whatever you pass in as a format string

it stops when teh format string is done or when it encounters an error



scanf(%placeholder, &addressofx) for intergers
scanf doesnt need & sign for strings. It reads till the null byte
char is already a poiniter 

*/