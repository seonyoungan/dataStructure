// Online C compiler to run C program online
#include <stdio.h>
#include <stdli.h>

typedef sturct listNode{
    int coef; //계수
    int expon; //지수
    struct listNode *link; //링크
} listNode;

typedef struct listType { //리스트의 head타입
    int size;
    listNode *head;
    listNode *tail;
    // head | size | tail <-이런 모양으로 만들고 싶은 것이 솔찍헌 나의 심정,,
} listType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

listType* create(){
    listType *plist = (listType *)malloc(sizeof(listType)); //plist라는 포인트변수에는,, listType을 가리킴 그런데 이제 동적메모리공간할당된..
    plist->size = 0;
    plist->head = NULL;
    plist->tail = NULL;
    return plist;
}


void insert_last(listType *plist, int coef, int expon){ //plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 지수, expon은 계수
    listNode* temp = (listNode *)malloc(sizeof(listNode)); //temp라는 포인트변수는  listType을 가리킴 그런데 이제 동적메모리공간할당된..
    if (temp == NULL)
        error("메모리 할당 에러"); //메모리할당했는데,, 그공간이 null이면 너굴맨은 용서할 수 없다구,,
    temp -> coef = coef;
    temp -> expon = expon;
    //temp의 ceof에...메인함수에서 받은 coef를 복사하구.. temp의 expon에는 메인함수에서 받은 expon을 복사합니다..
    temp->link = NULL; //temp의 링크는 null을 가리켜요.. 즉.. temp의 다음 데이터는 null이란 말이겠찌요?
    if(plist->tail = NULL){ //늙은이는 안된다? 처럼 tail은 NULL이다?
        plist->head = plist->tail = temp;
        //head랑 tail은 temp를 가리킨다는거야?ㅠㅠㅠ ..이게 먼말이노ㅠㅠ;;살려주시라고요
    } else{
        plist->tail->link = temp;
        plist->tail = temp;
        //아무튼 아니면 plist의 tail이 temp를 가리킨대ㅠㅠ 
    }
    plist->size++; //이거 처음에 위에서 0이었잖니.. 암튼 하나씩 증가시키렴
}

//list3 = list1 + list2?
void poly_add(listType* plist1, listType *plist2, listType* plist3){
    listNode* a = plist1->head;
    listNode* b = plist2->head;
    int sum;
    
    while(a&&b){
        if
    }
}

int main() {
    // Write C code here
    printf("Hello world");
    
    return 0;
}