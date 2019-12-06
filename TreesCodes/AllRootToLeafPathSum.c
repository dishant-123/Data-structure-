// C++ program to find sum of 
// all paths from root to leaves 
#include <bits/stdc++.h> 
using namespace std; 

class node 
{ 
	public: 
	int data; 
	node *left, *right; 
}; 

// function to allocate new node with given data 
node* newNode(int data) 
{ 
	node* Node = new node(); 
	Node->data = data; 
	Node->left = Node->right = NULL; 
	return (Node); 
} 

// Returns sum of all root to leaf paths. 
// The first parameter is root 
// of current subtree, the second 
// parameter is value of the number formed 
// by nodes from root to this node 

//logic mine..
void treePathsSumUtil(node *root, int sum, int *mainSum) 
{ 
	if(root==NULL)
      	return ;
 	sum = sum*10+root->data;
  	treePathsSumUtil(root->left,sum,mainSum);
  	treePathsSumUtil(root->right,sum,mainSum);
  	if(root->left == NULL && root->right == NULL)
    {
    	*mainSum += sum;
    }
} 

// Driver code 
int main() 
{ 
	node *root = newNode(6); 
	root->left = newNode(3); 
	root->right = newNode(5); 
	root->left->left = newNode(2); 
	root->left->right = newNode(5); 
	root->right->right = newNode(4); 
	root->left->right->left = newNode(7); 
	root->left->right->right = newNode(4); 
  	int mainSum = 0,sum=0;
	treePathsSumUtil(root,sum=0,  &mainSum); 
  	printf("%d",mainSum);
	return 0; 
} 

// This code is contributed by rathbhupendra 
