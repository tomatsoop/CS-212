/*
The Hello World Program in C 

*/

/* 
C math and I/O libaries*/

#include <math.h>
#include <stdio.h>

/*Main function defintion: */
int main(void) {
    //Statements end in a semicolon
    printf("Hello World\n");
    printf("sqrt(4) is %f\n", sqrt(4));

    return 0;
    // main returns value 0

}

/*
In C, libaries are included using #include. All include statements
appear at the top of the porgram, outside of function bodies

In C, blocks (for example, function, loops, and coditional bodies)
start with { and end with }

The main function:
In C, int main(void) {} defines the main function. The main function 
returns a  value of type int, which is C's name for specifing the 
signed integer type (signed interger are values like -3, 0, 1234). 

The main fuction returns the int value 0 to signify running to completion
without error. 
The void means it doesnt expect to receive a parameter. 

Statements:
In C, each statement ends with a semicolon ; In C, statemetns must be 
within the body of some fuction (in main in this example)

Output:
In C, the printf function prints a formatted string. Values for the 
placeholders in teh format string are additional arguments seperated
by commas (for exmaple, the valuue of sqrt(4) will be printed in 
place of the %f placeholder in the format string). 

%f is a placeholder for formatted string

Indentation: 
C's printf function doesn't automatically print a newline character
at the end. As a result, C programmers need to explicitly specify
a new line character (\n) int eh format string when a new line is 
desiired in the output

main function: 
A C program must have a function named main, and its return type 
must beb int. This means that the main functoin returns a signed 
interger type value. 

The C main function has a explicit return statement to return an int
value (by convention, main should return 0 if the main functioin is 
successfully excuted without errors)

A Python program needs to include an explicit call to its main function
to run it when the program executes. In C, its main function is 
automatically called when teh C program executes. 

*/


/* 1.1.1
To run a C program, it must be first be translated into a form 
that a computer system can directly execute. 

A C compiler is a program that translates C source code into
a binary executable form that the computer hardware can directly 
execute. A binary executable consists of a series of 0s and 1s
in a well-defined format that a computer can run.

For example, to run the C program hello.c on a Unix system, the C 
code must first be compiled by a C compiler (for example, the GNU 
compiler, GCC) that produces a binary executable (by default named 
a.out) The binary executable versiosn of the program can be then be run 
directly on the system

$ gcc hello.c
$ ./a.out


In general, the following seuqence describes the nessesary steps for editing, 
compiling, running a C program on a Unix system:

1. Using a text editory (for  example,vim), write and save your C source
code program in a file

$ vim hello.c

2. Compile the source to an executable form, and tthen run it. 
The most basic symtax for compiling with gcc is:

$ gcc <input_source_file>

If compilation yields no errors, the compiler creates a binary executable
file named a.out
The compiler also allows you to specify the name of the binary executable 
file t generate using the -o flag:

$ gcc -o <output_executable_file> <input_source_file> 

For example, this command instructs gcc to compile hello.c into an executable
file named hello: 
$ gcc -o hello hello.c

We can invoke the executable program using ./hello:
$ ./hello

Any cahnges made in the C source code (the hello.c file) must  be recompiled 
with gcc to produce a new version of hello. If the compiler detects any errors
during compilationo, the ./hello file won't be created/recreated (but beware,
an older version of the file from a previous successful compliation may still
exsists)

Often when compiling with cc, you want to include several command line options. 
For example, these options enable more compiler warnings and build a binary
executable with extra debugging information

$gcc -Wall -g -o hello hello.c
Because the gcc command line can be ong, frequently the make utility is used 
to simplify compiling C progams and for cleaning up files created by gcc 

1.1.2 Variables and C Numerical Types
In C, all varibales must be declared before they can be used. 
To declare a variable, use the following syntax:
    type_name variable_name;

A variable ecan have onlu a single type. The basic C types include
char, int, float and double

By convention, C variables should be declared at the beginning of thier scope
(at the top of a { } block), before any C statements in that scope

Example:
{
1. Define variables in this block's scope at the top of the block

int x; // declares x to be an int type variable and allocates space for it

int i, j, k; // can define multiple variables of the same type like this

char letter; // a char stores a single byte integer value
             // it is often used to store a single ASCII character
             // value (The ASCII numeric encoding of a character)
             // a char in C is different type than a string in c

float winpct; // winpct is declared to be a float type
double pi; // The double type is more preciese than a float (16 decimal values)

// 2. After defining all variables, you can use them in C statements
x = 7;
k = x + 2;

letter = 'A'; // A single quote is used for single character
letter = letter + 1; // letter now stores 'B' (ASCII value one more than 'A')

pi = 3.11415926;

winpct = 11/2.0; // wincpct gets 5.5, winpct is a  float type
j = 11/2; // j gets 5: int division truncates after the decimal
x = k % 2; // % is the C's mod operator, so x gets 9 mod 2 = 1


C types
The C char type stores a numeric value. However, its often used to store
the value of an ASCII character. A character literal value is specified in C 
as a single charcter between single quotes

C doesn't support a string type, however it can support a way of expressing 
string literal values in programs: A literal string is any sequence of charcters 
between double quotes
Often used in in fomrat string arugment to printf
printf("This is a C string\n")

In C, a string and a char type are different
'h' // can evaluate as the ASCII character 104 however
"h" // dos not evalute to the vlaue 104 and is a string literal value

char 1 byte Stores intergers ie char x;
short 2 bytes Stores signed intergers short x;
int 4 bytes Stores signed intergers int x;
long 4 or 8 bytes Signed intergers long x;
long long 8 bytes Stoes Signed integers long long x;
float 4 bytes stores signed real numbers float ;
double 8 bytes Stores signed real numbers double x; 

The exact numebr of bytes for each of teh C types may vary  from 
one architecture to the next. YOu can print the exact size on a given 
using C's sizeof operator, which takes the name of a type as an argument
and  evalutes the number of bytes usedto store that type

printf("number of bytes in an int: %lu\n", sizeof(int));
printf("number of bytes  in a  short: %lu\n", sizeof(short));

The size of operator evaluates to an unsigned long value, so in the call
to printf, use the placeholder %lu to print its value

Arthmetic Operators
If both operands are int types, the divide operator performs 
integer division, and returns a int
If one or both of the operands are float (or double) / performs real 
division and evaluates to a float result.

+=, ==, /=, %= are all fiar game

++ allos you to incremet by one so does --
variable++; // ie x++ assigns to the vlaue of x + 1

Post and Pre increment
++variable : incremets x first, then uses its value
varibale ++ : uses x's value first, then increment

x = 6;
y = ++x + 2; // y is assinged 9 [(x+1)+2]

x = 6
y = x++ + 2; // y is assigned 8 
y gets assigned 6+2 then x is incremented by one after that

generally, avoid writing like this instead
x++;
y = x + 1;



1.2 Input/Output system
printf function prints values to the termanl
scanf function reads in values entered by user

These are in the libary when calling #include <stdio.h>
The format string often contains formatting specifiers, such as 
special characters that will print tabs (\t) or new lines (\n)
Place holders consist of % followed by a type specifier for example %d 
represents a place holder for a interger value. 

ex 
printf("Name: %S\n", "Vijay")

%g : place holder for a float (or double  value)
%d : place holder for a decimal value (int, short, char)
%s : place holder for a string value

// Example printing a char value as its decimal representation (%d)
// and as the ASCII character that its valuee encodes (%c)

char ch;
ch = 'A';
printf("ch value is %d which is the ASCII value of %c\n", ch, ch)

output:
ch value is 65 which is the ASCII value of A




scanf takes user input and assigns that to a variable as specified

scanf takes the format string that specifies the number and the types of 
vallues to read in (for example %d species one int value). The scanf function
skips over leading and  trailing whitespaces as it reads in a numerical value,
so its format strong only needs to contain a sequence of formatting placeholderss, 
usually with no whitepaces or other formatting characters between placeholders 
in its format string. 
THe arugemnts for the palceholders in teh format string specify the locaions
of program varibales into which teh values read in will be stores

prefiing the name of a variable  witht eh & operator porduces a location
of that variable  in teh progams memory, the memory adderss of thee variable 

ex: 
int x;
float pi;

scanf("%d%g", &x, %pi)
when putting data from a porgram via scanf, indivial numeric imput values
must be seperated by at least  one white space character
}


1.3 Conditonals and Looops

Python uses indentation to indicate body statements whereas
C uses curly braces

int main(void) { 
    int num1, num2;

    if (num1> num2){
    printf("Blah blah blah");
    num2 = num1;

    } else{
     printf(("Yada Yada Yada"))
    num1 = num2;
    }

    return 0 

}

if (<boolean expression>) {
    <true body>
}

or 

if (<boolean expression>) {
    <true body>
}
else {
    <false body>
}

if else chain:
if (<boolean expression>) {
    <true body>
}
else if {
    <true1 body>
}
else if {
    <true2 body>
}
else {
    <false body>
}


Boolean values in C: 
C doesnt provide a boolean type with true or false values
INstead interger values evaluate to true or fale when used
in conditional statements. When used in conditional expressions, 
any interger expression is that: 

zero (0) evalutes to false
nonzero (any positive or negative value) evalutes to true

equality (==) and inequaliy (!=)

C's logical operators take interger "Boolean" operands and evaluate 
to either zero (False) or non zero (true) 
Logical negation (!)

logial and (&&) : stops evaluating at the first false expression
logical or (||): stops evaluting at teh first true expression
Both && and || are short cirtue logical operators

C's Short circut logical operators evaluation stops evaluating a 
logical expression as soon as teh result is known. For example, 
if the first operand to a logcal and  (&&) expression stops evaluating
as soon as the result is known.

if ( (x > 10) && (y >= x)) {
    printf("y and x are both larger than 10\n");
    x = 13;
}
else if ((-x) == 10) || (y > x)){
    printf("y might be bigger than x\n");
    x = y * x;
}
else {
    printf("I have no idea what the relationship between x and y is\n");
}


. means current directory
.. means parent directory
/ means path seperator or root directory
~ means home directory

# means comment and it is ignored
; means command separator ie cd /; ls

&& means AND operator, runs second command only if first succeeds
ie mkdir test && cd test

` OR operator 
& Runs in background 

` Pipe ie `ls

Redirection: 
> Redirect output (overwrite) 
ie ls > files.txt 

>> Redicrects output (append) Add to end of file
ie echo hi >> log.txt 

< redirects input sort < data.txt Takes input from file

2> redirect error gcc file.c 2> errors.txt Saves only error messages

&> Rerdirect both output and errors command &> output.txt saves everything

$ Variable or substitution echo $HOME Prints values of HOME variable

${} Varibale expansion echo ${USER} used for clarity or complex expressions

* Wildcard (Any characters) ls *.txt Matchs all .txt files

? Single-character wildcard ls.c Matches one character ie a.c, b.c 

[] Character set ls [abc].txt

{} Brace expansion echo {1..5} expands to 1 2 3 4 5

" Double quotes echo "Hello $USER" expands the varibles inside

' Single quotes echo '$USER' Treats $USER as plain text

\ Escape character echo \"hi\" Prints special symbols literally

sudo Run as super user sudo apt update Execute with admin rights

~user Another user's home ie cd ~bob Go to Bob's home directory

In Linux, every process has three default file descriptors:

0: Standard Input (stdin)

1: Standard Output (stdout)

2: Standard Error (stderr)


Given that 

$ ./foo >/dev/null

$ ./foo 2>/dev/null
Guveb that 

*/




/*
Typical unix tools

./program 
Reads from stdin, writes stdout

./program file1 file2 file3
Runs program on the 3 files, write to stdout

./program



Standard inout.output.error
Every running pogram has (by default) 3 open "files" 
referrred to by their file discripitor


Standard output
Normal outpput goes to stdout (file descripter 1)

Error messages traditionally go to stderrr (file descriptor 2)
Everything that goes to standard error also go to the screen


Redirection
> - Standard output (stdout) with truncattion (overwerites and erases)
>> - Redirects stdout, but append
< - Redirects input (stdin) to come from a file
| - connects stdout from left to stdin on right 
ls | wc

2> redirect standdrd error (stderr)

2>&11 - Redirects stderr to stdout

$ echo "hi" >output.txt

pipes allow you to chain together things
# look more into pipes 

In Unix, everything is a file
Files on the file system
Network sockets (for communicating with remote computers, web browers, etc)
Terminal I/O
A bunch of special files
/dev/null - writes are ignored, reads returns end of file (EOF)

/dev/zero - writes are ignored, reads returns arbitrarily many 0 bytes

/dev/urandom - Reads return arbitrarily many (pseudo) random bytes



Linux Permissions:
Reading permissions
ls -l

drwxr-x--- 6 rhoyle faculty 24 Dec 18 18:59 hw5
d means directory
r read
w write
x execute
- no privilages

first three are the owners, second three are group, last 3 is everybody else
-/---/---/---
d/rwx/rwx/rwx 
1: Owner
2: Group
3: Everyone else


UNIX PERMISSION FILES
u - user
g - group
o - others
a - all 

use chmod to change
$ chmod g-rwx hello.c
Change group permissions to rwx

Translaingg R/W/X Octal numbers
7: 111 Full permission
6: 110 Read and write
5: 101 Read and execute
4: 100 Read only
3: 011 Write and execute
2: 010 write only
1: 001 Execute only
0: 000 None

Permissions
-chown changes owner (and group) of files/directories
-chgrp chagne group files/directires
-chmod change permissions for files/directories


Look into Unix Scripts 
Shell scripts can be written in VS code to create a file
that contains a bunch of Unix commands
Give the file execute permissions 

------------------------------
Shell Script
#!/bin/bash << tells unix which program is going to run this
#bin/bin/bash
------- ^ 
This specific line tells the script what will be running it

touch cs212demo
echo "Testing123" > cs212demo
mkdir this_is_a_directory

chmod +x shellscript.sh 
----this makes it executable
----shellscript.sh is the file name

./shell_script.sh
^ thhis part works because the #!/bin/bin tells the program
where to go already, so its saying current directory, find 
this program and run it 
$ cat cs212demo 
runs the file


passing in arguments 
$# == blah blah
$1 == foo
$2 == foo1
















linux:
$ ps 
$ ps - ax <- all the processes that are currecntly running

$ ps - ax | grep bash 
grep <- takes standard input and returns every line that has whatever charracter 
you give it

$ ps - ax | grep bash 
Retunrs all the computer activites running as bash




$ echo 'Hello' > output
ls
this crerates a file called output that has Hello

$ echo 'Hello again' > output
$ cat output 
Hello again




gcc compiler  options
-E preprocessor only
-S compile only (no assembly or linking)

-c compile/assemble

-o foo specify output files as foo

-lxxx use libary named libxxx..so

-g used for debugging

-std=c99 use C99 Standards

-pedantic be pedantic

-Wall Turn on "all" warning

-Wextra turn on extra warnings

-Werror make

*/