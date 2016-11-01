#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "stack_functions.h"
#include "list_functions.h"
#include "queue_functions.h"

void stackbyqueue();
/*fucntion to check if the input string is palindrome or not*/
int palindrome()
{
  int n,i;
  char string[20];
  initialize();
  printf("enter the string to be checked to be palindrome: \n");
  scanf("%s",string);

  n=strlen(string);
  for(i=0;i<n;i++){
    push(string[i]);
  }
  for(i=0;i<n;i++){
    if(pop()!=string[i]){
      printf("string is not palindrome\n");
      return 0;
    }
  }
  printf("The string is palindrome\n");
  return 0;
}

int pushcost(int x)
{
  int i,l;
  qnode *t;
  create1();
  create();
  enqueue1(x);
  for(i=0;i<10;i++)
    enqueue(i);
  for(i=0;i<10;i++){
    l=deq();
    enqueue1(l);
  }
  t = front;
  front =front2;
  front2 = t;
  t=rear;
  rear=rear2;
  rear2=t;
int m,n;
  for(i=0;i<10;i++)
  {
    m=deq();
    printf("%d \n",m);
  }

  return 0;
}

int main()
{
  int ch;
  printf("Enter 1 for ques1, 2 for ques2 and 3 for ques3 \n");
  scanf("%d",&ch);
  switch(ch){
    case 1:
      palindrome();
      break;
    case 2:
    {
      struct node* head = NULL; //starting with empty list
       pushlist(&head, 23);
       pushlist(&head, 45);
       pushlist(&head, 16);
       pushlist(&head, 37);

       printList(head);
       reverselist(&head);
       printf("\n Reversed Linked list \n");
       printList(head);
       getchar();
       break;
  }
    case 3:{
      int a;
      printf("enter the value to be pushed ");
      scanf("%d",&a);
      pushcost(a);
      break;
    }
    default:
      printf("wrong choice");
  }
  return 0;
}
