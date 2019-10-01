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
void delete1(int p)
{
	int i=1;
	struct node *temp=NULL;
	struct node *temp1=NULL;
	temp=root;
	if(p>length())
	{
		printf("Position out of range \n");
	}
	else if(p==1)
	{
		root=temp->next;
		
	}
	else
	{
		while(i<p-1)
		{
			temp=temp->next;
			i++;
		}
		//printf("%d \n",temp->next->data);
		temp->next=temp->next->next;
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
		//printf("%d %d \n",temp,&temp);
	}
	int p;
	printf("Enter the position you want to delete \n");
	scanf("%d",&p);
	delete1(p);
	print(root);
}
