/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node and the function below is also provided to build a new node with given data. 
struct Node* newNode(int data);
*/
int getSolution(struct Node* root,int key,int *res,int level){
  	if(root==NULL)	return 0;
  	level+=1;
  	if(*res!=-1 && *res==level){
      return root->data;
    }
  	if(root->data==key){
      *res=level;
    }	
  	int a=getSolution(root->left,key,res,level);
   	int b=getSolution(root->right,key,res,level);
  	if(a!=0 || b!=0){
      if(a!=0)	return a;
      if(b!=0)	return b;
    }
}
int findRightSibling(struct Node* root, int key)
{
  	int res=-1,level=0;
	res = getSolution(root,key,&res,level);
  	if(res==0)	return -1;
 	else	return res;
}
