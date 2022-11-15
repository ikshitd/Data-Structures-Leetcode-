#include <stdio.h> 
#include <stdbool.h> 
#include <stdlib.h>
#define mx 5 

int front = -1 ; 
int rear = -1 ; 
int queue[mx] ; 

bool isempty(){
	return front == -1 ; 
}
bool isfull(){
	return rear == mx - 1 ; 
}
int size(){
	return rear + 1 ; 
}
int peek(){
	if(front == -1){
		return -1 ; 
	}
	else{
		return queue[front] ; 
	}
}
void enqueue(int val){
	// first check if the queue is full or not 
	// if it is full then return 
	if(rear == mx - 1){
		return ; 
	}
	if(rear == -1 && front == -1){
		front = 0 ; 
		rear = 0 ; 
	}
	else{
		rear += 1 ; 
	}
	queue[rear] = val ; 
	return ; 
}

int dequeue(){
	// if there is any element in the queue or not 
	if(front == -1 || front > rear){
		return -1 ; 
	}
	else{
		int item = queue[front] ;
		// this suggests that there is only one element
		if(front == rear){
			front = -1 ; 
			rear = - 1; 
		}
		else{
			front = front + 1 ; 
		}
		return item ; 
	}
}
void display(){
	if(rear == -1){
		printf("The queue is empty") ; 
		return ; 
	}

	else{
		for(int i = front ; i <= rear ; i++){
			printf("%d " , queue[i]) ; 
		}
		printf("\n") ; 
	}
}

int main(){
	enqueue(10) ; 
	enqueue(20) ; 
	enqueue(30) ; 
	enqueue(50) ; 
	display() ; 
	int a = dequeue() ; 
	display() ; 
	printf("%d" , a) ; 
}
