#include <stdio.h>

int main(){
	int n;
	printf("Enter the number of disks: ");
	scanf("%d\n",&n);
	char source='A',dest='C',spare='B';
	/*Recursive function to calculate the number of steps*/
	diskmove(n,source, dest, spare){
		if (n=0)
		 exit(1);
		else if(n==1){
			printf("\n Move disk 1 from peg %c to peg %c",source,dest);
		}
		else{
			diskmove(n-1,source,dest,spare);
			printf("Move disk %d from peg %c to peg %c",n,source,dest );
			diskmove(n-1,spare,dest,source);
		}
		
	}

}