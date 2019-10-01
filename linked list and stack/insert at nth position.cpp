#include<stdio.h>
struct node
{
	int data;
	struct node *next;	
};
struct node *root;
void insert_beg(struct node *root1)
{
	struct node *temp=NULL;
	struct node *iterate=NULL;
	temp=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&temp->data);
	temp->next=NULL;
	iterate=root1;
	int c=0;
	if(root1==NULL)
	{
		root1=temp;
	}
	else
	{
		while(iterate->next!=NULL)
		{
			iterate=iterate->next;
			c++;
		}
		iterate->next=temp;
		
	}
	iterate=NULL;
	iterate=root1;
	int i=0;
	while(iterate->next!=NULL)
	{
		printf("%d | %d\n",iterate->data,iterate->next);
		i++;
		iterate=iterate->next;
	}
	//iterate=iterate->next;
	printf("%d | %d\n",iterate->data,iterate->next);
	
}


int main()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *temp1=NULL;
	int i=0;
	while(i<5)
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
		}
		temp1=temp;
		
	}
	struct node *iterate;
	iterate=root;
	i=0;
	while(i<5)
	{
		printf("| %d | %d |\n",iterate->data,iterate->next);
		iterate=iterate->next;
		i++;
	}
	insert_beg(root);
}
