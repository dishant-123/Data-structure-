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
void reverseK()
{
	int c=3,j=0;
	struct node *curr=root,*temp=NULL,*temp1=NULL;
	struct node *next=NULL;
	struct node *prev=NULL;
	while(curr)
	{
		int c1=0;
		temp=curr;
		while(c1<c && curr)
		{
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
			c1++;
		}
		if(j==0)
			root=prev;
		else
		{
			temp1->next=prev;
		}
		temp1=temp;
		prev=NULL;
		j++;
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
	reverseK();
	print(root);
}
