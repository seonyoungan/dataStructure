
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

int parent[MAX_VERTICES]; //부모노드

void set_init(int n){ //초기화
    for(int i = 0; i < n;i++){
        parent[i] = -1;
    }
}

int set_find(int curr){ //curr속한 집합 반환
    if(parent[curr]==-1)
        return curr;
    while(parent[curr]!=-1)
        curr=parent[curr];
    return curr;
}

//두개 원소가 속한 집합 합침
void set_union(int a, int b){
    int root1 = set_find(a); //루트1찾기
    int root2 = set_find(b); //루트2찾기
    if(root1!=root2){
        parent[root1] = root2;
    }
}

typedef struct Edge{ //간선 나타내는 구조체
    int start, end, weight;
} Edge;

//그래프 구조체
typedef struct GraphType{
    int n;
    struct Edge edges[2*MAX_VERTICES];
} GraphType;


//그래프 초기화
void graph_init(GraphType *g){
    g->n=0;
    for(int i=0;i<2*MAX_VERTICES;i++){
        g->edges[g->n].start = 0;
        g->edges[g->n].end = 0;
        g->edges[g->n].weight = INF;
    }
}

//간선삽입연산
void insert_edge(GraphType *g, int start, int end, int w){
        g->edges[g->n].start =start;
        g->edges[g->n].end = end;
        g->edges[g->n].weight=w;
        g->n++;
}

//qsort()에 사용되는 함수
int compare(const void *a, const void *b){
    struct Edge *x = (struct Edge*)a;
    struct Edge *y = (struct Edge*)b;
    return (x->weight - y->weight);
}
//kruskal
void kruskal(GraphType *g){
    int edge_accepted = 0;
    int uset, vset;
    struct Edge e;
    
    set_init(g->n);
    qsort(g->edges, g->n, sizeof(struct Edge), compare);
    printf("크루스칼 최소 신장 트리 알고리즘\n");
    
    int i =0;
    while(i<=g->n-1){
        e=g->edges[i];
        uset = set_find(e.start);
        vset = set_find(e.end);
        if(uset != vset){
            printf("간선 (%d, %d) %d 선택\n", e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset);
        }
        i++;
    }
}
int main() {
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    graph_init(g);
    
    insert_edge(g, 1, 2, 3);
    insert_edge(g, 1, 3, 17);
    insert_edge(g, 1, 4, 6);
    insert_edge(g, 2, 4, 5);
    insert_edge(g, 2, 7, 12);
    insert_edge(g, 3, 5, 10);
    insert_edge(g, 3, 6, 8);
    insert_edge(g, 4, 5, 9);
    insert_edge(g, 5, 6, 4);
    insert_edge(g, 5, 7, 2);
    insert_edge(g, 6, 7, 14);
    

    
    kruskal(g);
    free(g);
    return 0;
}
