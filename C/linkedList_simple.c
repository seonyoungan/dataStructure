#include <stdio.h>
#include <stdlib.h>

typedef int element; //정수형 데이터
typedef struct listNode{
    element data; //정수타입의 노드
    struct listNode *link; //포인트변수의 링크
} listNode;

void erorr(char *message){
    fprintf(stderr, "%s", message);
    exit(1);
}

listNode* insert_first(listNode *head, int value){
    listNode *p = (listNode *)malloc(sizeof(listNode));  // p는 동적메모리 listnodde를 가리킴
    p->data = value; // value값을 p의 데이터필드에 복사
    p->link = head; // link는 head를 가리킴(참조)
    head = p; // head가 p를 가리킴
    return head; //head를 반환
    
} //데이터값 입력 후 head포인터 변경

listNode* insert(listNode *head, listNode *pre, element value){
    listNode *p = (listNode *)malloc(sizeof(listNode)); // p는 동적메모리 listnodde를 가리킴
    p->data = value; // value값을 p의 데이터필드에 복사
    p->link = pre->link; // p의 링크(p의 다음데이터)가 pre의 링크(pre의 다음데이터)를 가리킴
    pre->link = p; //pre링크(pre의 다음데이터)가 p를 가리킴
    return head; //head반환
}

listNode* del_first(listNode *head){
    listNode *removed; //removed라는 포인터변수생성
    if(head == NULL) //head가 null이면
        return NULL; //null을 리턴
    removed = head; // removed가 head를 가리킴
    head = removed->link; //head는 remove의 링크(remove의 다음데이터를 가리킴
    free(removed); //removed 동적메모리해제(=head를 가리킸지!)
    return head; //head반환
}
listNode* del(listNode *head, listNode *pre){
    listNode *removed; //removed라는 포인터변수 생성
    removed = pre->link; //removed는 pre의 링크(=pre 다음data)를 가리킴
    pre->link = removed->link; // pre의 링크는 removed의 링크(=removed의 다음data)를 가리킴
    free(removed); //동적메모리해제 (=삭제)
    return head; //head반환
}

void print_list(listNode *head){
    for(listNode *p = head; p!=NULL; p=p->link) // p가 null이 아닐때까지 p는 p의 링크(=다음데이터)로 이동하며(?) 반복
        printf("%d->", p->data); //출력
    printf("NULL\n"); //null출력
}

int main() {
    listNode *head = NULL;
    for(int i = 0; i < 5; i++){
        head = insert_first(head, i);
        print_list(head);
    }
    for(int i = 0; i < 5; i++){
        head = del_first(head);
        print_list(head);
    }
    return 0;
}
