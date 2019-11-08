//all the leftnodes of any nodes is smaller and right nodes are greater;
#include<iostream>
#include<queue>
int floor;
int ceil;
int prev;
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
void floorCeilInorder(BstNode *root,int key)
{
	if(root==NULL)
		return ;
	floorCeilInorder(root->left,key);
	if(root->data==key)
	{
		floor=root->data;
		ceil=root->data;
		//exit(0);
	}
	if(root->data>key)
	{
		if(floor==0)
			floor=prev;
		if(ceil==0)
			ceil=root->data;
		//exit(0);
	}
	prev=root->data;
	floorCeilInorder(root->right,key);
}
int main()
{
	prev=-1;
	floor=0;
	ceil=0;
	BstNode *root=NULL;
	int num;
	for(int i=0;i<7;i++)
	{
		cin>>num;
		root=Insert(root,num);
	}
	floorCeilInorder(root,32);
	cout<<"floor value is "<<floor<<"\n";
	cout<<"ceil value is "<<ceil;
}
