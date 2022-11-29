#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
typedef struct Edge{
    int w , x , y ; 
}Edge;

int *parent ; 
int *rank ;
void init(int n){
    parent = (int *)malloc(sizeof(int) * (n + 1)) ; 
    rank = (int *)malloc(sizeof(int) * (n + 1)) ; 
    for(int i = 1 ; i <= n ; i++){
        parent[i] = -1 ;
        rank[i] = 1 ;
    }
}
int findset(int x){
    if(parent[x] == -1){
        return x ;
    }
    return parent[x] = findset(parent[x]) ;
}
void unite(int x , int y){
    int s1 = findset(x) ; 
    int s2 = findset(y) ; 
    
    if(s1 != s2){
        if(rank[s1] < rank[s2]){
            parent[s1] = s2 ; 
            rank[s2] += rank[s1] ;
        }
        else{
            parent[s2] = s1 ; 
            rank[s1] += rank[s2] ;
        }
    }
    return ;
}
typedef struct Graph{
    int V , E ; 
    Edge *edgelist ;  
}Graph;

Graph *createGraph(int V , int E){
    Graph *gr = (Graph *)malloc(sizeof(Graph)) ; 
    gr -> V = V ; 
    gr -> E = E ; 
    gr -> edgelist = (Edge *)malloc((gr -> E  + 1 ) * sizeof(Edge)) ; 
    return gr ; 
}
bool comp(const Edge *a , const Edge *b){
    return a -> w < b -> w ;
}
int kruskal_mst(Graph *gr){
    qsort(gr -> edgelist , gr -> E, sizeof(gr -> edgelist[0]), comp) ; 
    int answer = 0 ; 
    for(int i = 1 ; i <= gr -> V ; i++){
        int s1 = findset(gr -> edgelist[i].x) ; 
        int s2 = findset(gr -> edgelist[i].y) ; 
        if(s1 != s2){
            unite(s1 , s2) ; 
            answer += gr -> edgelist[i].w ; 
        }
    }
    return answer ; 
}
int main(){
    int n , m ; 
    scanf("%d %d" , &n , &m) ; 
    Graph *gr = createGraph(n , m) ; 
    for(int i = 1 ; i <= m ; i++){
        int x , y  , w; 
        scanf("%d %d %d" , &x , &y , &w) ; 
        gr -> edgelist[i].w = w ; 
        gr -> edgelist[i].x = x ; 
        gr -> edgelist[i].y = y ; 
    }
    int ans = kruskal_mst(gr) ; 
    printf("%d " , ans) ; 
    return 0 ;
}
