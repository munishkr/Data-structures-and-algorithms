#include<stdio.h>
#include<stdlib.h>

struct node1
{
 int val;
 struct node1 * next;
};

struct queue
{
 struct node1 * front,*rear;
};

struct queue * createqueue()
{
 struct queue * temp=(struct queue *)malloc(sizeof(struct queue));
 temp->front=temp->rear=NULL;
 return temp;
}

void enqueue(struct queue * t,int val)
{
 if(t->rear==NULL)
 {
 	struct node1 * po=(struct node1 *)malloc(sizeof(struct node1));
 	po->val=val;
 	po->next=NULL;
 	t->front=t->rear=po;
 }
 else
 {
  	struct node1 * po=(struct node1 *)malloc(sizeof(struct node1));
 	po->val=val;
 	po->next=NULL;
 	t->rear->next=po;
 	t->rear=po;
 	
 }
}

int dequeue(struct queue * t)
{
 if(t->front==NULL)
 	return -1;
 else
 {
 	struct node1 * temp=t->front;
 	int a=temp->val;
 	if(temp->next!=NULL)t->front=t->front->next;
 	else t->front=t->rear=NULL;
 	free(temp);
 	return (a);
 }
 if(t->front==NULL)
 	t->rear=NULL;
}

int isempty(struct queue * t)
{
 if(t->front==NULL)
 	return 1;
 else return 0;
}

