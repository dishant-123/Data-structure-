#include<stdio.h>
int front=-1;
int rear=-1;
int arr[4];
int isFull()
{
	if((rear+1)%4==front)
		return 1;
	return 0;
}
void enque(int data)
{
	if(isFull())
		printf("Error Queue is Full \n");
	else if(isEmpty())
		front=rear=0;
	else
		rear=(rear+1)%4;
	arr[rear]=data;	
}
void deque()
{
	if(isEmpty())
		printf("Sorry Queue is empty \n");
	else if(front==rear)
		front=rear=-1;
	else
		front=front+1;
}
int isEmpty()
{
	if(front==-1 && rear==-1)
		return 1;
	return 0;
}
int top()
{
	return arr[front];
}
int main()
{
	enque(1);
	enque(4);
	enque(5);
	enque(7);
	deque();
	deque();
	printf("%d \n",top());
	 
}
