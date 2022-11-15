#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
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
    if(top == -1){
        return -1;  
    }
    char c =stack[top] ; 
    top -= 1 ; 
    return c ;
}
void push(char a){
    if(isfull()){
        return ;
    }
    top += 1 ;
    stack[top] = a ;
}
bool checkopearand(char c){
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
            return -1 ;
    }
}
void convertinfixtopostfix(char arr[]){
    int i , j ; 
    char ans[mxN] ;
    for(i = 0 , j = -1 ; arr[i] != '\0' ; i++){
        if(checkopearand(arr[i])){
            ans[++j] = arr[i] ;
        }
        else if(arr[i] == '('){
            push(arr[i]) ; 
        }
        else if(arr[i] == ')'){
            while(!isempty() && peek() != '('){
                ans[++j] = pop() ;
            }
            if(!isempty() && peek() != '('){
                printf("Invalid") ;
                return ;
            }
            else{
                pop() ;
            }
        }
        else{
            while(!isempty() && precedence(arr[i]) <= precedence(peek())){
                ans[++j] = pop() ; 
            }
            push(arr[i]) ;
        }
    }
    while(!isempty()){
        ans[++j] = pop() ;
    }
    ans[++j] = '\0' ;
    printf("%s" ,ans) ; 
    return ;
}
int main(){
    char exp[] = "((a+(b*c))-d)" ; 
    convertinfixtopostfix(exp) ; 
    return 0 ;
}
