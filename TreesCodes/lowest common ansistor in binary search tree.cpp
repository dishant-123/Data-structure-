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
int lowestCommonAnsistor(BstNode *root,int n1,int n2)
{
	while(root!=NULL)
	{
		if(root->data > n1 && root->data > n2)
			root=root->left;
		else if(root->data < n1 && root->data < n2)
			root=root->right;
		else 
		{
			break;
		}
	}
	return root->data;
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
	int elem1,elem2;
	cout<<"Enter two element whose LCA has to be found.\n";
	cin>>elem1>>elem2;
	int ans=lowestCommonAnsistor(root,elem1,elem2);
	cout<<"Lowest common ansistor for "<<elem1<<" "<<elem2<<" is "<<ans;
}
