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

int check_matching(const char *in){
    stackType s;
    char ch, open_ch;
    int i, n=strlen(in); //n=in의 문자열 길이
    init_stack(&s); //초기화
    
    //if open bracket
    for(i=0;i<n;i++){ //0~in문자열 길이까ㅣ 반복
        ch=in[i]; //ch=다음문자
        switch(ch){
            case '(': case '[': case '{':
                push(&s, ch); //스택에 push
                break;
            case ')': case ']': case '}':
                if(isEmpty(&s)){
                    return 0; //스택 비어있으면 0반환
                } else{
                    open_ch=pop(&s); //open_ch란 변수에 pop한 값을 넣음
                    if((open_ch =='('&&ch!=')')||(open_ch =='{'&&ch!='}')||(open_ch =='['&&ch!=']')){
                        return 0; // open_ch는 (이고, ch는 )가 아니면 실패임 각 괄호는 매칭되어야함
                    }
                    break;
                    
                    /*open_ch는 LIFO니까 가장 최근에 들어간 값이 들어가져있잖아.. 그리고 ch에는 닫는괄호가 나오면 걍 끝나야함..
                    */
                }
        }
    }
    if(!isEmpty(&s)) return 0; //스택에 남아있으면 오류
    return 1;
}

int main() {
	//괄호검사: 괄호가 열리면 push, 닫히면 pop
	char *p="{A[(i+1)]=0; }";
	if(check_matching(p)==1){
	    printf("%s 괄호검사 성공",p);
	} else{
	    printf("%s 괄호검사 실패",p);
	}
	return 0;
}