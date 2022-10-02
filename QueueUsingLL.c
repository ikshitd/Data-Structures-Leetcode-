#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
typedef struct Node{
	
	int data ; 
	struct Node *next ; 

}Node ; 

Node *head= NULL ; 
Node *tail = NULL ;

void enqueue(int val){

	Node *node = (Node *)malloc(sizeof(Node)) ; 
	node -> data = val  ; 
	node -> next = NULL ; 
	if((head == NULL) && (tail == NULL)){
		head = tail = node ; 
	}
	else{
		tail -> next = node ; 
		tail = node ; 
	}
}
int dequeue(){
	if(head == NULL){
		return -1 ; 
	}
	else{
		int temp = head -> data ; 
		head = head -> next ; 
		return temp ; 
	}
}
int front(){
	if(head == NULL){
		return -1 ; 
	}
	else{
		return head -> data ; 
	}
}
void display(){
	Node *current ; 
	if(head == NULL && (tail == NULL)){
		printf("The queue is empty") ; 
		return ; 
	}
	else{
		current = head ; 
		while(current) {
			printf("%d -->" , current -> data) ; 
			current = current -> next ; 
		}
		printf("NULL\n") ; 
		return ; 
	}
}
int main(){
	enqueue(10) ; 
	enqueue(20) ; 
	enqueue(30) ; 
	enqueue(40) ; 
	display() ; 
	int a  =dequeue() ; 
	printf("%d" , a) ; 
	display() ; 
}
