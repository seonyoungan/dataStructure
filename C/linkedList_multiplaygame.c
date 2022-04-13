
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100]; //char형의 element[100] 배열 타입 선언
typedef struct listNode{
    element data;
    struct linstNode *link;
} listNode;


listNode* insert_first(listNode *head, element data){
    listNode *node = (listNode *)malloc(sizeof(listNode));
    strcpy(node->data, data); //string복사! node->data에 매개변수 data값 복사
    if(head == NULL){
        head = node; //head 에 node값 복사한 다음에
        node->link = head; //node의 링크는 head를 가리킴
    } else{
        node->link = head->link; //노드의 링크는 헤드의 링크를 가리킴(다음을 가리킴)
        head->link = node; //헤드의 링크에 node 대입(헤드의 다음을 가리키는 건 node)
    }
    return head;
}
int main() {
    listNode *head = NULL;


    head = insert_first(head, "an");
    head = insert_first(head, "kim");
    head = insert_first(head, "min");
    head = insert_first(head, "jung");

		listNode* p = head;
	for (int i = 0; i < 10; i++) {
		printf("현재 차례=%s \n", p->data);
		p = p->link;
	}
    return 0;
}
