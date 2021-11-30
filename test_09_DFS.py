# 깊이 우선 탐색 구현(stack이용)
# 클래스와 함수 선언 부분
class Graph():
    def __init__(self, size) :
        self.SIZE=size
        self.graph = [[0 for _ in range(size)] for _ in range(size)]

# 전역 변수 선언
G1 = None
stack = []
visitedAry=[] #방문한 정점

#메인 코드 부분
G1 = Graph(4)
G1.graph[0][2] = 1; G1.graph[0][3] = 1 #A-C A-D
G1.graph[1][2] = 1; #B-C
G1.graph[2][0] = 1; G1.graph[2][1] = 1; G1.graph[2][3] = 1 #C-A C-B C-D
G1.graph[3][0] = 1; G1.graph[3][2] = 1 #D-A D-C

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
stack.append(current) #현재 시작정점을 stack에 넣음
visitedAry.append(current) #현재 시작정점을 방문한 것으로 표시


while(len(stack) != 0): #스택의 길이가 0이 아닌 동안에
    next = None #다음 것을 찾음
    for vertex in range(4):#vertex ==4번
        if G1.graph[current][vertex] == 1:  #간선이 존재하면 
            if vertex in visitedAry : #vertex가 visitAray에 있으면 pass
                pass 
            else : #vertex가 visitAray에 방문한 적이 없으면 다음 정점으로 지정
                next = vertex
                break
    
    #next가 none이 아닌 동안에(=다음에 방문할 정점이 있으면)
    if next!= None: 
        current = next #next는 current로 잡는다. 
        stack.append(current) #current를 stack에 넣음
        visitedAry.append(current) # current에 대해서 방문한 정점으로 처리하기
    else : #더이상 다음에 방문할 정점이 없으면
        current = stack.pop() #스택에서 pop해서 비우기

print('방문순서 --> ', end = ' ')
for i in visitedAry :
    print(chr(ord('A')+i), end = ' ')

