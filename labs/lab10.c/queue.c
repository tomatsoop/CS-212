#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 100

typedef struct {
	int front;
	int rear;
	int num_items;
	int array[QUEUE_CAPACITY];
} Queue;

Queue* createQueue() {
	Queue * queue = (Queue *)malloc(sizeof(Queue));
	(*queue).front = 0;
	(*queue).rear = 0;
	(*queue).num_items = 0;
	return queue;

}

void enqueue(Queue* queue, int item) {
	(*queue).array[(*queue).rear] = item;
	(*queue).rear = ((*queue).rear + 1) % QUEUE_CAPACITY;
	// if the value exceeds queue capacity it will wrap around
	(*queue).num_items++;
}

int dequeue(Queue* queue) {
	int value = (*queue).array[(*queue).front];
	(*queue).front = ((*queue).front + 1) % QUEUE_CAPACITY;
	(*queue).num_items--;
	return value;

}

int peek(Queue* queue) {
	return (*queue).array[(*queue).front];
}

int main() {
	Queue* queue = createQueue();

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);

	printf("%d dequeued from queue\n", dequeue(queue));
	printf("Front item is %d\n", peek(queue));

	free(queue);
	return 0;
}
