#include<stdio.h>
struct node
{
	int data;
	struct node *next;	
};
struct node *root;

void print(struct node * root1)
{
	struct node *iterate=NULL;
	iterate=root1;
	if(root1==NULL)
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
int length(struct node *root1)
{
	int c=0;
	struct node *temp;
	temp=root1;
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	return c;
}
void insert_at_ith(struct node *root1,int p,int v)
{
	struct node *temp=NULL;
	struct node *temp1=NULL;
	struct node *iterate=NULL;
	struct node *value=(struct node *)malloc(sizeof(struct node));
	value->data=v;
	value->next=NULL;
	int i=1;
	temp=root1;
	if(root1==NULL)
		printf("No element for deletion\n");
	else if(p>length(root1))
	{
		printf("position out of range..\n");
	}
	else if(p==0)
	{
		value->next=temp;
		root1=value;
		print(root1);
	}
	else
	{
		while(i<p)
		{
			temp1=temp->next;
			temp=temp->next;
			i++;
		}
		
		value->next=temp;
		temp1->next=value;
		print(root1);
	}
	
	
	
}


int main()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *temp1=NULL;
	int i=0;
	while(i<4)
	{
		i++;
		temp=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&temp->data);
		temp->next=NULL;
		if(root==NULL)
		{
			root=temp;
		}
		
		else
		{
			temp1->next=temp;
			//root=temp;
		}
		temp1=temp;
		
	}
	//print(root);
	insert_at_ith(root,2,100);
}
