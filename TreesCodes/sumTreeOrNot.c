#include <stdio.h> 
#include <stdlib.h> 

/* A binary tree node has data, left child and right child */
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

/* A utility function to get the sum of values in tree with root 
as root */
int sum(struct node *root) 
{ 
if(root == NULL) 
	return 0; 
return sum(root->left) + root->data + sum(root->right); 
} 

/* returns 1 if sum property holds for the given 
	node and both of its children */
int fun(struct node* root) 
{ 
	int left,right;
  	if(root == NULL)
      	return 0;
 	if(root->left==NULL && root->right==NULL)
      return root->data;
  	left = fun(root->left);
  	if(left == -1)
      return root->data;
  	right = fun(root->right);
  	if(left+right!=root->data)
      return -1;
  	else
      root->data+=root->data;
  	return root->data;
} 

/* 
Helper function that allocates a new node 
with the given data and NULL left and right 
pointers. 
*/
struct node* newNode(int data) 
{ 
	struct node* node = 
		(struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 

/* Driver program to test above function */
int main() 
{ 
	struct node *root = newNode(26); 
	root->left		 = newNode(10); 
	root->right	 = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(6); 
	root->right->right = newNode(3); 
	if(fun(root)!=-1) 
		printf("The given tree is a SumTree "); 
	else
		printf("The given tree is not a SumTree "); 

	getchar(); 
	return 0; 
} 

