#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node{
    int data ; 
    struct Node *left ; 
    struct Node *right ; 
}Node ;
void insert(Node **rootnode , int val){
    if(*rootnode == NULL){
        Node *node = (Node *)malloc(sizeof(Node)) ; 
        node -> data = val ; 
        node -> left = NULL ; 
        node -> right = NULL ;
        *rootnode = node ;
        return ;
    }
    else{
        if(((*rootnode)) -> data > val){
            insert((&(*rootnode) -> left) ,val) ;
        }
        else{
            insert((&(*rootnode) -> right) , val) ;
        }
    }
    return ;
}
void inordertraversal(Node **rootnode) {
    if(*rootnode == NULL){
        return ;
    }
    inordertraversal((&(*rootnode) -> left)) ; 
    printf("%d " , (*rootnode) -> data) ; 
    inordertraversal((&(*rootnode) -> right)) ;
    return ;
}
void preordertraversal(Node **rootnode){
    if(*rootnode == NULL){
        return ;
    }
    printf("%d " , (*rootnode) -> data) ;
    preordertraversal((&(*rootnode) -> left)) ; 
    preordertraversal((&(*rootnode) -> right)) ; 
    return ;
}
void postordertraversal(Node **rootnode){
    if(*rootnode == NULL){
        return ;
    }
    postordertraversal((&(*rootnode) -> left)) ; 
    postordertraversal((&(*rootnode) -> right)) ;
    printf("%d " , (*rootnode) -> data) ; 
    printf("\n") ;
    return ;
}
void search(Node **rootnode , int val){
    if(*rootnode == NULL){
        printf("The value does not exist") ;
        return ;
    }
    if((*rootnode) -> data == val){
        printf("The value is found") ; 
        return ;
    }
    else if((*rootnode) -> data > val){
        search((&(*rootnode) -> left) , val) ;
    }
    else{
        search((&(*rootnode) -> right) , val) ;
    }
    return ;
} 
Node *minvalue(Node **rootnode){
    Node *current = *rootnode ; 
    while(current != NULL && current -> left != NULL){
        current = current -> left ;
    }
    return current;
}
void delete(Node **rootnode , int val){
    if(*rootnode == NULL){
        return ;
    }
    if(((*rootnode) -> data) > val){
        delete((&(*rootnode) -> left) , val) ;
    }
    else if(((*rootnode) -> data) < val){
        delete((& (*rootnode) -> right) , val) ;
    }
    else{
        if((*rootnode) -> left == NULL && (*rootnode) -> right == NULL){
            free(*rootnode) ;
            return ;
        }
        else if((*rootnode) -> left == NULL){
            Node *temp = (*rootnode) -> right ; 
            (*rootnode) -> data = temp -> data; 
            free(temp) ;
        }
        else if((*rootnode) -> right == NULL){
            Node *temp = ((*rootnode) -> left) ;
            (*rootnode) -> data = temp -> data ; 
            free(temp) ;
        }
        else{
            Node *nodetobedeleted = minvalue((&(*rootnode) -> right)) ; 
            (*rootnode) -> data = nodetobedeleted -> data ; 
            delete((&(*rootnode) -> right) , nodetobedeleted -> data) ;
        }
    }
    return ;
}
int main(){
    Node *rootnode = NULL ;
    insert(&rootnode , 50) ; 
    insert(&rootnode , 30) ; 
    insert(&rootnode , 70) ; 
    insert(&rootnode , 20)  ; 
    insert(&rootnode , 40) ;
    insert(&rootnode , 60) ;
    insert(&rootnode , 80) ; 
    insert(&rootnode , 100) ;
    insert(&rootnode , 10) ;
    inordertraversal(&rootnode) ;
    delete(&rootnode , 20) ;
    printf("\n") ;
    inordertraversal(&rootnode) ;
    return 0 ;
}
