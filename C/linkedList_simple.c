#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data; //노드
    struct ListNode *link; // 링크_포인터변수
} listNode;

void erorr(char *message){
    fprintf(stderr, "%s", message);
    exit(1);
}

listNode* insert_first(listNode *head, int value){
    listNode *p = (listNode *)mallock(sizeof(listNode)); // 리스트노드 크기만큼의 메모리할당
    p->data = value; // value를 data변수에
    p->link = head; // head(포인터값) 변수link (포인터변수)에 복사
    head = p; // p값을 head에 대입 (= head 포인터 변경)
    return head; //변경된 head 반환
} //데이터값 입력 후 head포인터 변경
listNode* insert(listNode *head, listNode *pre, element value){
    listNode *p = (listNode *)malloc(sizeof(listNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p; //?
    return head;
}

int delete(listNode *head, listNode *pre){
    listNode *removed; //removed라는 포인터변수 생성
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(listNode *head){
    for(listNode *p = head; p!=NULLl; p=p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}



int main() {
    listNode *head = NULL;
    for(int i = 0; i < 5; i++){
        head = insert_first(head, i);
        print_list(head);
    for(int i = 0; i < 5; i++){
        head = delete(head);
        print_list(head);
    }
    return 0;
}
