#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node *next;
  struct node *prev;
};

struct deque {
  struct node *head;
  struct node *tail;
  int size;
};

struct deque *create_deque();
void add_to_front(struct deque *d, int n);
void add_to_back(struct deque *d, int n);
int remove_from_front(struct deque *d);
int remove_from_back(struct deque *d);

struct deque *create_deque(){
  struct deque *d;
  
  d = malloc(sizeof(struct deque));
  if (d == NULL) {
    perror("Could not allocate memory for deque");
    exit(1);
  }
  // Create sentinel node
  struct node *n = malloc(sizeof(struct node));
  if (n == NULL) {
    perror("Could not allocate memory for sentinel node");
    exit(1);
  }
  n->val = -1;
  n->next = NULL;
  n->prev = NULL;
  d->head = n;
  d->tail = n;
  d->size = 0;
  return d;
}

void add_to_front(struct deque *d, int n) {
  struct node *new = malloc(sizeof(struct node));
  if (new == NULL) {
    perror("Could not allocate memory for new node");
    exit(1);
  }
  new->val = n;
  new->next = d->head->next;
  new->prev = d->head;
  if (d->head == d->tail) {
    d->tail = new;
  }
  else {
    d->head->next->prev = new;
  }
  d->head->next = new;
  d->size++;
}

void add_to_back(struct deque *d, int n) {
  struct node *new = malloc(sizeof(struct node));
  if (new == NULL) {
    perror("Could not allocate memory for new node");
    exit(1);
  }
  new->val = n;
  new->next = NULL;
  new->prev = d->tail;
  d->tail->next = new;
  d->tail = new;
  d->size++;
}

int remove_from_front(struct deque *d) {
  int rv;
  struct node *tmp;
  if (d->size > 0) {
    tmp = d->head->next;
    rv = tmp->val;
    if (d->size > 1) {
      d->head->next = tmp->next;
      d->head->next->prev = d->head;
    }
    else {
      d->tail = d->head;
      d->head->next = NULL;
      d->tail->next = NULL;
    }
    d->size--;
    free(tmp);
    return(rv);
  }
  else {
    perror("Attempted to remove from empty list");
    exit(1);
  }
}

int remove_from_back(struct deque *d) {
  int rv;
  struct node *tmp;

  if (d->size > 0) {
    rv = d->tail->val;
    tmp = d->tail;
    d->tail = d->tail->prev;
    d->tail->next = NULL;
    free(tmp);
    d->size--;
    return rv;
  }
  else {
    perror("Attempted to remove from an empty list");
    exit(1);
  }
}

void empty_list(struct deque *d) {
  struct node *n = d->head->next;
  struct node *tmp;
  while (n != NULL) {
    tmp = n;
    n = n->next;
    free(tmp);
  }
  d->head->next = NULL;
  d->tail = d->head;
  d->size = 0;
}

void destroy_list(struct deque *d) {
  empty_list(d);
  free(d->head);
  free(d);
}

int main(){
  struct deque *d = create_deque();

  printf("Queue in Front:\n");
  for (int i = 0; i < 20; i++) {
    add_to_front(d, i * i);
  }
  for (int i = 0; i < 20; i++) {
    printf("%d\n", remove_from_front(d));
  }

  printf("Queue in Back:\n");
  for (int i = 0; i < 20; i++) {
    add_to_back(d, i * i);
  }
  for (int i = 0; i < 20; i++) {
    printf("%d\n", remove_from_back(d));
  }

  printf("Stack Front to Back:\n");
    for (int i = 0; i < 20; i++) {
    add_to_front(d, i * i);
  }
  for (int i = 0; i < 20; i++) {
    printf("%d\n", remove_from_back(d));
  }

  printf("Empty List:\n");
  for (int i = 0; i < 20; i++) {
    add_to_back(d, i * i);
  }
  empty_list(d);

  printf("Stack Back to Front:\n");
  for (int i = 0; i < 20; i++) {
    add_to_back(d, i * i);
  }
  for (int i = 0; i < 20; i++) {
    printf("%d\n", remove_from_front(d));
  }

  printf("Empty List:\n");
  for (int i = 0; i < 20; i++) {
    add_to_back(d, i * i);
  }
  empty_list(d);

  destroy_list(d);
  
  exit(1);
}
