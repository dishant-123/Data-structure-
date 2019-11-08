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
BstNode * newNode(int data)
{
	BstNode *newNode = new BstNode();
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}
BstNode *findLCA(BstNode *root,int elem1,int elem2)
{
	if(root==NULL)
		return NULL;
	if(root->data==elem1 || root->data==elem2)
		return root;
	BstNode *left=findLCA(root->left,elem1,elem2);
	BstNode *right=findLCA(root->right,elem1,elem2);
	//if both left and right are not null it means thier root is the LCA
	if(left && right)
		return root;
	if(left)
		return left;
	else if(right)
		return right;
	else
		return NULL;
	//above three line is same as.
	//return(left!=NULL?left:right);
}
int main()
{
	BstNode * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7);
    int elem1,elem2;
    cin>>elem1>>elem2;
    BstNode *ans=findLCA(root,elem1,elem2);
    if(ans)
   	 cout<<"LCA = "<<ans->data;
   	else
    	cout<<"Both Key not found";
}

