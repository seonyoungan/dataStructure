#1. 문자출력
print("1. 문자출력")
name = '홍길동'
age = 21
weight = 75.5
print('내이름은', name, '입니다.')
print('나는', age, '살 입니다.')
print('나의 몸무게는', weight, 'kg 입니다.')
print("-------------------------------------------------")

print("내이름은 %s입니다." %name)
print("나는 %d살 입니다." %age)
print("나의 몸무게는 %.1fkg 입니다." %weight)
print("-------------------------------------------------")

#2. 다중출력
print("2. 다중출력")
kleng = 90
eng = 85
print("국어는 %d점이고, 영어는 %d점 입니다." %(kleng, eng))
print("-------------------------------------------------")

#3. 변수 = input("입력메세지 : ")
print("#3 변수 = input()")
name = input("이름 : ")
print("안녕하세요? %s씨 반가워요." %name)
print("%s씨는(은)  몇살인가요?" %name)

age2 = int(input("나이 : "))
print("%s씨는(은) %d살이군요" %(name, age2))

nextAge = age2 + 1
print("%s씨는(은) 내년에 %d살이 됩니다." %(name,nextAge))
print("-------------------------------------------------")


#4. 조건문 - 다중if문
print("4. 조건문 - 다중if문")
score = int(input("성적입력 : "))
if score >= 90 :
    print("당신은 %d점이고, A학점입니다." %score)
elif (90 > score and score >= 80) :
    print("당신은 %d점이고, B학점입니다." %score)
elif (80 > score and score >= 70) :
    print("당신은 %d점이고, C학점입니다." %score)
elif (70 > score and score >= 60) :
    print("당신은 %d점이고, D학점입니다." %score)
else :
    print("당신은 %d점이고, F학점입니다." %score)
print("-------------------------------------------------")

#5. 반복문 - while문
print("5. 반복문 - while문")
import time
n = 1
cnt = int(input("숫자입력 : "))
while n <= cnt:
    print(n)
    n = n+1
    time.sleep(0.1)
print("끝")
print("-------------------------------------------------")

#6. 반복문 - for문
print("6. 반복문 - for문")
i = int(input("숫자입력 : "))

for  i in range(10) :
    print(i)
    i = i + 1
    time.sleep(0.1)
print("끝")
print("-------------------------------------------------")

#7. 전역변수, 지역변수
print("7. 전역변수, 지역변수")

def func1():
    a = 10
    print("func1()에서 a값 %d" %a)

def func2():
    print("func1()에서 a값 %d" %a)

a =20
func1()
func2()
