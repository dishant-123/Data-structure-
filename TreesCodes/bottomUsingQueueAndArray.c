#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
    int data;
    int val;
    struct node* left;
    struct node* right;
    
}node;



node* createBinary(node* root, int d, int v)
{
    if( root == NULL)
    {
        node* nn = (node*)malloc(sizeof(node));
        nn->data = d;
        nn->val = v;
        nn->left = NULL;
        nn->right = NULL;
        return nn;
    }
    else if(d < root->data)
    {
        root->left = createBinary(root->left, d, v-1);
    }
    else
    {
        root->right = createBinary(root->right,d, v+1);
    }
    return root;
}

// queue implementation
typedef struct
{
  node *arr[100];
  int head, tail;
} Queue;

Queue queue = {.head = 0, .tail = 0};

void queue_push(node *x)
{
  queue.arr[queue.tail++] = x;
}

void queue_pop(void)
{
  queue.head++;
}

bool queue_is_empty(void)
{
  return queue.tail - queue.head == 0;
}

node *queue_peek(void)
{
  return queue.arr[queue.head];
}
void fun(node *root,int *a,int *b,int level,int dist){
  if(root==NULL)
    	return ;
  if(level<a[50+dist]){
    a[50+dist]=level;
    b[50+dist]=root->data;
  }
  fun(root->left,a,b,level+1,dist-1);
  fun(root->right,a,b,level+1,dist+1);
}
void top_view(node *root)
{
    int dist;
    queue_push(root);
    int arr[100],k=0,i;
    for(i=0;i<100;i++)
        arr[i] = -1;
    while(queue_is_empty()!=1)
    {
        node *temp = queue_peek();
        dist = temp->val;
        arr[50+dist]=temp->data;
        if(temp->left)
        {
            queue_push(temp->left);
        }
        if(temp->right)
        {
            queue_push(temp->right);
        }
        queue_pop();
    }
    for(i=0;i<100;i++)
    {
        if(arr[i]!=-1)  
            printf("%d ",arr[i]);
    }
}

int main() 
{
  int num;
  scanf("%d", &num);
  
//   node *root = malloc(sizeof(node));
  node *root = NULL;
  int n;
  for (int i = 0; i < num; i++)
  {
    scanf(" %d", &n);
    root = createBinary(root, n, 0);
  }
  
  top_view(root);
    return 0;
}

