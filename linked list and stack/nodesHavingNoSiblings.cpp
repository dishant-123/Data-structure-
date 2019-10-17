//all the leftnodes of any nodes is smaller and right nodes are greater;
#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
struct BstNode{
	int data;
	BstNode *left;
	BstNode *right;
};
BstNode * getNewNode(int data)
{
	BstNode *newNode = new BstNode();
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}
BstNode * Insert(BstNode *root,int data)
{
		if(root==NULL)
			root=getNewNode(data);
		else if(data <= root->data)
			root->left=Insert(root->left,data);
		else 
			root->right=Insert(root->right,data);
		return root;
}
void findNodesHavingNosublings(BstNode *root){
	if(root==NULL)	return ;
	if(root->left!=NULL && root->right!=NULL){
		findNodesHavingNosublings(root->left);
		findNodesHavingNosublings(root->right);
	}
	else if(root->left!=NULL){
		cout<<root->left->data<<" ";
		findNodesHavingNosublings(root->left);
	}
	else if(root->right!=NULL){
		cout<<root->right->data<<" ";
		findNodesHavingNosublings(root->right);
	}
}
int main()
{
	BstNode *root=NULL;
	root = Insert(root,5);
	
	root = Insert(root,4);	
	root = Insert(root,6);
	root = Insert(root,7);
	root = Insert(root,8);
	findNodesHavingNosublings(root);
	
}
