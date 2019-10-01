//insert at ith position, delete at ith posotion,reverse the list
#include<stdio.h>
struct node
{
	int data;
	struct node *next;	
};
struct node *root;
int main()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
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
			temp->next=root;
			root=temp;
		}
		
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
}
