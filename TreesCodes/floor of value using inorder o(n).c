//all the leftnodes of any nodes is smaller and right nodes are greater;
#include<iostream>
#include<queue>
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
int main()
{
	BstNode *root=NULL;
	int num;
	for(i=0;i<7;i++)
	{
		cin>>num;
		root=insert(root,num);
	}
}
