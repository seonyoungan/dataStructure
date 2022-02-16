# 너비우선탐색(queue이용)
# 클래스와 함수 선언 부분
class Graph():
    def __init__(self, size) :
        self.SIZE=size
        self.graph = [[0 for _ in range(size)] for _ in range(size)]

# 전역 변수 선언
G1 = None
stack = []
queue=[]
visitedAry=[] #방문한 정점

#메인 코드 부분
G1 = Graph(4)
G1.graph[0][2] = 1; G1.graph[0][3] = 1 #A-C A-D
G1.graph[1][2] = 1; #B-C
G1.graph[2][0] = 1; G1.graph[2][1] = 1; G1.graph[2][3] = 1 #C-A C-B C=D
G1.graph[3][0] = 1; G1.graph[3][ 2] = 1 #D-A D-C


print('#G1 무방향그래프')
for row in range(4):
    for col in range(4):
        print(G1.graph[row][col], end= ' ')
    print()

'''
출력화면
     0(A) 1(B) 2(C) 3(D)
-------------------------
0(A)  0    0    1    1
1(B)  0    0    1    0
2(C)  1    1    0    1
3(D)  1    0    1    0

'''

current = 0 #시작정점
queue.append(current) #current에 queue집어넣기
visited = [False] * 4 #정점을 방문했는지 안했는지 확인 (정점이 4개니까, 처음에 다 false로 초기화셋팅하기)

while(len(queue)!=0): #queue가 비어있지 않을때까지 while문 반복
    current =  queue.pop(0) #처음에 0으로 시작
    visitedAry.append(current) #queue에서 뺀 것을 visitedAry에 넣음
    visited[current]=True #visited[current]를 방문한 것으로 지정
    for vertex in range(4):
        if G1.graph[current][vertex] == 1 and not visited[vertex] : #간선이 있고, vertex값이 방문하지 않았으면
                queue.append(vertex) #quque에 vertex값을 집어넣는다.
                visited[vertex] = True #그 정점을 방문한 것으로 표시한다.

print('방문순서 --> ', end = ' ')
for i in visitedAry :
    print(chr(ord('A')+i), end = ' ')