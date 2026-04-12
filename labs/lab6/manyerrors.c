#include <stdio.h>
#include <stdlib.h>

void pointer_error(){
    // int *p; this is wrong because it initliazes a random pointer
    // to fix this we initalize a variable a and set *p to the value of a
    int a;
    int *p = &a;
    *p = 5;
    printf("p = %d\n", *p);
    p++;
}

double * mem_leak(){
    double *arr = malloc(5 * sizeof(double)); return arr;
}

void nullptr_access_err(char c){
    if (c==0) {
        printf("c is the null character\n");
    }
    else {
        printf("c is %c\n",c);
    }
}

int main(int argc, char **argv){
    double *arr;
    arr = mem_leak();
    free(arr);

    arr = mem_leak();
     
   
    pointer_error();

    free(arr);
    nullptr_access_err(argv[1][0]);
    
    if (argc < 1) 
    { 
        nullptr_access_err(argv[1][0]);
    }
    else {nullptr_access_err(argv[1][0]);}
    
    }

