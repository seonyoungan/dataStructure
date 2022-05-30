#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
} TreeNode;

typedef TreeNode *element;

typedef struct QueueType{ //큐
    element data[SIZE];
    int front, rear;
}  QueueType;

//오류
void error(char *message){
    fprintf(stderr, "%s\n", "message");
    exit(1);
}

//초기화
void init_queue(QueueType *q){
    q->front = q->rear = 0; //front, rear를 0으로 초기화
}

//공백 검출
int is_empty(QueueType *q){
    return (q->front = q->rear); //front와 rear가 같은 곳을 가리킬 때 공백
}

//포화 검출
int is_full(QueueType *q){
    return ((q->rear + 1) % SIZE == q->front);
}

//삽입
void enqueue(QueueType *q, element item){
    if(is_full(q))
      error("큐가 포화상태입니다.");
    q->rear = (q->rear + 1) % SIZE; //rear 포인터 증가시킨 후대입 
    q->data[q->rear] = item; //item을 대입
}

//삭제
element dequeue(QueueType *q){
    if(is_empty(q))
        error("큐가 에러상태입니다.");
    q->front = (q->front + 1) % SIZE; //front 포인터 증가시킨 후 대입
    return q->data[q->front]; //그 값을 리턴
}

void level_order(TreeNode *ptr){
    QueueType *q;
    init_queue(&q); //초기화
    if(ptr== NULL) return;
    enqueue(&q, ptr); //삽입
    while(!is_empty(&q)){
        ptr = dequeue(&q);
        printf("[%d]", ptr->data);
        if(ptr->left)
            enqueue(&q, ptr->left);
        if(ptr->right)
            enqueue(&q, ptr->right);
    }   
}

//      15
//  4      20
//1	     16   25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode *root = &n6;

int main(void){
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");
	return 0;
}