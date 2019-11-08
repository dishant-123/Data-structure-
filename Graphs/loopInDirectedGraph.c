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
void createGraph(struct adjList **arr , int E){
	//undirected graph
	int i,src,dest;
	for(i=0 ; i < E ;i++){
	    scanf("%d %d",&src,&dest);
	    insert(arr,src,dest);
	}
}
int checkLoop(int v, struct adjList **arr, char *visited, int parent){
	visited[v] = '1';
	struct adjList *iterate = arr[v];
	while(iterate){
		if(visited[iterate->data]=='0'){
			if(checkLoop(iterate->data, arr, visited, v)){
				return 1;
			}
		}
		else if(iterate->data != parent){
			return 1;
		}
		iterate = iterate->next;
		
	}
}
int main(){
	int V,E,dfsNode,i,cycle=0;
	scanf("%d %d",&V, &E); //no of vertices and edges
	struct adjList **arr = (struct adjList **)calloc(sizeof(struct adjList *),  V);
	createGraph(arr , E);
	char *visited = (char *)malloc(sizeof(char)*V);
	for(i=0;i<V;i++){
		visited[i]='0';
	}
	for(i=0; i<V; i++){
		if(visited[i]=='0'){
			if(checkLoop(i ,arr ,  visited, -1)==1){
				cycle = 1;
			}
		}
	}
	if(cycle == 1)
		printf("Cycle is present");
	else
		printf("Cycle is not present");
}
