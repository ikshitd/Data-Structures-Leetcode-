#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h> 
#define mxN 20
char stack[mxN] ; 
int top = -1 ;
bool isempty(){
    return top == -1 ;
}
bool isfull(){
    return top == mxN - 1 ;
}
char peek(){
    return stack[top] ; 
}
char pop(){
    if(isempty()){
        return -1 ; 
    }
    char c = stack[top] ; 
    top -= 1 ; 
    return c ;
}
void push(char a){
    if(isfull()){
        return ;
    }
    top += 1 ; 
    stack[top] = a ; 
    return ; 
}
bool checkoperand(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ; 
}
int precedence(char c){
    switch(c){
        case '+': 
        case '-': 
            return 1 ;
        case '*': 
        case '/':
            return 2 ; 
        case '^': 
            return 3 ; 
        default : 
            return -1; 
    }
}
void getpostfix(char arr[]){
    int i , j ; 
    for(i = 0 , j = -1 ; arr[i] != '\0' ; i++){
        // if it is an operand ;
        if(checkoperand(arr[i])){
            arr[++j] = arr[i] ;
        }
        else if(arr[i] == '('){
            push(arr[i]) ; 
        }
        else if(arr[i] == ')'){
            while(!isempty() && peek() != '('){
                arr[++j] = pop() ; 
            }
            if(!isempty() && peek() != '('){
                return ;// invalid expression 
            }
            else{
                pop() ; 
            }
        }
        // it is an operator 
        else{
            while(!isempty() && precedence(arr[i]) < precedence(peek())){
                arr[++j] = pop() ;
            }
            push(arr[i]) ;
        }
    }
    while(!isempty()){
        arr[++j] = pop() ;
    }
    arr[++j] = '\0' ; 
}
void reverse(char *arr){
    int i = 0 , j = strlen(arr) - 1 ; 
    while(i <= j){
        char a = arr[i] ; 
        arr[i] = arr[j] ; 
        arr[j] = a ; 
        i += 1; 
        j -= 1 ;
    }
    return ;
}
void brackets(char arr[]){
    int n = strlen(arr) ; 
    for(int i = 0 ; i < n ;i++){
        if(arr[i] == '('){
            arr[i] = ')' ;
        }
        else if(arr[i] == ')'){
            arr[i] = '(' ;
        }
    }
    return ;
}
void infixtoprefix(char arr[]){
    reverse(arr) ; 
    brackets(arr) ;
    getpostfix(arr) ;
    reverse(arr) ;
    printf("%s" , arr) ; 
    return ;
}
int main(){
    char arr[] = "K+L-M*N+(O^P)*W/U/V*T+Q" ;
    infixtoprefix(arr) ; 
    return 0 ;
}
