// C++ program to merge a linked list into another at 
// alternate positions 
#include <bits/stdc++.h> 
using namespace std; 

// A nexted list node 
class Node 
{ 
	public: 
	int data; 
	Node *next; 
}; 
void merge(Node *a,Node *b)
{
	Node *temp;
	Node *i=a,*j=b;
	while(i && j)
	{
		temp=j;
		
		j=j->next;
		temp->next=i->next;
		i->next=temp;
		i=i->next->next;
		
	}

}
/* Function to insert a node at the beginning */
void push(Node ** head_ref, int new_data) 
{ 
	Node* new_node = new Node(); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

/* Utility function to print a singly linked list */
void printList(Node *head) 
{ 
	Node *temp = head; 
	while (temp != NULL) 
	{ 
		cout<<temp->data<<" "; 
		temp = temp->next; 
	} 
	cout<<endl; 
} 

int main() 
{ 
	Node *p = NULL, *q = NULL; 
	push(&p, 3); 
	push(&p, 2); 
	push(&p, 1); 
	cout<<"First Linked List:\n"; 
	printList(p); 

	push(&q, 8); 
	push(&q, 7); 
	push(&q, 6); 
	push(&q, 5); 
	push(&q, 4); 
	cout<<"Second Linked List:\n"; 
	printList(q); 

	merge(p, q); 

	cout<<"Modified First Linked List:\n"; 
	printList(p); 

	cout<<"Modified Second Linked List:\n"; 
	printList(q); 

	return 0; 
} 

// This code is contributed by rathbhupendra 

