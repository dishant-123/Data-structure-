#include<stdio.h>
struct queue{
	int data;
	struct queue *next;
};
struct queue *start=NULL;
struct queue *end=NULL;
void push(int data){
	struct queue *newNode=(struct queue *)malloc(sizeof(struct queue)); 
	newNode->data=data;
	newNode->next=NULL;
	if(start==NULL && end==NULL){
		start=newNode;
		end=newNode;
	}
	else{
		end->next=newNode;
		end=end->next;
	}
}
void pop(){
	if(start==end){
		start=end=NULL;
	}
	else{
		start=start->next;
	}
}
void print(){
	while(start!=end){
		printf("%d ",start->data);
		start=start->next;
	}
	printf("%d ",start->data);
	printf("\n");
}
int front(){
	return start->data;
}
int main(){
	int noe,num;
	scanf("%d",&noe);
	while(noe--){
		scanf("%d",&num);
		push(num);
	}
	print();
	printf("%d %d",start->data,end->data);
}
