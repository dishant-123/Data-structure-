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
void delete_last_node(struct node *root1)
{
	struct node *temp=NULL;
	struct node *iterate=NULL;
	iterate=root1;
	if(root1==NULL)
		printf("No element for deletion");
	else if(root1->next==NULL)
	{
		root1=NULL;
	}
	else
	{
		while(iterate->next->next!=NULL)
		{
			iterate=iterate->next;
		}
		iterate->next=NULL;
	
	}
	print(root1);
	
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
		}
		temp1=temp;
		
	}
	print(root);
	delete_last_node(root);
}
