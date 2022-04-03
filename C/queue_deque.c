#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5


//create
typedef int element;
typedef struct{
    element data[MAX_SIZE];
    int front, rear;
} dequeType;

//에러
void error(char *message){
    fprintf(stderr, "%s", message);
    exit(1);
}

//초기화
void init(dequeType *q){
    q->front = 0;
    q->rear = 0;
}

//공백검출
int is_empty(dequeType *q){
    return (q->front == q->rear); //원형큐와 동일
}

//포화검출
int is_full(dequeType *q){
    return ((q->front + 1) % MAX_SIZE == q->front) ; //data[0]에 위치해있을때?
}

//출력
void print(dequeType *q){
    printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q)){ //공백상태가 아니면
        int i = q->front; //front위치를 i에 대입
        do{
            i = (i+1) % MAX_SIZE;
            /*front:0이면 i:5 / front:1이면 i:2 / front:2이면 
            i:3 / front:3이면 i:4 / front:4이면 i:1 */
            printf("%d | ", q->data[i]); // 배열의 요소 대입
            if(i==q->rear) // q->front == q->rear (=공백상태)
                break;
        } while (i !=q->front); //i가 front가 아닐때까지 반복
    }
    printf("\n");
}
//1. 삽입 (add_rear)
void add_rear(dequeType *q, element item){
    if(is_full(q))
        error("큐가 포화상태입니다.");
    q->rear = (q->rear + 1) % MAX_SIZE ; // rear 올리고
    q->data[q->rear] = item; // item값을 rear가 위치한 배열에 대입
    
}

//1. 삭제 (delete_front)
element delete_front(dequeType *q){
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->front = (q->front + 1) % MAX_SIZE; //front올리고
    return q->data[q->front]; // front가 위치한 곳의 배열값 반환
}
//1번의 삽입삭제 : 큐와 같은 효과

//삽입 (add_front)
void add_front(dequeType *q, element val){
    if(is_full(q))
        error("큐가 포화상태입니다.");
    q->data[q->front] = val; //val값을 대입한 후
    q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE; //front의 배열을 옮겨준다. ex) data[0] -> data[4] 
}

element delete_rear(dequeType *q){
    int prev = q->rear;
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return q->data[prev];
}

element get_rear(dequeType *q){
    if(is_empty(q)){
        error("큐는 공백상태입니다.");
    return q->data[q->rear];
    }
}

int main() {
    dequeType q;
    init(&q);
    for(int i = 0;i<2;i++){
        add_front(&q, i); 
        print(&q);
    /*메인함수에서 add_front함수가 처음 실행되면
     add_front함수는 포화상태가 아므니므로,
     front == data[0] rear == data[0]에위치한 상태에서 
     val값(0)이 먼저 front가 위치하고 있는 data[0]에 대입되고
     그 다음 front가 data[4]로 이동.
     
     그리고 메인함수로 돌아와서 print함수 실행됨
     DEQUE(front=4, rear=0) = 출력
     공백상태가아니므로 do while문 실행
     int i = 4;
     i = (4+1) % 5 // i = 0을 가리킴
     0 | 출력(왜? data[0]의 값은 0이 들어가져있으므로!)
     i == rear이므로 종료 (왜? i=0이되었으며, rear도 0인상태이므로)
    */        

        
    }
    
    for(int i=0;i<2;i++){
        delete_rear(&q);
        print(&q);
        
    }
    return 0;
}