/* struct Node {
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */

int areSameTree(struct Node* r1, struct Node* r2)
{
	if(r1==NULL && r2==NULL){
      return 1;
    }
  	if(r1==NULL || r2==NULL)	return 0;
  	return((r1->data==r2->data) &&  (areSameTree(r1->left,r2->left)) && (areSameTree(r1->right,r2->right)) );
}

