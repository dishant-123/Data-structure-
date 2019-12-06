#include <bits/stdc++.h> 
using namespace std; 

// A Binary Tree Node 
struct node 
{ 
	struct node *left, *right; 
	int key; 
}; 

// Utility function to create a new tree node 
node* newNode(int key) 
{ 
	node *temp = new node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
//logic mine....
void printSingles(struct node *root) 
{ 
	
	if (root == NULL) 
	return; 
	
	 if (root->left==NULL && root->right != NULL) 
	{ 
		cout << root->right->key << " "; 
	} 

	else if (root->right == NULL && root->left != NULL) 
	{ 
		cout << root->left->key << " ";
	} 
  	printSingles(root->left); 
	printSingles(root->right);
} 

int main() 
{ 
	// Let us create binary tree given in the above example 
	node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->right = newNode(4); 
	root->right->left = newNode(5); 
	root->right->left->left = newNode(6); 
	printSingles(root); 
	return 0; 
} 

