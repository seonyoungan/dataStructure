#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 //리스트의 최대 크기

typedef int element; // 항목 정의
typedef struct{
    element array[MAX_SIZE]; //배열 정의
    int size; //현재 리스트에 저장된 항목들의 개수
} arrayListType; 

//에러
void error(char *message){
    fprintf(stderr, "%s", message);
    exit(1);
}

//초기화
void init(arrayListType *l){
    l->size = 0;
}

//공백검출
int is_empty(arrayListType *l){
    return l->size == 0; //size == 0이면 공백상태
}

//포화검출
int is_full(arrayListType *l){
    return l->size == MAX_SIZE; //size == MAX_SIZE면 포화상태
}

//위치 요소 반환
element get_entry(arrayListType *l, int pos){
    if(pos < 0 || pos >=l->size) //pos가 0보다 작거나 size와 같거나 크면
        error("위치오류"); //위치오류
    return l->array[pos]; //array[pos]값 반환
}


//출력
void print_list(arrayListType *l){
    int i;
    for(i=0;i<l->size;i++)
        printf("%d -> ", l->array[i]); //0~max_size까지 반복
    printf("\n");
}

//삽입
//1. 마지막요소에 리스트 삽입
void insert_last(arrayListType *l, element item){
    if(l->size >= MAX_SIZE) //size가 MAX_SIZE와 같거나 크면
        error("리스트 오버플로우"); //에러
    l->array[l->size++] = item; //item값을 대입하고 size한개 증가 (어차피 맨 마지막이라 이렇게 대입시켜줌)
}

//2. pos위치에 요소 추가
void insert(arrayListType *l, int pos, element item){
    if(!is_full(l) && (pos >= 0)&&(pos<=l->size)){
        //포화가 아니고 pos는 0보다 크고 MAX_SIZE보다 작으면
        for(int i=(l->size -1); i>=pos;i--) //반복문 실행
        //i = MAX_SIZE - 1, i가 pos와 같거나 클 때까지, i--
            l->array[i+1] = l->array[i]; 
        l->array[pos] = item; //ois에 item값 대입
        l->size++; // size 한개 증가
    }
}

element delete(arrayListType *l, int pos){ //pos를 삭제
    element item; //item변수 선언
    if(pos < 0 || pos >= l->size) //pos가 0보다 작거나 size보다 크면
        error("위치오류"); //오류
    item = l->array[pos]; // item변수에 array[pos] 대입
    for(int i=pos;i<(l->size -1); i++) //pos값; i<-1;i++
        l->array[i] = l->array[i+1]; //array[i]배열에  array[i+1] 대입
    l->size--; // size 한개 삭제
    return item;
}

int main(void){
    arrayListType l;
    
    init(&l);
    insert(&l, 0, 10); print_list(&l);
    insert(&l, 0, 20); print_list(&l);
    insert(&l, 0, 30); print_list(&l);
    insert_last(&l, 40); print_list(&l);
    delete(&l, 0); printf(&l); //0번째 항목 삭제
    return 0;
}
