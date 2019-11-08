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
	BstNode *newNode = new BstNode()
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
bool search(BstNode *root,int data)
{
	if(root==NULL)
	{
		return false;
	}
	else if(root->data==data){
		return true;
	}
	else if(root->data>=data){
		return search(root->left,data);
	}
	
	else {
		return search(root->right,data);
	}
}
int findMin(BstNode *root)
{
	/*if(root->left==NULL)
		return root->data;
	else findMin(root->left);*/
	//same using iterative
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root->data;
}
int findMax(BstNode *root)
{
	if(root->right==NULL)
		return root->data;
	else findMax(root->right);
}
int max(int a,int b)
{
	if(a>=b)
		return a;
	return b;
}
int height(BstNode *root)
{
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
void levelOrder(BstNode *root)
{
	/*if(root==NULL)
		return;*/
	queue<BstNode *> Q;
	Q.push(root);
	//cout<<Q.empty();
	while(Q.empty()!=1)
	{
		BstNode *first=Q.front();
		Q.pop();
		cout<<first->data<<" ";
		if(first->left!=NULL)		
			Q.push(first->left);
		if(first->right!=NULL)		
			Q.push(first->right);
			
	}
}
//Data,left,right
void preOrder(BstNode *root)
{
	if(root==NULL)
		return ;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
void postOrder(BstNode *root)
{
	if(root==NULL)
		return ;
	preOrder(root->left);
	preOrder(root->right);
	cout<<root->data<<" ";
}
void inOrder(BstNode *root)
{
	if(root==NULL)
		return ;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}
int main()
{
	BstNode *root=NULL;
	root = Insert(root,15);
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,17);
	root = Insert(root,8);
	root = Insert(root,12);
	if(search(root,0)==true)
		cout<<"Found"<<"\n";
	else
		cout<<"Not Found"<<"\n\n";
	cout<<findMin(root)<<"\n\n";
	cout<<findMax(root)<<"\n\n";
	cout<<height(root)<<"\n\n";
	//breadth first 
	cout<<"\n\n level order :- \n\n";
	levelOrder(root);
	cout<<"\n\n pre order :- \n\n";
	preOrder(root);
	cout<<"\n\n post order :- \n\n";
	postOrder(root);
	cout<<"\n\n in order :- \n\n";
	inOrder(root);
	
}
