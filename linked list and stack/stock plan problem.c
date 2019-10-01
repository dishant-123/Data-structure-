#include<stdio.h>
#include<stdio.h>
struct stack
{
	int data;
	struct stack *next;
};
struct stack *root=NULL;
void push(int data)
{
	struct stack *value=NULL;
	value=(struct stack *)malloc(sizeof(struct stack *));
	value->data=data;
	value->next=NULL;
	if(root==NULL)
	{
		root=value;
	}
	else
	{
		value->next=root;
		root=value;
	}
}
void print()
{
	struct stack *iterate=root;
	while(iterate!=NULL)
	{
		printf("%d ",iterate->data);
		iterate=iterate->next;	
	}
	printf("\n");
}
void pop()
{
	root=root->next;
}
int peek()
{
	if(root==NULL)
		printf("No element in stack \n");
	else
		return root->data;
}
int isEmpty()
{
	if(root==NULL)
		return 1;
	else
		return 0;
}
int size()
{
	struct stack *iterate=root;
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
	int n,d,k=0,i,c=0;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int res[n];
	res[0]=1;
	push(0);
	for(i=1;i<n;i++)
	{
				while(arr[peek()]<=arr[i]  && !isEmpty())
				{
					pop();
					
				}
				res[i]=isEmpty()?i+1:i-peek();
				
				push(i);
	
	}
	for(i=0;i<n;i++)
	{
		printf("%d \n",res[i]);
	}
}
