#include <stdio.h>
#include <stdlib.h>

int pre[50];

void PretoPost(int l, int u){
	if(l<u){
	int i,pos=0;
	 int a=pre[l];
	 for(i=l+1;i<=u;i++){	
	 	if(pre[i]< a){
	 		pos++;
	 	}
	 }
	 PretoPost(l+1,l+pos);
	 PretoPost(l+pos+1,u);
	 printf("%d\t",pre[l]);
	}
	else if(l==u)
		printf("%d\t",pre[l]);
}

 int main()
 {

  int n,i;
  printf("\nenter no of nodes");
  scanf("%d",&n);
  printf("enter the pre-ordered list:");
  for(i=0;i<n;i++){
    scanf("%d",&pre[i]);
  }

  PretoPost(0,n-1);
 }