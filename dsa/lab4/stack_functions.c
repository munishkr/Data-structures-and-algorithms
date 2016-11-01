// Program to Implement a Stack using Linked List

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define TRUE 1
#define FALSE 0

// Structure defining Stack data structure
struct Stack {
	int top;
	int array[MAXSIZE];
} st, st1;

/*
   Initializes the top index to -1
 */
void initialize()
{
	st.top = -1;
}

void initialize1()
{
	st1.top = -1;
}

/*
   Checks if Stack is Full or not
 */
int isFull()
{
	if (st.top >= MAXSIZE - 1)
		return TRUE;
	else
		return FALSE;
}

/*
   Checks if Stack is Empty or not
 */
int isEmpty()
{
	if (st.top == -1)
		return TRUE;
	else
		return FALSE;
}

/*
   Adds an element to stack and then increment top index
 */
void push(int num)
{
	if (isFull())
		printf("Stack is Full...\n");
	else {
		st.array[st.top + 1] = num;
		st.top++;
	}
}

/*
   Removes top element from stack and decrement top index
 */
int pop()
{
	if (isEmpty())
		printf("Stack is Empty...\n");
	else {
		st.top = st.top - 1;
		return st.array[st.top + 1];
	}
}
