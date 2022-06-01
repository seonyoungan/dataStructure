#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;
typedef struct{
    element data[MAX_SIZE];
    int top;
} stack;

void init_stack(stack *s){
    s->top = -1;
}

int is_empty(stack *s){
    return (s->top == -1);
}

int is_full(stack *s){
    return (s->top == (MAX_SIZE - 1));
}

void push(stack *s, element item){
    if(is_full(s)){ //어떨땐 s로받고 어떨땐 &s로 받는것,,일까..?
        fprintf(stderr, "스택 포화에러");
    } else{
        s->data[++(s->top)] = item;
    }
}

element pop(stack *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백에러");
    } else{
        return s->data[(s->top)--];
    }
}

int main(void){
    stack *s; //구조체,, 포인터,, 선언?
    s=(stack*)malloc(sizeof(stack)); //할당할 때 왜 이렇게 포인터를 사용해야하지..?
    init_stack(s);//초기화
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    free(s);
}