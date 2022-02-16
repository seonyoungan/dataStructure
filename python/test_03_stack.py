#python 스택구현

#배열선언
stk = []


#각 함수 선언
def push(e):
    stk.append(e)
    #stk.append 자동으로 스택처리해주며 empty, full확인 안해도됨(파이썬)

def pop():
    top = len(stk)-1
    if top == -1 :
        print("스택이 비었습니다.")
    else :
        stk.pop()

#맨 마지막 값 가져오기(peek)
def peek():
    return stk[len(stk)-1]

#push 
for i in range(3):
    push(i+1)
print(stk)

#peek
print(peek())

#pop(LIFO)
pop()
pop()
pop()
pop()
print(stk)
