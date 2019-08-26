#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode listnode;

listnode* listnode_new(int val) {
	listnode* node = (listnode *) malloc(sizeof(listnode));
	node->val = val;
	node->next = NULL;
	return node;
}

void addNode(listnode* A, int i){
	listnode* temp = listnode_new(i);
	listnode* t = A;
	while(t->next != NULL){
		t = t->next;
	}
	t->next = temp;
}

/*
 * Complete the function below.
 */
int isPalin(listnode* A){
listnode *start=A;
listnode *end=NULL;
listnode *i=A;
listnode *j=A;
while((j->next!=NULL && j!=NULL)&&((j->next->next!=NULL && j!=NULL)))
{
        j=j->next->next;
        i=i->next;
}
end=i->next;
i->next=NULL;
listnode *curr=end;
listnode *prev=NULL;
listnode *next=NULL;
while(curr!=NULL)
{
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
}
end=prev;
while(start && end)
{
    if(start->val!=end->val)
        return 0;
    start=start->next;
    end=end->next;
}
return 1;




}
int main(){
	int count = 0;
	int i;
	int v;
	scanf("%d",&count);
	scanf("%d",&v);
	listnode* A = listnode_new(v);
	for(i=0;i<count-1;i++){
		scanf("%d",&v);
		addNode(A,v);
	}
	if(isPalin(A) == 1) printf("true");
	else printf("false");
}

