#include <stdio.h>
#define n 5
int arr[n][2] ;
int avail = 0 , l = -1 , temp = -1 ;

void create(int val) {
    if (arr[avail][1] != -1) {
        // list
        if(l == -1){
            l = avail ;
            temp = avail;
            avail = arr[avail][1]  ;
            arr[temp][0] = val ;
            arr[temp][1] = -1 ;
        }
        else{
            int a = temp ; 
            temp = avail ; 
            arr[a][1] = temp ; 
            avail = arr[avail][1] ; 
            arr[temp][0] = val ; 
            arr[temp][1] = -1 ; 
        }
    }
    else{
        return ; 
    }
}
void display(){
    int i = l ;
    while(i != -1){
        printf("%d " , arr[i][0]) ; 
        i = arr[i][1] ; 
    }
    printf("\n") ;
}

void insertatbeginning(int val){
    if(avail == -1){
        return ; 
    }
    else{
        temp = avail ; 
        avail = arr[avail][1] ; 
        arr[temp][0] = val ; 
        arr[temp][1] = l ; 
        l = temp ; 
    }
}
void insertatend(int val){
    int i = l  ; 
    while(arr[i][1]  != -1 ){
        i = arr[i][1] ; 
    }
    if(avail == -1){
        return ; 
    }
    else{
        temp = avail ; 
        arr[i][1] = temp ; 
        avail = arr[avail][1 ] ; 
        arr[temp][0] = val ; 
        arr[temp][1] = -1 ; 
    }
}

void deleteatbeginning(){
    l = arr[l][1] ; 
}
void deleteatend(){
    int i = l ; 
    int j = i ; 
    while(arr[i][1] != -1){
        j = i ; 
        i = arr[i][1] ; 
    }
    arr[j][1] = -1 ; 
}
int main() {
    int i = 0 ;
    for (i ; i < n - 1 ; i++) {
        arr[i][1] = i + 1;
    }
    arr[i][1] = -1 ;
    create(10) ; 
    create(20) ; 
    create(30) ; 
    insertatbeginning(50) ; 
    insertatend(90) ; 
    deleteatend();
    display() ; 
    for (int i = 0 ; i < n ; i++) {
        printf("%d %d\n", arr[i][0] , arr[i][1]) ;
    }
    printf("\n") ;
}
