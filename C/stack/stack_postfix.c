#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef char element;
typedef struct{
    element data[MAX_SIZE];
    int top;
} stackType;

int init_stack(stackType *s){
    s->top=-1; //tackType *s라는 변수는 stackType 구조체를 가리킨다.
    // 포인터변수 s는 stackType의 top을 가리키고, top 변수에 -1을 대입하여 초기화시킨다.
}


int is_empty(stackType *s){
    //top == -1이면 empty상태(참)이다. 참이므로 1을 반환, 아니면 0반환
    return (s->top == -1); 
}

int is_full(stackType *s){
    // top == data[99]의 크기면 full상태(참)이다. 참이므로 1을 반환, 아니면 0반환
    return (s->top == (MAX_SIZE-1)); 
}

void push(stackType *s, element item){ //구조체를 가리키는 포인터변수 *s와 element item 변수 선언(char type)
    //isfull 상태면
    if(is_full(s)){
        fprintf(stderr,"스택포화에러");
        exit(0);
    } else{ //아니면 push 실행
        s->data[++(s->top)] = item; //먼저 top의위치를 증가시키고, item값을 data[top]에넣음
    }
}
int pop(stackType *s){
    //isEmpty상태면
    if(is_empty(s)){ 
        fprintf(stderr, "스택공백에러");
    } else{ //아니면 pop실행
        return s->data[(s->top)--];
    }
}
int peek(stackType *s){
    //isEmpty상태면
    if(is_empty(s)){ 
        fprintf(stderr, "스택공백에러");
    } else{ //아니면 pop실행
        return (s->data[s->top]);
    } 
}

int eval(char exp[]){ //여기는 후위표기 수식들 계산해줄거야
    int op1, op2, value, i=0; //피연산자1, 피연산자2, 값, for문돌릴변수 선언
	int len = strlen(exp); //exp배열의 길이는 len에 대입
    char ch; //문자
    stackType s;
    init_stack(&s); //s를 -1로 초기화시켜
    for(i=0; i<len;i++){
        ch = exp[i]; // 배열의 값들을 순차적으로 반복해서 돌리고, ch에 넣는다.
        if(ch!= '+' && ch!='-' && ch!='*' && ch!='/'){ //ch가 피연산자면(=연산자가 아니면)
            value = ch -'0'; // 문자로 들어가져있는 ch들을 숫자형태로 바꿈 (아스키코드) -> value에 대입
            push(&s, value); //value값을 push한다.
        } else{ //ch가 연산자면
            op2=pop(&s); //피연산자2를 스택에서 제거
            op1=pop(&s); //피연산자1를 스택에서 제거
            switch(ch){ //연산 수행 (push)
                case '+': push(&s, op1+op2); break;
                case '-': push(&s, op1-op2); break;
                case '*': push(&s, op1*op2); break;
                case '/': push(&s, op1/op2); break;
            }
        }
    }
    return pop(&s); //pop해서 반환함
}

int main(void) {
    int result;
    printf("후위표기식: 82/3-32*+\n");
    result=eval("82/3-32*+");
    printf("결과값: %d\n", result);
    return 0;
}