#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack {
	int top;
	unsigned capacity;
	int* array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack* stack,int item)
{
    
	if (isFull(stack))
		printf("stack is full");
	else{
	   
	    
	   stack->array[++stack->top] = item;
	   printf("%d pushed to stack\n", item);
	}
}

// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}

// Driver program to test above functions
int main()
{
	struct Stack* stack = createStack(100);
	do{
	int c;
	int item;
	printf("1. push\n 2.pop\n3.top element\n 4. for exit\n");
	scanf("%d",&c);
	switch(c){
	    case 1 : 
	             
	             printf("enter element");
	             scanf("%d",&item); 
	             push(stack,item);
	             break;
	   
	   case 2 :
	            printf("%d popped from stack\n", pop(stack));
	            break;
	    case 3 :
	            printf("%d",peek(stack));
	            break;
	    case 4 :
	            exit(0);
	    
	    default :
	            printf("enter right no.\n");
	    
	}
  }while(1);
	

	return 0;
}
