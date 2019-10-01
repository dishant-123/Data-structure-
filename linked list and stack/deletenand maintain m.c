/*geeks for geeks
Delete N nodes after M nodes of a linked list
M = 2, N = 2
Linked List: 1->2->3->4->5->6->7->8
Output:
Linked List: 1->2->5->6
*/
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
void deletemn(int m,int n)
{
	struct node *temp=root;
	int countm=0,countn=0;
	while(temp)
	{
		countm=0,countn=0;
		while(countm<m-1 && temp)
		{
			countm++;
			temp=temp->next;
			
		}
		if(temp==NULL || temp->next==NULL)
		break;
		while(countn<n && temp->next)
		{
			countn++;
			temp->next=temp->next->next;
		}
		temp=temp->next;
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
	//printf("\n");
	deletemn(3,2);
	print(root);
}
