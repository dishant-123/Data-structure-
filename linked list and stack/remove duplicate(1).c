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
void remove_dupt()
{
	struct node *temp=NULL;
	temp=root;
	while(temp->next!=NULL)
	{
		if((temp->next)->data==(temp)->data)
		{
			temp->next=temp->next->next;
		}
		else
		{
			temp=temp->next;
		}
	}
	
}
int main() 
{
	int n,i;
	
	printf("Enter the length of linked list \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter %d element \n",i+1);
		scanf("%d",&temp->data);
		temp->next=NULL;
		add(temp);
	}
	struct node *top=( struct node*)malloc(sizeof(struct node));
    top->data=-999;
    top->next=root;
    root=top;
    struct node *iterate=root;
    while(iterate->next!=NULL)
    {
        if(iterate->next->data>3)
        {
            struct node *i=iterate->next;
            while(i->next)
            {
                i=i->next;
            }
            
            //i->next=iterate->next;
            iterate->next=iterate->next->next;
            //i->next->next=NULL;
            
            
        }
        else
            iterate=iterate->next;
    }
	print(root->next);
}
