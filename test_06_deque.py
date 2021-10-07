from collections import deque


deq = deque()

for i in range(1, 10, 1) :
    if i % 2 :
        deq.appendleft(i) #내림차순으로 추가
    else :
        deq.append(i) #순차적으로 추가

print(deq)

deq.popleft() #맨처음(왼쪽)부터 pop(제거)
print(deq) #맨끝부터 pop(제거)
deq.pop()
print(deq)
deq.pop()
