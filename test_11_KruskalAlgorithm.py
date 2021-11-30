#https://debuglog.tistory.com/84
adj_mat = [(1,2,29),(1,6,10),(2,1,29),(2,3,16),(2,7,15),(3,2,16),
         (3,4,12),(4,3,12),(4,5,22),(4,7,18),(5,4,22),(5,6,27),
         (5,7,25),(6,1,10),(6,6,27),(7,2,15),(7,4,18),(7,5,25)]
adj_mat.sort(key = lambda x : x[2])

mst = []
n = 7
p = [0]

for i in range(1, n+1):
    p.append(i) #정점의 집합 대표

def find(u):
    if u!=p[u]:
        p[u] = find(p[u]) #경로압축시킴
    return p[u]

def union(u,v):
    root1=find(u)
    root2=find(v)
    p[root2] = root1

tree_edges = 0 #간선개수
mst_cost=0 #가중치합

while True:
    if tree_edges== n-1:
        break
    u,v,wt = adj_mat.pop(0)
    if find(u) != find(v):
        union(u,v)
        mst.append((u,v))
        mst_cost +=wt
        tree_edges +=1

print('최소신장트리:', mst)
print('최소신장트리 가중치:', mst_cost)
