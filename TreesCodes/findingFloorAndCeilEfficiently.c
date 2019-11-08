/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */
void getCeil(struct Node *root,int key,int *ans){
  	if(root==NULL)	return ;
  	getCeil(root->left,key,ans);
  	if(root->data>=key && *ans==-1){
      *ans=root->data;
    }
  	getCeil(root->right,key,ans);
}
void getFloor(struct Node *root,int key,int *ans){
  	if(root==NULL)	return ;
  	getFloor(root->left,key,ans);
  	if(root->data<=key){
      *ans=root->data;
    }
  	getFloor(root->right,key,ans);
}
int floorOf(struct Node* root, int key)
{
  	int ans=-1;
	getFloor(root,key,&ans);
  	return ans;
}

int ceilOf(struct Node* root, int key)
{
  	int ans=-1;
	getCeil(root,key,&ans);
  	return ans;
}
