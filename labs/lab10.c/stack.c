#include <stdio.h>
#include <stdlib.h>

#define STACK_CAPACITY 100

typedef struct {
	int top;
	int array[STACK_CAPACITY];
} Stack;

Stack* createStack() {
	// intitalize a stack 
	Stack * stack = (Stack *)malloc(sizeof(Stack));
	stack -> top = 0;
	return stack;
}

void push(Stack* stack, int item) {
	// add to the next empty index 
	// do a for loop 
	stack ->array[stack->top] = item;
	stack->top++;
}

int pop(Stack* stack) {
	// return the last item in a stack that is not null and set to null
	stack ->top--;
	return stack->array[stack->top];
}

int peek(Stack* stack) {
	return stack->array[stack->top - 1];
}

int main() {
	Stack* stack = createStack();
	
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);

	printf("%d popped from stack\n", pop(stack));
	printf("Top item is %d\n", peek(stack));

	free(stack);
	return 0;
}
