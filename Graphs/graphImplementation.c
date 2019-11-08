#include<stdio.h>
#include<stdlib.h>
struct adjList{
	int data;
	struct adjList *next;
};
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
int main(){
	int V,E;
	scanf("%d %d",&V, &E); //no of vertices and edges
	struct adjList **arr = (struct adjList **)calloc(sizeof(struct adjList *),  V);
	createGraph(arr , E);
	print(arr , V);
	
}
