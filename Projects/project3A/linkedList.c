#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
    struct node *prev;

}node; 


typedef struct deque {
    node *head;
    node *tail;
    int size;
} deque;

struct deque *create_deque();


deque *create_deque(deque *deque)
{
    struct deque *d = malloc(sizeof(deque) * (*deque).size);

}

// check if head is emtpy
// cehck if head is full 

void add_to_back(deque *d, int n)
{
    int tail; 
    if (d->tail->next == NULL)   //((*d).tail->next == NULL)
    {
        tail = d->tail->next
        d->head->next == tail
    }


}
void add_to_front(deque *d, int n);
int remove_from_front(deque *d);
int remove_from_back(deque *d); 


a -> b -> c -> NULL

a -> b -> c -> d -> NULL