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
void split()
{
	int c=0;
	
	struct node *i=NULL;
	struct node *j=NULL;
	struct node *temp=NULL;
	struct node *start=root;
	struct node *end=NULL;
	i=root;
	j=root;
	while((j->next!=NULL && j!=NULL) && ((j->next->next!=NULL && j!=NULL)))
	{
		j=j->next->next;
		end=i;
		i=i->next;
		c++;
	}
	//end=i->next;
	i->next=NULL;
	print(start);
	printf("\n");
	print(end);
	
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
		//printf("%d %d \n",temp,&temp);
	}
	//print(root);
	//printf("\n");
	split();
}
