/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node.
*/
void getSolution(struct Node *root,int sum){
  	if(root==NULL)	return ;
 	sum+=1;
  	if(sum%2!=0){
     	printf("%d ",root->data);
    }
  getSolution(root->left,sum);
  getSolution(root->right,sum);
}
void printOdd(struct Node* root)
{
	struct Node *start=root;
  	int sum=0;
  	getSolution(root,sum);

}
