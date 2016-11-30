#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
int isBSTUtil(struct node* node, int min, int max);
 
int isBST(struct node* node) 
{ 
  return(isBSTUtil(node, INT_MIN, INT_MAX)); 
} 

int isBSTUtil(struct node* node, int min, int max) 
{ 
  /* an empty tree is BST */
  if (node==NULL) 
     return 1;
       
  /* false if this node violates the min/max constraint */ 
  if (node->data < min || node->data > max) 
     return 0; 
 
  /* otherwise check the subtrees recursively, 
   tightening the min or max constraint */
  return
    isBSTUtil(node->left, min, node->data-1) && isBSTUtil(node->right, node->data+1, max); 
} 

struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(3);
  root->right       = newNode(7);
  root->left->left  = newNode(1);
  root->left->right = newNode(2); 
 
  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
     
  getchar();
  return 0;
}