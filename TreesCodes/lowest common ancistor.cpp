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
int lowestCommonAnsistor(BstNode *root,int arr[],int &count,int elem)
{
	if(root==NULL)//base condition.
		return 0;
	arr[count++]=root->data;
	if(root->data==elem)
		return 1;
	int x=(lowestCommonAnsistor(root->left,arr,count,elem) || lowestCommonAnsistor(root->right,arr,count,elem));
	if(x==0)
		count--;//decreses size ie.remove last element;
	return x;
	
}
int main()
{
	//create BST ! YIPEE!!!!!
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
	//lowest common ansistor for one side;
	int arr1[100],arr2[100];//assume given in queshion.
	//which we have to find LCA.
	int size1=0,size2=0;
	
	int k1=lowestCommonAnsistor(root,arr1,size1,elem1);
	//cout<<k1<<"\n";
	if(k1==0)
		cout<<"Lowest common ansistor for "<<elem1<<" "<<elem2<<" is "<<root->data;
	else
	{
		int k2=lowestCommonAnsistor(root,arr2,size2,elem2);
		//cout<<k2<<"\n";
		/*for(int i=0;i<size1;i++)
			cout<<arr1[i]<<" ";
		cout<<"\n";
		for(int i=0;i<size2;i++)
			cout<<arr2[i]<<" ";
		cout<<"\n";*/
		if(k2==0)
			cout<<"Lowest common ansistor for "<<elem1<<" "<<elem2<<" is "<<root->data;
		else
		{
			for(int i=0;i<size1;i++)
			{
				if(arr1[i]==arr2[i])
				{
					cout<<"Lowest common ansistor for "<<elem1<<" "<<elem2<<" is "<<arr1[i];

				}
			}
		}
	}
	
}
