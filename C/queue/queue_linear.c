// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

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

void print(queueType *q){
    for(int i=0;i<MAX_SIZE;i++){ // 0~4까지 반복
        if(i <= q->front || i> q->rear){ //i가 front보다 작고 rear보다 크면 (=데이터가 없으면)
            printf("   | ");
        } else{ //데이터가 있으면
            printf("%d | ", q->data[i]);
        }
    }
    printf("\n");
}
void init(queueType *q){
    q->rear = -1;
    q->front = -1;
}

int is_empty(queueType *q){
    if(q->front == q->rear) {return 1;}
    else {return 0;}
}
int is_full(queueType *q){
    if(q->rear == MAX_SIZE -1) {return 1;}
    else {return 0;}
}

int enqueue(queueType *q, int item){
    if(is_full(q)){
        error("큐가 포화상태입니다.");
    } else{
        q->data[++(q->rear)] = item;// rear를 올리고 item의 값을 삽입
    }
}

int dequeue(queueType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    } else{
        int item = q->data[++(q->front)]; //front 올리고 그 배열에 있는 값을 item에 대입
        return item; //item 반환
    }
}


int main() {
    int item=0;
    queueType q;
    init(&q); 
    enqueue(&q, 10); print(&q);
    enqueue(&q, 20); print(&q);
	enqueue(&q, 30); print(&q); 
	item = dequeue(&q); print(&q); //item = data[0] = 10
	item = dequeue(&q); print(&q); //item = data[1] = 20
	item = dequeue(&q); print(&q); //item = data[2] = 30 
	
    return 0;
}