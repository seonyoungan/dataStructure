#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 7
#define INF 50

typedef struct GraphType {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES]={0};
int distance[MAX_VERTICES];

// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i <n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v])) v = i;
	return (v);
}
//prim의 MST 알고리즘
void prim(GraphType* g, int s){
	int i, u, v;

	for (u = 0; u<g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for (i = 0; i<g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) return;
		printf("정점 %d 추가\n", u);
		for (v = 0; v<g->n; v++){
			if (!selected[v] && g->weight[u][v] < distance[v]) {
				distance[v] = g->weight[u][v];
			}
			printf("%d ", distance[v]);
	}
	printf("\n");
    }
}

int main(void)
{
	GraphType g = { 7,
	{{INF, 3, 17, 6, INF, INF, INF},
	 {3, INF, INF, 5, INF, INF, 12},
	 {17, INF, INF, INF, 10, 8, INF},
	 {6, 5, INF, INF, 9, INF, INF},
	 {INF, INF, 10, 9, INF, 4, 2},
	 {INF, INF, 8, INF, 4, INF, 14},
	 {INF, 12, INF, INF, 2, 14, INF} }
	};
	prim(&g, 0);
	return 0;
}
