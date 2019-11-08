#include<stdio.h>
#include<stdlib.h>
//not complete //
struct adjList{
	int data;
	struct adjList *next;
};
struct queue{
	int data;
	int next;
};
struct queue * createQueueNode(int dest){
    struct queue *newNode = (struct queue *)malloc(sizeof(struct queue));
    newNode->data = dest;
    newNode->next = NULL;
    return newNode;
}
struct adjList * createNode(int dest){
    struct adjList *newNode = (struct adjList *)malloc(sizeof(struct adjList));
    newNode->data = dest;
    newNode->next = NULL;
    return newNode;
}
void insert(struct adjList **arr,int src,int dest){
        struct adjList * newNode = createNode(dest);
        newNode->next = arr[src];
        arr[src] = newNode;
        struct adjList * newNode1 = createNode(src);
        newNode1->next = arr[dest];
        arr[dest] = newNode1;
}
void print(struct adjList **arr, int V){
    int i;
    printf("Adjacency List \n");
	for(i=0 ; i < V ; i++){
    	struct adjList *iterate = arr[i];
    	printf("%d ",i);
    	while(iterate){
    	    printf("%d ",iterate->data);
    	        iterate = iterate->next;
    	 }
    	 printf("\n");
    }
}
void createGraph(struct adjList **arr , int E){
	//undirected graph
	int i,src,dest;
	for(i=0 ; i < E ;i++){
	    scanf("%d %d",&src,&dest);
	    insert(arr,src,dest);
	}
}
struct queue *push(struct queue *root ,int value){
	struct queue *newNode = createQueueNode(value);
	
	if(root == NULL){
		root = newNode;
	}
	struct queue *iterate = root;
	while(iterate->next!=NULL){
		iterate = iterate->next;
	}
	iterate->next = newNode;
	return root;
}
int peek(struct queue *root){
	return root->data;
}
void pop(struct queue *root){
	root=root->next;
}
int empty(struct queue *root){
	return (root == NULL ? 1 : 0);
}
//void printBFS(struct adjList **arr, char *visited){
//	struct queue *Queue = NULL;
//	Queue = push(Queue,0);
//	while(empty(Queue)!=1){
//		int s = peek(Queue);
//		printf("%d ",s);
//		pop(Queue);
//		visited[s]='1';
//		struct adjList *iterate = arr[s];
//		while(iterate){
//			if(visited[iterate->data] == '0'){
//				Queue = push(Queue, iterate->data);
//			}
//			iterate=iterate->next;
//		}
//	}
//}
int main(){
	int V,E,dfsNode,i;
	scanf("%d %d",&V, &E); //no of vertices and edges
	struct adjList **arr = (struct adjList **)calloc(sizeof(struct adjList *),  E);
	createGraph(arr , E);
	//print(arr , V);
	char *visited = (char *)malloc(sizeof(char)*V);
	for(i=0;i<V;i++){
		visited[i]='0';
	}
//	printBFS(arr,visited);
struct queue *Queue = NULL;
	Queue = push(Queue,0);
	Queue = push(Queue,1);
	Queue = push(Queue,2);
	Queue = push(Queue,3);
	printf("%d \n",peek(Queue));
	pop(Queue);
	printf("%d \n",peek(Queue));
}
