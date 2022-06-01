#include <stdio.h>
#include <stdlib.h>
typedef int element; //int형 element 타업선언
typedef struct listNode{ // listNode 구조체 선언
    element data; //element타입의 data라는 변수 선언
    struct listNode *link; // listNode 구조체타입의 link라는 포인터변수 선언
} listNode;
// data|link -> 대충 이런모양~

//결과 출력
void print_list(listNode *head){
    listNode *p; //출력할 위치를 가리키는 포인터변수
    if(head == NULL)
        return; //아무것도 리턴하지않음
    do{
        printf("%d->", p->data); //data값 복사
        p = p->link; //이동
    } while(p!= head);
    printf("%d", p->data); //마지막노드 출력
}

//첫부분에 삽입
listNode* insert_first(listNode* head, element data){ 
    listNode *node = (listNode *)malloc(sizeof(listNode)); //listNode크기의 동적메모리 할당 후 node에 복사
    node->data = data; //매개변수 data값을 node의 data에 복사
    if(head == NULL){//헤드가  NULL인 상태면
        head = node; //헤드에 노드를 복사함
        node->link = head; //노드의 링크는 헤드를 가리킴
    } else{ //헤드가 NULL이 아니면
        node->link = head->link; //노드의 링크는 헤드의 링크를 가리킴
        head->link = node; //헤드의 링크가 노드를 가리킴
       //즉, 삽입된 노드의 링크를 헤드의 링크로 연결시켜주고, 헤드의 링크는 노드를 가리키게해서 원형을 만듦
    }
    return head;
}

//마지막에 삽입
listNode* insert_last(listNode* head, element data){ 
    listNode *node = (listNode *)malloc(sizeof(listNode)); //listNode 크기의 동적메모리 할당 후 node에 복사
    node->data = data; //매개변수 data값을 node의 data에 복사
    if(head == NULL){ //헤드가 null이면
        head = node; // 헤드에 노드를 복사
        node->link = head; //노드의 링크가 헤드를 가리킴
    } else{ //헤드가 null이 아니면
        node->link = head->link; //노드의 링크가 헤드의 링크를 가리키고 있음
        head->link = node; //헤드의 링크가 노드를 가리킨다.
        head = node; //헤드에 노드를 복사 (헤드가 삽입된 노드를 가리킴)
    }
    return head;
}

//실행
int main(void){
    listNode *head = NULL; //head라는 포인터변수의 값은 NULL
    head = insert_last(head, 20); //head: 20의 주소를 가리키는 상태, data: 20
    head = insert_last(head, 30); //head: 20의 주소를 가리키는 상태, data: 30
    head = insert_last(head, 40); //head: 20의 주소를 가리키는 상태, data: 40
    head = insert_first(head, 10); //head: 10의 주소를 가리키는 상태, data: 10
    print_list(head);
    return 0;
}
