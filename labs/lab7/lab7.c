#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <stdio.h>

/*Structs
typdef to call by defined name
Structs are a user defined data
ALlows you to group data together 

Pointer to a struct use a ->
or (*student).gpa

if student is not on the heap we
can directly call the value with Student.gpa

Struct Student { <- this is the memory address
    float gpa; <- these guys are offsets
    char *name;
    int id_num;
};




*/
#define MAX_EVENTS 100
typedef struct 
{
    int month;
    int day; 
    int year; 
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
    char title[100];
//  This is good for dyanamic memory title sizes
//  char *title;
//  int title_size;

    char location[100];

}Event;

void printEvent(Event *e);

int displayEventsAtDate(Event **data, int size, int year, int month, int day);
int displayEventsAtLocation(Event **date, int size, char *location);

int main() {
    // Parse the events into Event struct
    Event *data[MAX_EVENTS]; 
    // this is a array of pointers to a Event

    FILE *f = fopen("events.txt", "r");

    size_t size = 1024;
    char *buffer = malloc(size * sizeof(char));

    // loop through each line in the file
    int linecount = 0;

    while (getline(&buffer, &size, f) > 0)
    {       
        data[linecount] = (Event *)malloc(sizeof(Event));
    //  ^^^ pointer at linecount point to a generic pointer into a Event pointer
    //  This will fill the array with Event pointers (Eventt *)
     
        // %99[^!|] match everything that is not the pipe up to 99 chars

        sscanf(buffer, "%d/%d/%d|%d:%d|%d:%d|%99[^!|]|%99[^\n]", 
            &(data[linecount]->month),
            &(data[linecount]->day),
            &(data[linecount]->year),
            &(data[linecount]->startHour),
            &(data[linecount]->startMinute),
            &(data[linecount]->endHour),
            &(data[linecount]->endMinute),
            &(data[linecount]->location) );
        

            // parse all our events into Event structs


        linecount++;
        if (linecount == MAX_EVENTS)
        {
            break;
        }
    }

    free(buffer);
    // free everything in data
    for (int i = 0; i < MAX_EVENTS; i++)
    {
        free(data[i]);
    }

    
}

void printEvent(Event *e)
{
    printf("%s is happening at %s, from %d:%d, on %d/%d/%d",
            (*e).title, (*e).location,
            (*e).startHour, (*e).startMinute,
            (*e).endHour, (*e).endMinute,
            (*e).month, (*e).day, (*e).year);

}
                     // **data is a array of pointers, to point at specific index at pointer array use **        
int displayEventsAtDate(Event **data, int size, int year, int month, int day)
{
    int count = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (data[i]->year == year && (*data[i]).month == month && (*data[i]).day == day)
        {
            printEvent(data[i]);
            count++;
        }
    }
};
int displayEventsAtLocation(Event **date, int size, char *location);