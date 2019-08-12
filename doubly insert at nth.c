//sort linked list with nodes
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};

struct node *root=NULL;
void print()
{
	struct node *iterate=NULL;
	iterate=root;
	if(root==NULL)
		printf("Empty List");
	else
	{
		while(iterate!=NULL)
		{
			printf("| %d | %d |\n",iterate->data,iterate->next);
			iterate=iterate->next;
		}
	}
}
void add(struct node * temp)
{
	struct node *temp1=NULL;
	int c=1;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp1=root;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
	}
	
}
void doubly_list(int p)
{
	struct node *loop_list=root;
	int c=0;
	while(c<p-1 && loop_list->next!=NULL)
	{
		c++;
		loop_list=loop_list->next;
	}
	struct node *temp1=NULL;
	temp1=root;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=loop_list;
	//print();
}

void * add_nth(struct node * value,int p)
{
	struct node *temp=root;
	int c=0;
	while(c<p-1)
	{
		c++;
		temp=temp->next;
	}
	value->next=temp->next;
	temp->next=value;
	print();
}
int main()

{
	int n,i;
	printf("Enter the length of linked list \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter %d element \n",i+1);
		scanf("%d",&temp->data);
		temp->next=NULL;
		add(temp);
		
	}
	struct node *value=(struct node *)malloc(sizeof(struct node));
	value->next=NULL;
	value->data=10;
	print();
	doubly_list(3);
	printf("Enter the position where you want to add new element.\n");
	int pos;
	scanf("%d",&pos);
	add_nth(value,pos);
}

