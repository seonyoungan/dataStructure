#python 스택구현 (클래스 활용)

class Stud_stk:
    #생성자, 기본적으로 class에서는 지역변수만 존재하며 자기자신을 매개변수로 넘겨줌
    def __init__(self) :
        self.stk1 = [] #초기화
        self.stk2 = []
        self.stk3 = []


    def push(self, num, name, dept):
        print("스택에 자료를 넣습니다.")
        self.stk1.append(num)
        self.stk2.append(name)
        self.stk3.append(dept)

    def pop(self):
        if self.isEmpty() : 
            print("스택이 비었습니다.")
        else :
            print("스택에서 자료를 제거합니니다.")
            self.stk1.pop()
            self.stk2.pop()
            self.stk3.pop()

    def peek(self):
       print("스택의 top값을 출력합니다 : ", end="")
       print (self.stk1[len(self.stk1)-1], self.stk2[len(self.stk2)-1], self.stk3[len(self.stk3)-1])

    def isEmpty(self):
        top = len(self.stk1)-1
        if top == -1 :
            return 1
        
    def display(self) :
        print("스택항목의 수 --->>", len(self.stk1))
        for i in range(0, len(self.stk1), 1) :
            print(self.stk1[i], self.stk2[i], self.stk3[i])

#class 호출
st_test = Stud_stk()
st_test.display
st_test.push(202011007, "홍길동", "글로벌미디어학부")
st_test.push(202011008, "장길산", "글로벌미디어학부")
st_test.push(202011009, "임꺽정", "컴퓨터학부")
st_test.push(202011010, "트럼프", "소프트웨어학부")
st_test.display()
st_test.peek()
st_test.pop()
st_test.pop()
st_test.pop()
st_test.pop()
st_test.display()
