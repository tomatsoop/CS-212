/*
CS 212 - Project2H 
Sabrina Zhang
References: 
How to use gettimeofday:
https://stackoverflow.com/questions/2125219/how-to-get-the-running-of-time-of-my-program-with-gettimeofday

(4) Main function loops through each N in the array for length 8
and calclualtes the time by storing start and end time in a struct address,
calculates the total time, and prints it.

(5)
Time of processing starts out fast and slows down linearly as 
array size increases. 

(6) 
Comparing it to (5), it runs faster than (5) as array size increases 
2h_out runs faster than than (5) and (6) 
(6) is slightly better than (5) with smaller arrays and the time 
exponentially increases as array size increases
2h_out processing time is not linear but does better than (5) and (6)
*/

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
int *AllocateArray(int N)
{
    /* Allocate an array with N integers.    
     * The value of each element of the array should be a random
     * number between 0 and 10N.    
     * Hint: use the rand() function and a modulo operator. 
     */
    int *array = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        int num = 0;
        int random = rand();
        if (random > 10*N)
        {
            num = random % 10;
            array[i] = num;
        }
        else
        {
            array[i] = num;
        }

    }
    return array;

}

void SortArray(int N, int *A)
{
    /* Hint: pull your code from 2B */
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[i])
            {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}

void DeallocateArray(int *A)
{
    free(A);
}

int main()
{
    int sizes[8] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000 };

/* For fun:
 *  int sizes[11] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000,
 *                    256000, 512000, 1024000 }; 
 */

    for (int i = 0 ; i < 8 ; i++)
    {
        double alloc_time = 0., sort_time = 0., dealloc_time = 0.;
        struct timeval startTime;
        struct timeval endTime;

        /* Call the three functions in a sequence. Also use
         * gettimeofday calls surrounding each function and set the 
         * corresponding variable (alloc_time, sort_time, dealloc_time).
         */
        gettimeofday(&startTime, NULL);
        int *array = AllocateArray(sizes[i]);
        gettimeofday(&endTime, NULL);
        alloc_time = (endTime.tv_sec - startTime.tv_sec) + 
                        ((endTime.tv_usec - startTime.tv_usec)/1000000.0);

        gettimeofday(&startTime, NULL);
        SortArray(sizes[i], array);
        gettimeofday(&endTime, NULL);
        sort_time = (endTime.tv_sec - startTime.tv_sec) + 
                        ((endTime.tv_usec - startTime.tv_usec)/1000000.0);
       
        gettimeofday(&startTime, NULL);
        DeallocateArray(array);
        gettimeofday(&endTime, NULL);
        dealloc_time = (endTime.tv_sec - startTime.tv_sec) + 
                        ((endTime.tv_usec - startTime.tv_usec)/1000000.0);
                       
        printf("Timings for array of size %d\n", sizes[i]);
        printf("\tTime for allocation is %g, time per element = %g\n", alloc_time, alloc_time/sizes[i]);
        printf("\tTime for sort_time is %g, time per element = %g\n", sort_time, sort_time/sizes[i]);
        printf("\tTime for deallocation is %g\n", dealloc_time);
    }
}
