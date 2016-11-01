#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Graph
{
 int v;
 struct array * a;
};

struct array
{
 struct node * head;
};

struct node
{
 int dest;
 int weight;
 struct node * next;
};

struct Graph * creategraph(int v)
{
 struct Graph * temp=malloc(sizeof(struct Graph));
 temp->v=v;
 temp->a=malloc(v*sizeof(struct array));
 for(int i=0;i<v;i++)
	 temp->a[i].head=NULL;
 return temp;
}

struct node * newnode(int dest,int weight)
{
 struct node * temp=malloc(sizeof(struct node));
 temp->dest=dest;
 temp->weight=weight;
 temp->next=NULL;
 return temp;
}

void undirectededge(struct Graph * t,int src,int dest,int weight)
{
 struct node * temp=(struct node *)newnode(dest,weight);
 temp->next=t->a[src].head;
 t->a[src].head=temp;
 
 temp=(struct node *)newnode(src,weight);
 temp->next=t->a[dest].head;
 t->a[dest].head=temp;
}

void directededge(struct Graph * t,int src,int dest,int weight)
{
 struct node * temp=(struct node *)newnode(dest,weight);
 temp->next=t->a[src].head;
 t->a[src].head=temp;
}

void printGraph(struct Graph * t,int v)
{
 struct node * temp=NULL;
 for(int i=0;i<v;i++)
 {
  temp=t->a[i].head;
  printf("vertex %d is connected with ",i);
  while(temp!=NULL)
  {
   printf("->%d ",temp->dest);
   temp=temp->next;
  }
  printf("\n");
 }
}

void deletedge(struct Graph * g, int src, int dest)
{
 struct node * temp = g->a[src].head;
 struct node * po = NULL;
 if(temp->dest == dest)
 {
 	g->a[src].head=temp->next;
 	free(temp);
 	return;
 }
 while(temp!=NULL)
 {
 	if(temp->next!=NULL)
 	{
	 	po=temp->next;	
	 	if(po->dest==dest)
	 	{
	 	 	temp->next=po->next;
	 	 	free(po);
	 	}
	 	temp=temp->next;
	}
	else return;
 }
}

int degree(struct Graph * g,int ver)
{
 struct node * temp = g->a[ver].head;
 int a=0;
 while(temp!=NULL)
 {
 	a+=1;
 	temp=temp->next;
 }
 return a;
}
