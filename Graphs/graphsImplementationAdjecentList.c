#include<stdio.h>
struct adjListNode{
	int dest;
	struct adjListNode *next;
};
struct adjList{
	struct adjListNode *head;
};
struct Graph{
	int v;
	struct adjList *array;
};
struct adjListNode * newAdjListNode(int dest){
	struct adjListNode *newNode = (struct adjListNode *) malloc(sizeof(adjListNode));
	newNode->next=NULL;
	newNode->dest=dest;
	return newNode;
}
struct Graph *createGraph(int v){
	struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
	graph->v=v;
	graph->array = (struct adjList *)malloc(sizeof(struct adjList)*v);
	int i;
	for(i=0;i<v;i++){
		graph->array[i].head=NULL;
	}
	return graph;
}
void addEdge(struct Graph *graph,int src,int desc){
	struct adjListNode *newNode = newAdjListNode(desc);
	newNode->next = graph->array[src].head;
	graph->array[src].head=newNode;
	//for undirected graph 0->1 = 1->0
	struct adjListNode *newNode = newAdjListNode(src);
	newNode->next = graph->array[desc].head;
	graph->array[desc].head=newNode;
}
void print(struct Graph *graph){
	int i;
	for(i=0;i<graph->v;i++){
		struct adjListNode *iterate = graph->array[i].head;
		while(iterate){
			printf("%d ",iterate->dest);
			iterate = iterate->next;
			
		}
		printf("\n");
	}
}
int main(){
	int V = 5;//no of vertices
	struct Graph *graph = createGraph(V);
	addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4);
    print(graph);
	return 0;
}
