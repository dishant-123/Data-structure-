
#include <stdio.h>
#include<stdlib.h>
struct treeNode
{
  int data;
  struct treeNode *left;
  struct treeNode *right;
  struct treeNode *next;
  int hd;
};
struct Queue
{
  struct treeNode *front;
  struct treeNode *rear;
};

struct treeNode *newNode(int data)
{
     
     struct treeNode *node = (struct treeNode *)malloc(sizeof(struct treeNode));
     node->data = data;
     node->left = node->right = node->next = NULL;
     node->hd = 0;
     return node;
}
void push(struct Queue *qroot,struct treeNode *node)//node = tree ki node
{
    if(qroot->front == NULL && qroot->rear == NULL)
    {
        qroot->front = node;
        qroot->rear = node;
        return ;
    }
    qroot->rear->next = node;
    qroot->rear = node; 
}
struct Queue *top(struct Queue *qroot)
{
    return qroot->front;
}
void pop(struct Queue *qroot)
{
    if(qroot->front == qroot->rear)
    {
        qroot->front = qroot->rear = NULL;
    }
    else
    {
        qroot->front = qroot->front->next;
    }
}
int empty(struct Queue *qroot)
{
    if(qroot->front == NULL)
    {
        return 1;
    }
    return 0;
}
void print(struct Queue *qroot)
{
    while(qroot->front!=NULL)
    {
        printf("%d ",qroot->front->data);
        qroot->front= qroot->front->next;
    }
}
int find(int arr[],int end,int f)
{
    int i;
    for(i=0;i<end;i++)
    {
        if(arr[i] == f)
            return 1;
    }
    return 0;
}
int main()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue ->front = queue->rear = NULL;
    struct treeNode *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right = newNode(5);
    root->right->left = newNode(6);
    // int *arr = (int *)malloc(sizeof(int )*6);
    int arr[6];
    int hd=0,k=0;
    root->hd = hd;
    push(queue,root);
    while(empty(queue)==0)
    {
        struct treeNode *temp = top(queue);
        hd = temp->hd;
        if(find(arr,k,hd)==0)
        {
            arr[k] = hd;
            printf("%d %d \n",arr[k],temp->data);
            k=k+1;
        }
        if(temp->left!=NULL)
        {
            temp->left->hd = hd-1;
            push(queue, temp->left);
        }
        if(temp->right!=NULL)
        {
            temp->right->hd = hd+1;
            push(queue, temp->right);
        }
        pop(queue);
    }
    return 0;
}
