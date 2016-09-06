#include <stdio.h>
#include "function.h"

   int main(){
	int total,token,i;
	
	//getting the inputs for the game
	printf("Enter the number of players =");
	scanf("%d",&total);
	printf("enter the token number =");
	scanf("%d",&token);
	
	//entering data into the queue	
	struct node{
		int value;
		struct node *ptr;
   	}*front,*rear, *temp,*frontnew;
	
	create();
	for(i=0;i<total;i++)
		enqueue(i+1);
	
	//algorithm to implement the hot_potato game
	int winner;
	int c=0,j=0;
	for(i=0;i<total-1;i++){
		while(c<j+token-1){
			int tmp=deq();
			enqueue(tmp);
			c++;
		}
		int rm=deq();
		j=j+token-1;
		j=j%total;
		printf("\nkid removed=%d",rm);
	}		
	printf("winner is %d th kid ",deq());
   }
	
	
