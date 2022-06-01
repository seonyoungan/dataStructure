#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 5

typedef int element;
typedef struct{
    element data[MAX_SIZE];
    int front, rear;
} queueType;

void error(char *message){
    fprintf(stderr, "%s", message);
    exit(1);
}

//초기화
void init(queueType *q){
    q->front = 0;
    q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(queueType *q){
    return (q->front == q->rear); //front == rear일 땐 공백
}

int is_full(queueType *q){
    return ((q->rear+1)%MAX_SIZE == q->front);
    /*ex- MAX_SIZE = 5이므로, rear가 index[4]에 위치하면, (rear+1)%MAX_SIZE은 0 == front가 index[0]이면 0=0이 되니까 포화상태*/
}
void print(queueType *q){
    printf("Queue(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i=(i+1)%MAX_SIZE;
            printf("%d | ", q->data[i]);
            if(i==q->rear)
                break;
        } while(i!=q->front);
    }
    printf("\n");
}

//삽입함수
void enqueue(queueType *q, element item){
    if(is_full(q))
        error("큐가 포화상태입니다.");
    q->rear=(q->rear+1)%MAX_SIZE; //1. rear index를 1증가
    q->data[q->rear] = item; //2. item값을 data[rear]에 대입
}

//삭제함수
element dequeue(queueType *q){
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->front=(q->front+1)%MAX_SIZE; //1. front index를 1증가
    return q->data[q->front]; //2. data[front]를 반환
}


int main(void){
    queueType q;
    int item;
    
    init(&q);
    srand(time(NULL)); //시간 기준으로 초기화하는 난수 만듦
    for (int i=0;i<100;i++){ //i가 100이될 때까지 반복 
        if(rand() % 5 == 0){ //5로 나누어떨어지면 (0~4)
            enqueue(&q, rand()%100); //1~100중의 하나의 값을 삽입            
        }
        if(rand() % 10 == 0){ //10으로 나누어 떨어지면 (0~9)
            item = dequeue(&q);
        }
        print(&q); //현재queue보여줌
        
    }
    
    return 0;
}