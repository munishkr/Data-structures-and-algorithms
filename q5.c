#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
	int data;
	struct node *leftchild;
	struct node *rightchild;;
};

struct node *root = NULL;

//function to insert a node

void insert(int data){
	struct node *tempnode=(struct node*)malloc(sizeof(struct node));
	struct node *current;
	struct node *parent;

	tempnode->data=data;
	tempnode->leftchild=NULL;
	tempnode->rightchild=NULL;

	//if the tree is empty create the root node
	if(root == NULL){
		root=tempnode;
	}	
	else{
		current = root;
		parent = NULL;

		while(1){
			 parent=current;

			 //go to left half
			 if(data < parent-> data){
			 	current =current->leftchild;

			 	//insert to the left
			 	if(current == NULL){
			 		parent->leftchild=tempnode;
			 	 	return;
			 	 }

			 }

			 //goto the right half
			 else{
			 	current = current->rightchild;

			 	//insert the node
			 	if(current == NULL){
			 		parent->rightchild=tempnode;
			 	 	return;
			 	 }
			 }
		}

	}
}

int k=0;
int allnodes[7];
//in-order traversal
void inorder(struct node* root){
	if(root != NULL){
		inorder(root->leftchild);
		allnodes[k]=root->data;
		k++;
		inorder(root->rightchild);
		
	}
}

int main()
{
	  int i,x,n,min[7];
   int array[7] = { 27, 14, 35, 10, 19, 31, 42 };
   
   for(i=0;i<7;i++)
      insert(array[i]);

  printf("\nenter the node whose closest is to be searched:");
  scanf("%d",&n);

inorder(root);
  for(i=0;i<7;i++)
  	min[i]=abs(n-allnodes[i]);

int minval=999999;
  for(i=0;i<7;i++){
  	if(min[i]< minval){
  		minval=min[i];
  		x=i;
  	}
  }
  
printf("closest node is :%d",allnodes[x]);
  
}