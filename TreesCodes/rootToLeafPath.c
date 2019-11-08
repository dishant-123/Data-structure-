/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */
int i;
void getSolution(struct Node *root,int *arr,int *size,int *count){
  if(root==NULL)	return ;
  arr[*size]=root->data;
  *size+=1;
  getSolution(root->left,arr,size,count);
  getSolution(root->right,arr,size,count);
  if(root->left==NULL && root->right==NULL){
    *count+=1;
  	for(i=0;i<*size;i++){
      printf("%d ",arr[i]);
    }
    printf("%d\n",*size-1);
  }
  *size=*size-1;
}
void printAllPaths(struct Node* root) 
{
  	
	int arr[100],size=0,count=0;
  	getSolution(root,arr,&size,&count);
  	if(root!=NULL)
  	printf("%d",count);
}
