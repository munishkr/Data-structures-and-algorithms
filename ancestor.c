#include <stdio.h>
#include <stdlib.h>

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

//algorithm to find the lowest common ancestor

struct node *ancestor(int a, int b,struct node *root){
		
		if(root->data >a && root->data> b)
			ancestor(a,b,root->leftchild);
	
		else if(root->data < a && root->data <b)
			ancestor(a,b,root->rightchild);
		
		else
			return root;
	
	return root;
}


int main(){
	 int n,i,A,B,data,rn;
  	printf("\nenter no of nodes");
  	scanf("%d",&n);

  	printf("\nEnter the nodes in any order\n");
  	for(i=0;i<n;i++){
  		scanf("%d",&data);
  		insert(data);
  	}

  	printf("\nenter the two nodes a and b (a<b)whose lowest ancestor is required\n");
  	scanf("%d%d",&A,&B);

  	printf("\nenter the value of root node");
  	scanf("%d",&rn);

  	struct node * rootrn = rn;
  	struct node *ans=ancestor(A,B,rn);

  	printf("\nLowest common ancestor is: %d",ans->data);
}
