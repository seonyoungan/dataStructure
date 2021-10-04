#큐 리스트 생성
Que = []

def enqueue(x) :
    print("큐에 자료를 넣습니다.")
    Que.append(x)

def dequeue(): #매개변수 필요없음
    if isEmpty() :
        print("큐가 비어있습니다.")
    else :
        print("큐에서 자료를 제거합니다.")
        result = Que[0] #Que의 0번지 값을 돌림
        print("큐에서 다음 자료를 제거합니다 :", result)
        del Que[0] #0번지 값지움
        return result

def peek() :
    return Que[0] #peek는 넘겨주면 됨

def isEmpty() :
    if len(Que)-1 < 0 :
        return 1 #0은 거짓 1은 참

def display() :
    print("큐 항목의 수 ===>>", len(Que)) #Que의 길이
    print(Que)


print(Que)

for i in range (1, 10, 1) :
    enqueue(i)
    if i == 5 :
        print(Que)
print(Que)
dequeue()
print(peek())
dequeue()

print(Que)
