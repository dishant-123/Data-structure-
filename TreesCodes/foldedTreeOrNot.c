/* struct Node {
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */
int getSolution(struct Node *root1,struct Node *root2){
	if(root1==NULL && root2==NULL){
      return 1;
    }
  	if(root1==NULL || root2==NULL)	return 0;
  	return(getSolution(root1->left,root2->right) && getSolution(root1->right,root2->left));
}
int isFoldable(struct Node* root)
{
  	if(root==NULL)
      	return 1;
	return getSolution(root->left,root->right);
}
