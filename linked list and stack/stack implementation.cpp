#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *next;
};

//struct stack *root=NULL;
int peek(struct stack **root)
{
		return (*root)->data;
}
void push(struct stack **root,int data)
{
	struct stack *value=(struct stack *)malloc(sizeof(struct stack *));
	value->data=data;
	value->next=NULL;
	value->next=*root;
	*root=value; 
}
void print(struct stack **root)
{
	struct stack *iterate=*root;
	while(iterate!=NULL)
	{
		printf("%d ",iterate->data);
		iterate=iterate->next;	
	}
	printf("\n");
}
void pop(struct stack **root)
{
	if(root==NULL)
		printf("no element in stack \n");
	else
	{
		*root=(*root)->next;
	}
}

int isEmpty(struct stack **root)
{
	if((*root)==NULL)
		return 1;
	else
		return 0;
}
int size(struct stack **root)
{
	struct stack *iterate=*root;
	int c=0;
	while(iterate!=NULL)
	{
		c++;
		iterate=iterate->next;
	}
	return c;
}
int main()
{
	int n,d;
	scanf("%d",&n);
	struct stack *root=NULL;
	while(n--)
	{
		scanf("%d",&d);
			push(&root,d);
		//	print();
	}
	print(&root);
	
	
}
