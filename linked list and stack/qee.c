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
int main()
{
	char str[]="2 1 + 3 * 3 +";
	int l=strlen(str);
	int i,b,a,c;
    for(i=0;i<l;i++)
    {
        int d=(int)str[i];
        if(d>=48 && d<=57)
        {
            push((d-48));
        }
        else if(str[i]=='+')
        {
            b=peek();
            pop();
            a=peek();
            pop();
            c=b+a;
            push(c);
        }
        else if(str[i]=='-')
        {
            b=peek();
            pop();
            a=peek();
            pop();
            c=b-a;
            push(c);   
        }
        else if(str[i]=='*')
        {
            b=peek();
            pop();
            a=peek();
            pop();
            c=b*a;
            push(c);   
        }
        else if(str[i]=='/')
        {
            b=peek();
            pop();
            a=peek();
            pop();
            c=b/a;
            push(c);   
        }
        else
        {
		}
    }
    printf("%d",peek());

}

