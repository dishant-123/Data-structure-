//remove dupicate 2 1,1,1,2,2,3,4 = 3,4
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *root=NULL;
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
	
	//print(root);
}
void removeDuplicate()
{
	struct node *dummyNode=(struct node *)malloc(sizeof(struct node));
	dummyNode->next=root;
	root=dummyNode;
	struct node *ptr1=root,*ptr2=root->next;
	while(ptr2!=NULL)
	{
		while((ptr1->next->data == ptr2->next->data )&& ptr2->next)
		{
			ptr2=ptr2->next;
		}
		if(ptr1->next==ptr2)
		{
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else
		{
			ptr1->next=ptr2->next;
			ptr2=ptr2->next;
		}
	}
	//else 
	root=dummyNode->next;
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
	removeDuplicate();
	print(root);
}
