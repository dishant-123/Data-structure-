#include<stdio.h>
#include<stdlib.h>
struct stack{
  struct stack *next;
  char data;
};
struct stack * getNewNode(struct stack *root, char data){
    struct stack *newNode = (struct stack *)malloc(sizeof(struct stack));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}
struct stack * push(struct stack *root,char data){
    struct stack *newNode = getNewNode(root,data); 
    newNode->next = root;
    root = newNode;
    return root;
}
struct stack * pop(struct stack *root){
    root = root->next;
    return root;
}
char top(struct stack *root){
    return root->data;
}
int weight(char a){
    if(a=='+' || a=='-')
        return 1;
    if(a=='*' || a == '/')
        return 2;
}
int highPrecedence(char a,char b){
    int weight1 = weight(a);
    int weight2 = weight(b);
    return weight1>=weight2;
}
int empty(struct stack *root){
    return root==NULL;
}
void solveExp(struct stack *root,char *str)
{
    int a,b,i;
    for(i=0;str[i];i++)
    {
        if((str[i]>='0'&&str[i]<='9'))
        {
            root = push(root,str[i]);
        }
        else
        {
            a = top(root);
            // printf("%d",b);
            root = pop(root);
            b = top(root);
            root = pop(root);
            if(str[i]=='*')
            {
                a=(a-48)*(b-48);
                printf("%d \n",a);
                root = push(root,a);
            }
            if(str[i]=='/')
            {
                a=(a-48)/(b-48);
                root = push(root,a);
            }
            if(str[i]=='+')
            {
                a=(a-48)+(b-48);
                root = push(root,a);
            }
            if(str[i]=='-')
            {
                a=(a-48)-(b-48);
                root = push(root,a);
            }
        }
       
    }
     printf("%c",top(root));
}
void postFix(struct stack *root,char *str)
{
    int i,k=0;
    char res[100],temp;
    for(i=0;str[i];i++)
    {
        if((str[i]>='0'&&str[i]<='9'))
        {
            res[k++] = str[i];
            continue;
        }
        if(str[i]=='(')
        {
            root = push(root,str[i]);
            continue;
        }
        if(str[i]=='+' || str[i]=='-' || str[i]=='/' || str[i]=='*' )
        {
            while(empty(root)==0 && top(root)!='(' && highPrecedence(top(root),str[i]))
            {
                temp = top(root);
                res[k++] = temp;
                root = pop(root);
            }
            root= push(root,str[i]);
        }
        if(str[i]==')')
        {
            while(empty(root)==0 && top(root)!='(')
            {
                temp = top(root);
                res[k++] = temp;
                root = pop(root);
            }
            root = pop(root);
        }
    }
    while(empty(root)==0)
    {
        temp = top(root);
        res[k++] = temp;
        root = pop(root);
    }
    printf("%s \n",res);
    solveExp(root,res);
    // printf("%s",res);
}
int main()
{
    struct stack *root = NULL;
    char str[100];
    scanf("%s",str);
    postFix(root , str);
}