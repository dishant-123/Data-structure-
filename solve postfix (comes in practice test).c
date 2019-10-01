#include <stdio.h>
#include<string.h>
struct stack 
{
  int data;
  struct stack *next;
};
push(struct stack **root,int data)
{
    struct stack *newNode=(struct stack *)malloc(sizeof(struct stack));
    newNode->data=data;
    newNode->next=NULL;
    newNode->next=(*root);
    (*root)=newNode;
}
void pop(struct stack **root)
{
	if(*root==NULL)
		return ;
	else
	{
		/*struct stack *top=NULL;
		top = (*root);  
	    (*root) = top->next; 
	    free(top);*/
	    (*root)=(*root)->next;
 	}
}
int peek(struct stack *root)
{
	
	if(root!=NULL)
    	return root->data;
    else
    	return -1;
}
int main()
{
   char str[100];
   scanf("%[^\n]",str);
   int n=strlen(str);
   struct stack *root=NULL;
   int i;
   char *token=strtok(str," ");
   while(token!=NULL)
   {
   
       if(strcmp(token,"+")==0 || strcmp(token,"-")==0 || strcmp(token,"/")==0 || strcmp(token,"*")==0)
       {
           int a=peek(root);
           pop(&root);
           int b=peek(root);
           pop(&root);
            if(strcmp(token,"+")==0)
            {
                push(&root,b+a);
            }
            else if(strcmp(token,"-")==0)
            {
                push(&root,b-a);
            }
            else if(strcmp(token,"/")==0)
            {
                push(&root,b/a);
            }
            else if(strcmp(token,"*")==0)
            {
                push(&root,b*a);
            }
       }
       else 
       {
           push(&root,atoi(token));
       }
       token=strtok(NULL," ");
   }
   printf("%d",peek(root));
}

