//all the leftnodes of any nodes is smaller and right nodes are greater;
#include<iostream>
#include<queue>
#include<stack>
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
void inOrderIterative(BstNode *root)
{
	stack<BstNode *> Stack;
	while(Stack.empty()!=1 || root)
	{
		while(root)
		{
			Stack.push(root);
			root=root->left;
		}
		BstNode *temp=Stack.top();
		Stack.pop();
		cout<<temp->data<<" ";
		root=temp->right;
	}
}
int main()
{
	int n,num;
	cout<<"Enter the no of element and \n";
	cin>>n;
	BstNode *root=NULL;
	while(n--)
	{
		cin>>num;
		root=Insert(root,num);
	}
	inOrderIterative(root);
}
