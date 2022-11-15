#include <stdio.h>
#include <stdlib.h> 
typedef struct Node {
    int data ;
    struct Node *next ;
    struct Node *prev ;
} Node;
Node *head = NULL ;
Node *tail = NULL ;
int len(){
    if(head == NULL){
        return 1 ; 
    }
    int cnt = 0 ;
    Node *current = head ; 
    do{
        cnt += 1 ; 
        current = current -> next ;
    }while(current != head) ; 
    return cnt ; 
}
Node *insertatbeginning(int val){
    Node *node = (Node *)malloc(sizeof(Node)) ; 
    node -> data = val ; 
    if(head == NULL){
        node -> next = node ; 
        node -> prev = node ; 
        head = tail = node ; 
    }
    else{
       node -> next = head ; 
       node -> prev = tail ; 
       tail -> next = node ; 
       head -> prev = node ; 
       head = node ; 
    }
    return head ; 
}
Node *insertatend(int val){
    Node *node = (Node *)malloc(sizeof(Node)); 
    node ->data = val ;
    if(head == NULL){
        node -> next = node ; 
        node -> prev = node; 
        head = tail = node ; 
    }
    else{
        tail -> next =node ; 
        node -> prev = tail ; 
        node -> next = head ; 
        head -> prev = node ; 
        tail = node ; 
    }
    return head ; 
}
Node *insertatposn(int val , int k){
    Node *node = (Node *)malloc(sizeof(Node)) ;
    node -> data = val ; 
    if(head == NULL){
        return insertatbeginning(val) ; 
    }
    int cnt = 0 ; 
    Node *current = head ; 
    while(current){
        if(cnt == k - 1){
            break ; 
        }
        current = current -> next ; 
        cnt += 1 ; 
    }
    Node *next_node = current -> next ; 
    current -> next = node ; 
    node -> next =next_node ; 
    next_node -> prev = node ; 
    node -> prev = current ; 
    return head ; 
}
Node *deletefrombeginning(){
    if(head == NULL){
        return NULL ; 
    }
    if(head == tail){
        free(head) ; 
        return NULL ;
    }
    else{
        Node *del = head ;
        Node *dummy = head -> next ; 
        dummy -> prev = tail  ;
        tail -> next = dummy ;
        head = dummy ; 
        free(del) ; 
    }
    return head ;
}
Node *deletefromend(){
    if(head == NULL){
        return NULL ; 
    }
    if(head == tail){
        free(head) ; 
        return NULL ; 
    }
    else{
        Node *del = tail;  
        Node *prev_node = tail -> prev ; 
        prev_node -> next = head ; 
        head -> prev = prev_node  ; 
        tail = prev_node ; 
        free(del) ; 
    }
    return head ;
}
Node *delefromposn(int k){
    if(k == 0 || head == NULL || head == tail){
        return deletefrombeginning() ; 
    }
    if(k == len() - 1){
        return deletefromend() ;
    }
    else{
        int cnt = 0 ; 
        Node *current = head ; 
        while(current){
            if(cnt == k) break ;
            current = current -> next ;
            cnt += 1 ;
        }
        Node *prev_node = current -> prev ; 
        Node *next_node = current -> next ; 
        prev_node -> next = next_node ; 
        next_node -> prev = prev_node ; 
        free(current) ; 
    }
    return head ; 
}
void display(){
    if(head == NULL){
        return ; 
    }
    Node *current = head ; 
    do{
        printf("%d " , current -> data) ; 
        current = current -> next ; 
    }while(current != head) ; 
    return ; 
}
int main(){
    head = insertatbeginning(10) ; 
    head = insertatbeginning(20) ; 
    head = insertatbeginning(30) ; 
    head = insertatend(40) ; 
    head =insertatposn(50 , 2) ;
    head = delefromposn(2) ; 
    display() ; 
}
