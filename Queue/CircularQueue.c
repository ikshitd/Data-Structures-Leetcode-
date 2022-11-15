#include <stdio.h> 
#include <stdbool.h> 
#define mx 5 

int queue[mx] ;
int front = -1 , rear = -1 ; 

bool isFull(){
	// if front is just after the rear or rear =- mx - 1 and front == 0
	if((front == rear + 1) || (front == 0 &&  rear == mx - 1)){
		return true ; 
	}
	return false ; 
}
bool isempty(){
	// if the front hasn't moved then is queue is empty
	if(front == -1){
		return true ; 
	}
	return false ; 
}
void enqueue(int val){
	// check if the queue is full or not 
	if(isFull()){
		printf("The queue is full") ; 
		return ; 
	}
	else{
		// if there is no element in the queue 
		if(front == -1){
			front = 0 ; 
		}
		// move the rear += 1  and take % mx ; 
		rear = (rear + 1) % mx ; 
		// insert the value
		queue[rear] = val ; 
	}
}

int dequeue(){
	int a ;
	// check if the queue is empty or not 
	if(isempty()){
		return -1 ; 
	}
	else{
		// pick the very first element whose value is to be removed ; 
		a = queue[front] ; 
		// check if there is only one element 
		if(front == rear){
			front = -1 ; 
			rear = -1 ; 
		}
		else{
			// increment the value of front by 1 
			front = (front + 1) % mx ; 
		}
	}
	return a ; 
}
void display(){
	int i ; 
	if(isempty()){
		printf("The queue is empty"); 
		return ; 
	}
	else{
		for(i = front ; i != rear ; i = (i + 1) % mx){
			printf("%d " , queue[i]) ; 
		}
		printf("%d " , queue[i]) ; 
		// printf("%d " , queue[i]) ; 
		printf("\n") ; 
	}
	return ; 
}
int main(){
	enqueue(10) ; 
	enqueue(20) ; 
	enqueue(30) ; 
	enqueue(40) ; 
	enqueue(50) ; 
	display() ; 
	int a = dequeue() ; 
	display() ; 
	enqueue(99) ; 
	display() ; 
}
