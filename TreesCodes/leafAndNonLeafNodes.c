/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */

int countLeafs(struct Node* root) 
{
	if(root==NULL)	return 0;
  	if(root->left==NULL && root->right==NULL)	return 1;
  	int a=countLeafs(root->left);
  	int b=countLeafs(root->right);
  	return a+b;
}
void getSolution(struct Node *root,int *countNonLeafs){
  if(root==NULL)	return ;
  if(root->left!=NULL || root->right!=NULL)	*countNonLeafs+=1;
  getSolution(root->left,countNonLeafs);
  getSolution(root->right,countNonLeafs);
}
int countNonLeafs(struct Node* root) 
{
  	int countNonLeafs=0;
	getSolution(root,&countNonLeafs);
  	return countNonLeafs;
}
