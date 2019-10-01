#include<stdio.h>
struct Queue
{
	int data;
	struct Queue *next;	
};
struct	Queue *front=NULL;
struct	Queue *rear=NULL;
void enqueue(int data)
{
	struct Queue *newNode=(struct Queue *)malloc(sizeof(newNode));
	(*newNode).next=NULL;
	newNode->data=data;
	if(front==NULL && rear==NULL)
		front=rear=newNode;
	else
		rear->next=newNode;
		rear=newNode;
}
void deque()
{
	struct Queue *temp=front;//to delete front node (also works if we don't do that);
	if(front==NULL)
	{
		printf("Queue is Empty");
		return;
	}
	if(front==rear)
		front=rear=NULL;
	else
		front=front->next;
	free(temp);
		
}
int top()
{
	if(front == NULL)
	{
		printf("Queue is Empty\n");	
		return -1;
	}
	return front->data;
}
int isEmpty()
{
	if(front==NULL)
		return 1;
	return 0;
}
void print()
{
	struct Queue *iterate=front;
	while(iterate)
	{
		printf("%d -> ",iterate->data);
		iterate=iterate->next;
	}
	printf("NULL\n");
}
int main()
{
	enqueue(1);print();
	enqueue(2);print();
	enqueue(2);print();
	enqueue(3);print();
	deque();print();
	deque();print();
	deque();print();
	deque();print();
	printf("top = %d \n",top());
}
