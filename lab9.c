#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *leftchild;
	struct node *rightchild;;
};
int flag=0;

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

//function to search a node
struct node* search(int data){
	struct node *current = root;
	printf("Visiting elements");

	while(current->data != data){
		if(current != NULL)
			printf("%d",current->data);

		//goto the left half of the tree
		 if(current->data >data)
		 	current=current->leftchild;
		 //goto the right half of the tree
		 else
		 	current=current->rightchild;

		 //if not found
		 if(current == NULL)
		 	return NULL;
		 
		 return current; 
	}
}

//in-order traversal
void inorder(struct node* root){
	if(root != NULL){
		inorder(root->leftchild);
		printf("%d\t",root->data);
		inorder(root->rightchild);
	}
}

//pre-order traversal
void preorder(struct node* root){
	if(root != NULL){
		printf("%d\t",root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
}

//post-order traversal
void postorder(struct node* root){
	if(root != NULL){
		postorder(root->leftchild);
		postorder(root->rightchild);
		printf("%d\t",root->data);
	}
}

//total number of nodes
int totalnodes(struct node* root){
	if(root != NULL){
		totalnodes(root->leftchild);
		flag++;
		totalnodes(root->rightchild);
	}
	return flag;
}

//minimum value of the tree
struct node* minValue(struct node* node) {
  struct node* current = node;
  
  // loop down to find the leftmost leaf 
    while (current->leftchild != NULL) {
    current = current->leftchild;
  }
  return current;
}

//maximum value of the tree
int maxValue(struct node* node)
{
    struct node* n = node;
    while(n->rightchild!=NULL)
        n=n->rightchild;
    return n;
}

//inorder successor 
 struct node* insuccessor(struct node *root, struct node* n)
{

	//move to the right subtree and return min value
    if( n->rightchild != NULL )
        return minValue(n->rightchild);
 
    struct node *succ = NULL;
 
    // Start from root and search for successor down the tree
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->leftchild;
        }
        else if (n->data > root->data)
            root = root->rightchild;
        else
           break;
    }
 
    return succ;
}

//inorder predecessor
struct node* inPredecessor(struct node* root, stuct node* x)
{
    if( x->leftchild!= NULL )
        return (maxValue(x->leftchild));
  
    struct node *predecessor = NULL;
  
    while (root != NULL)
    {
        if (x > root->data)
        {
            predecessor = root;
            root = root->rightchild;
        }
        else if (x->data < root->data)
            root = root->leftchild;
        else
           break;
    }
    return predecessor;
}


//deleting a node from the tree
struct node* deleteNode(struct node* root, int data)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    if (data < root->data)
        root->leftchild = deleteNode(root->leftchild, data);
 
    // If the key to be deleted is greater than the root's key,
    else if (data > root->data)
        root->rightchild = deleteNode(root->rightchild, data);
 
    // if key is same as root's data
    else
    {
        // node with only one child or no child
        if (root->leftchild == NULL)
        {
            struct node *temp = root->rightchild;
            free(root);
            return temp;
        }
        else if (root->rightchild == NULL)
        {
            struct node *temp = root->leftchild;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValue(root->rightchild);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->rightchild = deleteNode(root->rightchild, temp->data);
    }
    return root;
}

 //height of the tree
int height(struct node* node)
{
	if(node==NULL)
		return 0;
	else{

		 // compute the depth of each subtree 
       int lDepth = maxValue(node->leftchild);
       int rDepth = maxValue(node->rightchild);
 
       // use the larger one 
       if (lDepth > rDepth) 
           return ((int)lDepth+1);
       else return ((int)rDepth+1);
   }
} 

int main(){

   int i;
   int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

   for(i=0;i<7;i++)
      insert(array[i]);

  	printf("total no of nodes: %d",totalnodes(root));
 	i=31;
   struct node * temp = search(i);

   if(temp != NULL) {
      printf("[%d] Element found.", temp->data);
      printf("\n");
   }
   else {
      printf("[ x ] Element not found (%d).\n", i);
   }

 	i=15;
   temp = search(i);

   if(temp != NULL) {
      printf("[%d] Element found.", temp->data);
      printf("\n");
   }
   else {
      printf("[ x ] Element not found (%d).\n", i);
   }            

   int del;
   printf("enter the node to be deleted:");
 	scanf("%d",&del);
 	deleteNode(root,del);

   printf("\nheight of the tree: %d",height(root));

   printf("\nPreorder traversal:");
   preorder(root);

   printf("\nInorder traversal: ");
   inorder(root);

   printf("\nPost order traversal: ");
   postorder(root);  

   printf("\nEnter the node whose predecessor and successor is needed:");
   scanf("%d",&del);
   
   struct node *x = NULL;
   x->data=del;
   printf("\npredecessor of %d is %d ",x,inPredecessor(root,x));
   printf("\ninsuccessor of %d is %d ",x,insuccessor(root,x));



   return 0;

}