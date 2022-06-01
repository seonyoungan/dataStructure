#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_SIZE];
} queueType;

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(queueType *q){ //초기화해줌
    q->front=0;
    q->rear=0;
}

int is_empty(queueType *q){
    return (q->front == q->rear);
}

int is_full(queueType *q){
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void print(queueType *q){
    printf("Queue (front= %d rear %d) = ", q->front, q->rear);
    if(!is_empty(q)){ //공백상태가 아니면
        int i = q->front; //1. front의 현재위치를 i에 대입
        do{
            i = (i + 1) % MAX_SIZE; //i= front + 1과 같다고 봐.
            printf("%d(%d) | ", q->data[i], i); //배열에 삽입
            if(i== q->rear) //i = rear이면
                break; // break;
        } while (i!=q->front); //i가 front가 아니면 반복
    } 
    printf("\n");
}

element enqueue(queueType *q, element item){
    if(is_full(q))
        error("큐가 포화상태 입니다.");
    q->rear=(q->rear + 1) % MAX_SIZE; // rear가 0=> rear에 1대입, 1 => 2대입, ...4=>5대입.. 즉 rear의 index를 1개씩 증가시켜준다는 뜻.
    return q->data[q->rear] = item; // item값을 data[rear]에 넣어줌.
}

element dequeue(queueType *q){
    if(is_empty(q))
        error("큐가 공백상태 입니다.");
    q->front=(q->front + 1) % MAX_SIZE; //front의 index를 1씩 올려주고
    return q->data[q->front]; //data[front] 값을 반환
}

element peek(queueType *q){
    if(is_empty(q))
        error("큐가 공백상태 입니다.");
    return q->data[q->front + 1] % MAX_SIZE;
}

int main(void){
    queueType q;
    int item;
    init(&q); //초기화
    printf("--데이터 추가 단계--\n");
    while(!is_full(&q)){ //포화상태가 아니면 반복
        printf("정수를 입력하세요.");
        scanf("%d", &item); //정수 입력
        enqueue(&q, item); //입력한 정수값을 삽입
    } 
    printf(">> 큐는 포화상태입니다. \n\n");
    print(&q);    
    printf("--데이터 삭제단계--\n");
    while(!is_empty(&q)){ //공백상태가 아니면 반복
        item = dequeue(&q); //반환된 dequeue함수값을 item에  대입
        printf("꺼내진정수: %d\n", item);
        print(&q); //print함수 실행
    }
    printf("큐는 공백상태입니다.\n\n");
    return 0;
}