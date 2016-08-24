#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <glib.h>
void moveprinter(char s,char d,int des);										//pre-declaration of the functions used in the code
int itrmain();
void move(GSList **source,GSList **dest,char s,char d);

/*Recursive function to compute the steps*/
void diskmove(int n,char source1, char dest1, char spare){
	if(n==1)
		printf("\n Move disk 1 from peg %c to peg %c\n",source1,dest1);
	else {

			diskmove(n-1,source1,spare,dest1);
			printf("\nMove disk %d from peg %c to peg %c\n",n,source1,dest1 );	//recursion to print the steps involved
			diskmove(n-1,spare,dest1,source1);
	}
}
/*Iterative method to compute the steps */					
	int itrmain(){																//function to call all the functions for iterative method 
	GSList *source=NULL,*dest=NULL,*aux=NULL,**psource,**pdest,**paux;
	psource=&source;
	pdest=&dest;
	paux=&aux;
	int n;
	printf("enter the number of disk \n");
	scanf("%d",&n);
	int total_moves,i;
	char s='A',d='C',a='B';
	total_moves=pow(2,n)-1;   
	for(i=n;i>0;i--)
	source=g_slist_prepend (source,GINT_TO_POINTER(i));							//fucntioning of the basic algorithm
	for(i=1;i<=total_moves;i++){
		if(i%3==1)
			move(psource,pdest,'s','d');
        else if(i%3==2)
            move(psource,paux,'s','a');
        else if(i%3==0)
        	move(paux,pdest,'a','d');
	}  
}	
	void print(char s,char d,int des){										 	//printing the steps
		printf("Move the disk %d from \'%c\' to \'%c\'\n",des,s,d);
	}
	void move(GSList **source,GSList **dest,char s,char d){						//function to move the disks between three pegs
		int src,des;	
		if(*source==NULL){														//if the peg A is intially empty
			src=INT_MIN;
		}
		else{
			src=GPOINTER_TO_INT((*source)->data);
	    	*source=g_slist_remove(*source,(*source)->data);					//poping out the value in source
		}
		if((*dest)==NULL)					
			des=INT_MIN;
		else{
			des=GPOINTER_TO_INT((*dest)->data);									//poping out the value in destination
			*dest=g_slist_remove(*dest,(*dest)->data);	
		}
		if(src==INT_MIN){														
			*source=g_slist_prepend(*source,GINT_TO_POINTER(des));
			print(d,s,des);														//adding the disks and printing the steps into source
		}
		else if(des==INT_MIN){
			*dest=g_slist_prepend(*dest,GINT_TO_POINTER(src));
			print(s,d,src);
		}
		else if(src>des){
			*source=g_slist_prepend(*source,GINT_TO_POINTER(src));				
			*source=g_slist_prepend(*source,GINT_TO_POINTER(des));
			print(d,s,des);
		}
		else{
			*dest=g_slist_prepend(*dest,GINT_TO_POINTER(des));
			*dest=g_slist_prepend(*dest,GINT_TO_POINTER(src));
			print(s,d,src);
		}
	}

/*main function containing choices for both the methods*/
int main(){
	int t,c;
	printf("Enter the number of disks: ");
	scanf("%d",&t);
	printf("\nEnter 1 for recursive method and 2 for iterative method:");
	scanf("%d",&c);
	switch(c){																	//switch case to have choice to solve via diff methods
		case 1:
		diskmove(t,'A','C','B');
		break;
		case 2:
		itrmain();
		break;
		default:
		printf("wrong choice");
	}
	return 0;
}

