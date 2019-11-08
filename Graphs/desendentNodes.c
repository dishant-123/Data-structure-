#include<stdio.h>
#include<stdlib.h>
struct adjList{
	int data;
	int timeIn;
	int timeOut;
	struct adjList *next;
};
struct adjList * createNode(int dest){
    struct adjList *newNode = (struct adjList *)malloc(sizeof(struct adjList));
    newNode->data = dest;
    newNode->next = NULL;
    newNode->timeIn= 0;
    newNode->timeOut= 0;
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
int time;
void createDesedent(struct adjList ** arr, int v, char *visited){
	visited[v]='1';
	time += 1;
	arr[v]->timeIn = time;
	struct adjList *iterate = arr[v];
	while(iterate){
		if(visited[iterate->data]=='0'){
			createDesedent(arr, iterate->data , visited);
		}
		iterate = iterate->next;
	}
	arr[v]->timeOut = time;
	time += 1;
}
void desendent(struct adjList **arr, int p, int c,char *visited){
	createDesedent(arr, 0 , visited);
	if(arr[p]->timeOut- arr[p]->timeIn > arr[c]->timeOut- arr[c]->timeIn){
		printf("Yes these are decendent");
	}
	else{
		printf("No these are not decendent");
	}
}
int main(){
	int V,E,dfsNode,i,cycle=0,parent,child;
	time = 0 ;
	scanf("%d %d",&V, &E); //no of vertices and edges
	struct adjList **arr = (struct adjList **)calloc(sizeof(struct adjList *),  V);
	createGraph(arr , E);
	char *visited = (char *)malloc(sizeof(char)*V);
	for(i=0;i<V;i++){
		visited[i]='0';
	}
	scanf("%d %d",&parent, &child);
	desendent(arr , parent, child, visited);
}
