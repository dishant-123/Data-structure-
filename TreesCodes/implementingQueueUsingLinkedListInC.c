
#include <stdio.h>
struct Qnode
{
  int data;
  struct Qnode *next;
};
struct Queue
{
  struct Qnode *front;
  struct Qnode *rear;
};
struct Qnode *newNode(int data)
{
     struct Qnode *node = (struct Qnode *)malloc(sizeof(struct Qnode));
     node->data = data;
     node->next = NULL;
     return node;
}
void push(struct Queue *qroot,int data)
{
    struct Qnode *node = newNode(data);
    if(qroot->front == NULL && qroot->rear == NULL)
    {
        qroot->front = node;
        qroot->rear = node;
        return ;
    }
    qroot->rear->next = node;
    qroot->rear = node; 
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
    if(qroot->front == qroot->rear == NULL)
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
int main()
{
    struct Queue *newQ = (struct Queue *)malloc(sizeof(struct Queue));
    newQ ->front = newQ->rear = NULL;
    push(newQ,1);
    push(newQ,2);
    push(newQ,3);
    push(newQ,4);
    push(newQ,5);
    pop(newQ);
    pop(newQ);
    pop(newQ);
    pop(newQ);
    print(newQ);
    return 0;
}
