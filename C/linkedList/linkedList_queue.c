#include <stdio.h>
#include <stdlib.h>

typedef int element; //int형인 element라는 이름의 타입 선언
typedef struct queueNode{
    element data; //노드의 data는 element형
    struct queueNode *link; //노드의 link
} queueNode;

typedef struct{ //queue ADT 구현
    queueNode *front, *rear; //front와 rear 선언
} linkedQueueType;

//큐 초기화
void init(linkedQueueType *q){
    q->front = NULL;
    q->rear = NULL;
}

//공백 검출
int is_empty(linkedQueueType *q){
    return (q->front == NULL);
}

//포화 검출, 필요없긴한듯..? 왜냐면 동적이라서..
int is_full(linkedQueueType *q){
    return (0);
}

//삽입
void enqueue(linkedQueueType *q, element item){
    queueNode *temp = (queueNode *)malloc(sizeof(queueNode));
    temp->data = item; //매개변수로 받은 item을 temp의 data로 복사
    temp->link = NULL; // temp의 link는 NULL
    if(is_empty(q)){  //q가 공백이면 front와 rear는 temp를 가리킨다.
        q->front = temp;
        q->rear = temp;
    } else{
        q->rear->link = temp; //현재 rear의 링크(다음데이터)와 삽입할 노드(temp)에 연결시킴
        q->rear = temp; //rear가 temp를 가리키게 함
    }
}
//삭제
int dequeue(linkedQueueType *q){
    queueNode *temp = q->front; //front는 temp를 가리킴
    element data; //element형 변수 data 선언
    if(is_empty(q)){
        fprintf(stderr, "공백상태");
    } else{
        data = temp->data; //변수 data에 temp의 data값을 복사해둠
        q->front = q->front->link; //현재 front의 link(=다음데이터)를 front가 가리키게함
        if(q->front == NULL) //front가 NULL(공백)이면
            q->rear = NULL; //rear에 NULL 복사
        free(temp); //temp노드 동적메모리해제
        return data; //복사해둔 데이터값 반환
        /*dangling pointer(엉뚱한 값을 가리키고 있는 포인터)를 막기 위해
        초기화해줘야함*/
    } 
    return data; //삭제한 data값 반환
}
//프린트

void print_queue(linkedQueueType *q){
    queueNode *p;
    for(p = q->front; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

//메인함수에서 테스트
int main(void){
    linkedQueueType queue;
    
    init(&queue);

	printf("--삽입--\n");
	enqueue(&queue, 1);	print_queue(&queue);
	enqueue(&queue, 2);	print_queue(&queue);
	enqueue(&queue, 3);	print_queue(&queue);
	printf("\n--삭제--\n");
	dequeue(&queue);	print_queue(&queue);
	dequeue(&queue);	print_queue(&queue);
	dequeue(&queue);	print_queue(&queue);
}
