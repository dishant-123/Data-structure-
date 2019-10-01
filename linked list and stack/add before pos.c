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
	
	//print();
}
struct node *root;
int length()
{
	int c=0;
	struct node *temp;
	temp=root;
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	//printf("%d \n",c);
	return c;
}
void add_before(int p,struct node * value)//different stack frame for all function.
{
	struct node *temp=NULL;
	temp=root;
	int c=0,p1=0;
	if(root=NULL)
	{
		printf("No element in list.\n");
	}
	else if(p==1)
	{
		value->next=root;
		root=value;
	}
	else
	{
		while(c<p-1)
		{
			c++;
			temp=temp->next;
			p1=1;
		}
		value->next=temp->next;
		temp->next=value;
	}
}
int main()

{
	int n,i;
	struct node *temp=NULL;
	printf("Enter the length of linked list \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter %d element \n",i+1);
		scanf("%d",&temp->data);
		temp->next=NULL;
		add(temp);
	}
	struct node *value=NULL;
	value=(struct node *)malloc(sizeof(struct node));
	value->next=NULL;
	value->data=9;
	add_before(4,value);
}

