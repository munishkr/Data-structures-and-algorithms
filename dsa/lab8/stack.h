#include<stdio.h>
#include<stdlib.h>

struct stack
{
 struct node1 * front;
};

struct node1
{
 int val;
 struct node1 * next;
};

struct stack * create()
{
 struct stack * temp=malloc(sizeof(struct stack));
 temp->front=NULL;
 return temp;
}

void push(int val,struct stack * t)
{
 if(t->front==NULL)
 {
 	struct node1 * temp=malloc(sizeof(struct node1));
 	temp->val=val;
 	temp->next=NULL;
 	t->front=temp;
 }
 else
 {
 	struct node1 * temp=malloc(sizeof(struct node1));
 	temp->val=val;
 	temp->next=t->front;
 	t->front=temp;
 }
}

int pop(struct stack *t)
{
 if(t->front==NULL)
 	return -1;
 else
 {
 	struct node1 * temp=NULL;
 	temp=t->front;
 	t->front=t->front->next;
 	int a=temp->val;
 	free(temp);
 	return (a);
 }
}
 
int isempty(struct stack * t)
{
 if(t->front==NULL)
	return 1;
 else
    	return 0;
}

int peek(struct stack *t)
{
	if(t->front==NULL)
		return -1;
	else 
		return t->front->val;
}

