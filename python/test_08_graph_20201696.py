# 함수 선언
# 인접행렬을 2차원 배열로 구현
class Graph():
    def __init__(self, size) :
        self.SIZE=size
        self.graph = [[0 for _ in range(size)] for _ in range(size)]

# 전역 변수 선언
G1 = None
G2 = None 

# 메인 코드
G1 = Graph(4) #그 =래프 사이즈 지정(2차원배열)
G1.graph[0][1] = 1; G1.graph[0][2] = 1; G1.graph[0][3]=1
G1.graph[1][0] = 1; G1.graph[1][2] = 1
G1.graph[2][0] = 1; G1.graph[2][1] = 1; G1.graph[2][3] = 1
G1.graph[3][0] = 1; G1.graph[3][2] =1

print('#G1 무방향그래프')
for row in range(4) :
    for col in range(4):
        print(G1.graph[row][col], end = '')
    print()

G2 = Graph(4)
G2.graph[0][1] = 1; G2.graph[0][2] = 1
G2.graph[3][0] = 1; G2.graph[3][2] = 1

print('#G2 방향그래프')
for row in range(4):
    for col in range(4):
        print(G2.graph[row][col], end='')
    print()