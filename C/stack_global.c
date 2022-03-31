#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element; // 데이터의 자료형
element stack[MAX_SIZE]; //1차원 배열을 구조체로 선언 (자료형: int)
int top = -1; //스택의 최상단

int isEmpty(){ //공백확인
    return (top == -1); //스택이 공백인 상태
}

int isFull(){ //공백포화
    return (top == (MAX_SIZE -1)); //배열의 값은 stack[0]~stack[99]까지니까요
}


void push(element item){ //삽입
    if(isFull()){
     fprintf(stderr, "스택포화\n");
     return;
 } else stack[++top] = item; //증가 후 삽입
     /*push를 하는 경우 처음에 -1로초기화했었지요.
     전위연산으로 인덱스에 1을 더해주고 그 뒤에  값을 push 해준다. */
}

element pop(){ //삭제
    if(isEmpty()){ //스택 공백이면
        fprintf(stderr, "스택공백\n");
        exit(1); //종료
    } else{
        return stack[top--]; //stack에서 값을 pop한다.
    }
}

element peek(){
    if(isEmpty()){
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
    } else{
        return stack[top]; //현재 스택이 어디에 위치하는지를 보여주는 것이에요
    }
}

int main() {
	push(1);
	push(2);
	push(8);
	push(4);
	push(5);
	push(6);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	return 0;
}
