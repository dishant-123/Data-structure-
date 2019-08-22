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
	if(root==NULL)
		printf("no element in stack \n");
	else
	{
		root=root->next;
	}
}
int peek()
{
	if(root==NULL)
	{
		
	}
		//printf("No element in stack \n");
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
	char str[]="O";
	int l=strlen(str),i,s=0,temp,sum=0,d;
	for(i=0;i<l;i++)
	{
		d=(int)str[i];
		if(str[i]=='C')
		{
			push(12);
		}
		else if(str[i]=='H')
		{
			push(1);
		}
		else if(str[i]=='O')
		{
			push(16);
		}
		else if(str[i]=='(')	
		{
			push(-1);
		}	
		else if(d>48 && d<57)
		{
			temp=peek();
			///printf("temp=%d %d \n",temp,d);
			pop();
			push(temp*(d-48));
		}
		else
		{
			s=0;
			while(peek()!=-1)
			{
				s=s+peek();
				pop();
			}
			pop();
			push(s);
		}
		//print();
	}
	while(peek())
	{
		sum+=peek();
		pop();
	}
	printf("%d",sum);
}
