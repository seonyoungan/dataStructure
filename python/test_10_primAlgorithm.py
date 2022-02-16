
#출처 : https://sexy-developer.tistory.com/58

INF = 999  #큰 값으로 지정
#인접행렬에 대한 선언 adj_mat
adj_mat = [[0,29, INF, INF, INF, 10, INF],
           [29, 0, 16, INF, INF, INF, 15],
           [INF, 16, 0, 12, INF, INF, INF],
           [INF, INF, 12, 0, 22, INF, 18],
           [INF, INF, INF, 22, 0, 27, 25],
           [10, INF, INF, INF, 27, 0, INF],
           [INF, 15, INF, 18, 25, INF, 0]]

'''
주어진 인접행렬에서, PRIM알고리즘을 토앻 최소신장트리 구하기
입력 : 인접행렬, 시작정점
출력 : 시작정점에서 만든 최소 신장 트리

알고리즘
1. distances배열을 INF로 초기화한다.
2. distances[start]=0
3. 우선순위 큐queue에 모든 정점을 삽입(우선순위는 distances[])
4. i는 0부터 n-1까지 반복
    1). u에 weight가 가장 작은 간선 삽입
    2). u의 인접 정점들인 v를 반복
        v가 Q의 원소이고, weight[u][v] < dist[v]라면
            dist[v]에 weight[u][v]를 할당

설명:
0. 프림 알고리즘은 시작 정점을 최초의 신장 트리로 놓는다.
1. 시작 정점만이 포함된 신장 트리에서, 더 포함시킬 수 있는 노드들을 찾아놓는다.
2. 더 포함시킬수 있는 노드 중, 비용(가중치)가 가장 작은 노드를 포함시킨다.
3. 2에서 포함된 정점에서 가장 낮은 비용으로 도달할 수 있는 노드를 찾아서, 
	그 노드를 신장 트리에 포함시킨다.
'''
node_num = len(adj_mat) #node number를 구하는 것은 매트릭스의 크기
visited = [False] * node_num #전체 초기화 false로 방문했는지 여부 확인
distances = [INF] * node_num #거리배열

def get_min_node(node_num): #미니멈 노드 찾는 함수
    for i in range(node_num): #node_num값을 받은 후 i에 이 값이 있으면
        if not visited[i]: #방문하지 않은 게 있으면 v = i, break
            v=i
            break
    for i in range(node_num): #방문하지 않으면서 i거리가 v거리보다 작으면 v = i
        if not visited[i] and distances[i] < distances[v]:
            v = i
    return v # 그렇지 않으면 그냥 v를 연결해서 v가 실행됨

#prim알고리즘
def prim(start, node_num): #시작노드부터 노드번호를 주고, 몇개인지 확인하는 과정
    for i in range(node_num):
        visited[i] = False #초기는 false로 초기화
        distances[i] = INF #거리도 INF로 지정

    distances[start] = 0 #초기시작노드는 0
    for i in range(node_num): #모든 i값에 대해 node_num을 찾음
        node=get_min_node(node_num) 
        visited[node] = True # node를 방문했다고 표시한다.

        for j in range(node_num):
            if adj_mat[node][j] != INF: #node[j]가 INF가 아닌 동안에
                if not visited[j] and adj_mat[node][j] < distances[j] : # 방문하지 않았고 adj_mat[node][j]가 distances[j] 보다 작으면
                    distances[j] = adj_mat[node][j] #adj_mat[node][j]를 distances[j]에 대입한다.

print(prim(0, node_num))
print("distances:", distances)
print("minmum cost : ", sum(distances))