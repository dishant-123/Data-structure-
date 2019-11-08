#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};
Node *getNewNode(int data)
{
	Node *newNode=new Node();
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}
Node *binaryTree(Node *root,int data)
{
	if(root==NULL) 
		root=getNewNode(data);
	else if(data<=root->data)
		root->left=binaryTree(root->left,data);
	else 
		root->right=binaryTree(root->right,data);
	return root;
}
void verticalTraversal(Node *root)
{
	if(!root)
		return ;
	map<int,vector<int> > Map;
	int hd=0;
	queue<pair<Node *,int> > Queue;
	Queue.push(make_pair(root,hd));
	while(!Queue.empty())
	{
		pair<Node *,int> temp=Queue.front();
		Queue.pop();
		hd = temp.second;
		Node *node = temp.first;
		Map[hd].push_back(node->data);
		if(node->left!=NULL)
			Queue.push(make_pair(node->left,hd-1));
		if(node->right!=NULL)
			Queue.push(make_pair(node->right,hd+1));
		
	}
	map<int,vector<int> > :: iterator iterate;
	for(iterate=Map.begin();iterate!=Map.end();iterate++)
	{
		// for vertical level order travirsal
		/*for(int i=0;i<iterate->second.size();i++)
		{
			cout<<iterate->second[i]<<" ";
		}*/
		
		//for top view of tree
		cout<<iterate->second[0]<<" ";
	}
	
}
int main() 
{ 
    int n,data;
    cin>>n;
    Node *root=NULL;
    for(int i=0;i<n;i++)
    {
    	cin>>data;
    	root=binaryTree(root,data);
    }
    verticalTraversal(root);
}
