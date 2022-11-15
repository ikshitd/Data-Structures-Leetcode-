#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node{
  int data ; 
  struct Node *next ; 
}Node ; 

Node *insertathead(Node *head , int val){
    Node *node = (Node *)malloc(sizeof(Node)) ; 
    node -> data = val ; 
    if(head == NULL){
      node -> next = node ; 
      head = node ; 
      return head ; 
    }
    Node *current = head ; 
    while(current -> next != head){
      current = current -> next ; 
    }
    current -> next = node ; 
    node -> next =head ; 
    head = node ; 
    return head ; 
}

Node *insertattail(Node *head , int val){
  if(head == NULL){
    return insertathead(head , val) ; 
  }
  Node *node = (Node *)malloc(sizeof(Node)) ; 
  node -> data = val ; 
  Node *current = head ; 
  while(current -> next != head){
    current = current -> next ; 
  }
  current -> next = node ; 
  node -> next = head ; 
  return head ; 
}

Node *deleteatbeginning(Node *head){
  Node *current = head ; 
  while(current -> next != head){
    current = current -> next ; 
  }
  Node *todelete = head ; 
  current -> next = head -> next;
  head = head -> next  ; 
  free(todelete) ; 
  return head ; 
}

Node *delete(Node *head , int pos){
  if(pos == 1){
    return deleteatbeginning(head) ; 
  }
  Node *current = head ;
  int cnt = 1 ; 
  while(cnt != pos -1){
    current = current -> next ; 
    cnt += 1 ; 
  }
  Node *todelete = current -> next ; 
  current -> next = current -> next -> next ; 
  free(todelete) ; 
  return head ; 
}
void display(Node *head){
    Node *current = head ;
    do{
        printf("%d " , current -> data) ;
        current = current -> next ; 
    }while(current != head) ; 

}
int main(){
  Node *head = NULL ; 
  head = insertathead(head , 1) ; 
  head = insertathead(head , 2) ; 
  head = insertattail(head , 3) ; 
  head = insertattail(head , 9) ; 
  head = insertattail(head , 10) ; 
  head = deleteatbeginning(head) ; 
  display(head) ; 

}
