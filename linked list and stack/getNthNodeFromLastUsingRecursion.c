// Simple C++ program to find n'th node from end 
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
struct Node { 
	int data; 
	struct Node* next; 
}; 

/* Function to get the nth node from the last of a linked list*/
int printNthFromLast(struct Node* head, int n,int *count) 
{ 
	if(head == NULL)
      	return 0;
 	printNthFromLast(head->next,n,count);
  	*count=*count+1;
  	if(*count == n)
      return head->data;
} 

void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = new Node(); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

// Driver Code 
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 
	// create linked 35->15->4->20 
  int count= 0;
	push(&head, 20); 
	push(&head, 4); 
	push(&head, 15); 
	push(&head, 35); 

	printf("%d",printNthFromLast(head, 4,&count)); 
	return 0; 
} 
