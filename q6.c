#include <stdio.h>
#include <stdlib.h>



void PretoPost(int pre[],int n){

int i,j,left=0,right=0;
int post[n];
for(i=1;i<n;i++){
    if(pre[i]<pre[0])
      left++;
    else
      right++;
}
j=0;
int k=0;
for(i=1;i<n;i++){
    if(pre[i]<pre[0]){
        post[j++]=pre[i];
    }
    else if(pre[i]>pre[0]){
        post[left+k++]=pre[i];
    }
 }

  post[left+right]= pre[0];
  
  printf("%d",left);
  printf("\n%d",right);
  printf("\n----------");
  for(i=0;i<n;i++)
    printf("%d\t",post[i]);
}

 int main()
 {

  int n,i;
  printf("\nenter no of nodes");
  scanf("%d",&n);
  printf("enter the pre-ordered list:");
  int pre[n];
  for(i=0;i<n;i++){
    scanf("%d",&pre[i]);
  }

  PretoPost(pre,n);
 }