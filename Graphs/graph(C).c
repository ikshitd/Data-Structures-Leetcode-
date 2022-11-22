#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
// this will represent a node in the adjecency list 
typedef struct Node{
	int data ; 
	struct Node *next ;
}Node; 

// structure to represent adjecency list 
typedef struct AdjList{
	Node *head ;
}AdjList;

// structure to represent the whole graph 
typedef struct Graph{
	int v ; 
	// number of vertices 
	struct AdjList * array ; 
}Graph ;

Graph *createGraph(int v){
	Graph *gr = (Graph *)malloc(sizeof(Graph)) ;
	gr -> v = v ; 
	gr -> array = (AdjList *)malloc(sizeof(AdjList)) ; 
	// initialize each of the list with null 
	for(int i = 0 ; i < v ; i++){
		gr -> array[i].head = NULL ; 
	}
	return  gr ;
}
void addEdge(Graph *gr , int u , int v){
	Node *node = (Node *)malloc(sizeof(Node)) ; 
	node -> data = v ; 
	node -> next = NULL ;
	if(gr -> array[u].head == NULL){
		node -> next = gr -> array[u].head ; 
		gr -> array[u].head = node ; 
	}
	else{
		Node *current = gr -> array[u].head ; 
		while(current -> next){
			current = current -> next ;
		}
		current -> next = node ; 
	} 
	node = (Node *)malloc(sizeof(Node)) ; 
	node -> data =  u ; 
	node -> next = NULL ;
	if(gr -> array[v].head == NULL){
		node -> next = gr -> array[v].head ; 
		gr -> array[v].head = node ; 
	}
	else{
		Node *current = gr -> array[v].head ; 
		while(current -> next){
			current = current -> next ;
		}
		current -> next = node ;
	}
}
void display(Graph *gr){
	for(int i = 0 ; i < gr -> v ;i++){
		Node *current = gr -> array[i].head ; 
		printf("%d ---->" , i) ;
		while(current){
			printf("%d -->" , current -> data) ;
			current = current -> next ;
		}
		printf("\n") ;
	}
}
void solve(){
	Graph *gr = createGraph(4) ; 
	addEdge(gr , 1 , 2) ; 
	addEdge(gr , 0 , 1) ; 
	addEdge(gr , 2 , 3) ;
	display(gr) ;
	return ;
}
int main(){
	int t = 1 ; 
	while(t--){
		solve() ;
	}
	return 0;
}
