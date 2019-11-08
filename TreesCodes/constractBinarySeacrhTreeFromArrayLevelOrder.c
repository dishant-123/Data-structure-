/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node and also one function to create a new node as belo is provided. 
struct Node* newNode(int data); 	*/
struct Node *createNode(int data){
  struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
  newNode->left=newNode->right=NULL;
  newNode->data=data;
  return newNode;
}
struct Node *getRootNodeOfBst(struct Node *root,int data){
  if(root==NULL){
    root=createNode(data);
    return root;
  }
  else if(data<=root->data){
    root->left=getRootNodeOfBst(root->left,data);
  }
  else{
    root->right=getRootNodeOfBst(root->right,data);
  }
  return root;
}
struct Node* buildSearchTree(int t[], int n){
    struct Node* root = NULL;
  	int i;
  	for(i=0;i<n;i++){
      root=getRootNodeOfBst(root,t[i]);
    }
    return(root);
}
