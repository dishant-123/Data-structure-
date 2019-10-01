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
void reverse()
{
	struct node *curr=root;
	struct node *next=NULL;
	struct node *prev=NULL;
	while(curr)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	root=prev;
}
void add1()
{
	int sum=0,carry=1;
	struct node *head=root,*temp=NULL;
	while(head)
	{
		sum=carry+head->data;
		carry=sum>=10?1:0;
		sum=sum%10;
		head->data=sum;
		temp=head;
		head=head->next;
	}
	if(carry
	>0)
	{
		struct node *value=(struct node *)malloc(sizeof(struct node ));
		value->data=carry;
		value->next=NULL;
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
	reverse();
	add1();
	reverse();
	print(root);
}
