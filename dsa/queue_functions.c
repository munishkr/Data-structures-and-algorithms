#include <stdio.h>
#include <stdlib.h>

typedef struct nodequeue{
	int value;
	struct nodequeue *ptr;
}qnode;
qnode *front,*front2,*rear,*rear2,*temp,*front1;


   int count=0;
   //creating an empty queue
   void create(){
	front =rear=NULL;
   }

   void create1(){
 front2 =rear2=NULL;
   }

int qisEmpty(){
  if(front==NULL)
  return 1;
  else
  return 0;
}

   //adding data to the queue(enqueing)
   void enqueue(int data){
	  if (rear == NULL){
		rear = (struct nodequeue *)malloc(1*sizeof(struct nodequeue));
      	        rear->ptr = NULL;
        	rear->value = data;
        	front = rear;
    	  }
         else{
		temp=(struct nodequeue *)malloc(1*sizeof(struct nodequeue));
        	rear->ptr = temp;
        	temp->value = data;
       	        temp->ptr = NULL;

	        rear = temp;
         }
    	count++;
    }

    // Dequeing the queue
  int deq(){
	front1 = front;
	if (front1 == NULL){
		printf("\n the queue is empty");
        	return -1;
    	}
    	else if (front1->ptr != NULL){
		front1 = front1->ptr;
		int val=front->value;

            	free(front);
                front = front1;
		return(val);

        }
        else{
		int val=front->value;

            	free(front);
            	front = NULL;
            	rear = NULL;
		return(val);
        }
        count--;
     }

     // Returns the front element of queue
     int frontelement(){
		if ((front != NULL) && (rear != NULL))
        		return(front->value);
    		else
			return 0;
     }

     //getting the size of the queue
     int queuesize(){
	      return(count);
      }

    void enqueue1(int data){
       if (rear2 == NULL){
       rear2 = (struct nodequeue *)malloc(1*sizeof(struct nodequeue));
                   rear2->ptr = NULL;
             rear2->value = data;
             front2 = rear2;
           }
            else{
       temp=(struct nodequeue *)malloc(1*sizeof(struct nodequeue));
             rear2->ptr = temp;
             temp->value = data;
                   temp->ptr = NULL;

             rear2 = temp;
            }
         count++;
       }


    int deq1(){
     front1 = front2;
     if (front1 == NULL){
       printf("\n the queue is empty");
             return -1;
         }
         else if (front1->ptr != NULL){
       front1 = front1->ptr;
       int val=front->value;

                 free(front2);
                   front2 = front1;
       return(val);

           }
           else{
       int val=front2->value;

                 free(front2);
                 front2 = NULL;
                 rear2 = NULL;
       return(val);
           }
           count--;
        }
