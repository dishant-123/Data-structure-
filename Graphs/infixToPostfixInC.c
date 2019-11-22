#include<stdio.h>
#include<stdlib.h>
struct stack{
    char data;
    struct stack *next;
};
// struct stack *newNode(char data){
    
//     return node;
// } 
struct stack *push(struct stack *root,char data){
    // struct stack *node = newNode(data);
    struct stack * node = (struct stack *)malloc(sizeof(struct stack));
    node->data = data;
    node->next = NULL;
    node->next = root;
    root = node;
    return root;
}
struct stack * pop(struct stack *root){
    if(root == NULL)
        printf("Empty Pop");
    root = root->next;
    return root;
}
char top(struct stack *root){
    return root->data;
}
int empty(struct stack *root){
    if(root == NULL)
        return 1;
    else 
        return 0;
}
int weight(char a){
    if(a == '*' || a == '/')
        return 2;
    else 
        return 1;
}
int precedence(char a, char b){
    int w1 = weight(a);
    int w2 =weight(b);
    return w1>=w2?1:0;
}
int main(){
    struct stack *root = NULL;
    char str[100];
    int i,k=0;
    scanf("%s",str);
    char res[100];
    for(i=0;str[i];i++){
        if((str[i] >=65 && str[i]<= 90) || (str[i] >=97 && str[i]<= 122)){
            // 
            res[k++]=str[i];
        }
        else if(str[i]=='*'||str[i]=='/' || str[i]  == '+' || str[i] =='-'){
            while(empty(root)!=1 && precedence(top(root),str[i])){
                // printf("HEllo");
                res[k++] = str[i];
                root = pop(root);
            }
            root  = push(root,str[i]);
            // printf("%c",top(root));
        }
    }
    while(empty(root)!=1){
        res[k++] = top(root);
        pop(root);
    }
    for(i=0;i<k;i++){
            printf("%c",res[i]);
    }
}
