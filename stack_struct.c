#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;
typedef struct{
    element data[MAX_SIZE];
    int top;
} stackType;

//스택초기화하기
void init_stack(stackType *s){ //구조체에 포인터 선언
    s->top = -1; // -1을 s에 위치한 top에 대입 (구조체에 접근)
}

//공백일 때
int isEmpty(stackType *s){
    return (s->top == -1);
}

//포화일 때
int isFull(stackType*s){
    return (s->top == (MAX_SIZE -1 ));
}

//삽입
void push(stackType*s, element item){
    if(isFull(s)){ //값으로 받아지나..?
        fprintf(stderr, "스택 포화 에러");
        return;
    } else{
        s->data[++(s->top)] = item;
    }
}

//삭제
element pop(stackType *s){
    if(isEmpty(s)){
        fprintf(stderr, "스택 공백 에러");
    } else{
        return s->data[s->top--];
    }
}

element peek(stackType *s){
    if(isEmpty(s)){
        fprintf(stderr, "스택 공백 에러");
    } else{
        return s->data[s->top];
    }
}

int main() {
	stackType s;
	init_stack(&s); //포인터의 값을 받아올 때 &를 쓰면..call by reference
	push(&s,1);
	push(&s,2);
	push(&s,3);
	push(&s,4);
	printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	
	return 0;
}