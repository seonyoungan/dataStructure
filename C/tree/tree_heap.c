#include <stdio.h>
#include <stdlib.h>
#define MAX 200

//element type struct
typedef struct element{
    int key;
} element;

typedef struct HeapType{
    element heap[MAX]; // element 타입인 heap배열은 max개의 요소를 가짐
    int heap_size; //heap의 사이즈 변수
} HeapType;

//생성
HeapType *create(){
    return (HeapType *)malloc(sizeof(HeapType));
}

//초기화
void init(HeapType *h){
    h->heap_size = 0; //그 생성함수는 heap_size를 0으로 초기화
}

//삽입
void insert_max_heap(HeapType *h, element item){
    int i;
    i = ++(h->heap_size); //사이즈를 증가시켜서 공간만들어서 아이템 삽입할것
    
    //i가 1이 아니거나(=루트노드가 h->heap[1]에 위치, 삽입할 item의 키값이 h->heap[i/2](=부모노드)보다 큰 동안에 반복
    while((i!=1)&&(item.key > h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2]; //자식노드를 heap[i]에 복사
        i /= 2; //부모노드쪽으로 이동시킴
    }
    h->heap[i] = item; //item값 복사
}

//삭제
element delete_max_heap(HeapType *h){
    int parent, child;
    element item, temp;
    
    item = h->heap[1]; //루트노드값을 itemㅔㅇ 복사 (이걸 삭제하겠지?)
    temp = h->heap[(h->heap_size)--]; //heap사이즈를 temp에 복사하고 사이즈를 줄인다.
    parent = 1;
    child = 2; 
    while(child<=h->heap_size){ //2보다 h->heap_size가 큰 동안에반복
        if((child < h->heap_size)&&(h->heap[child].key) < h->heap[child+1].key) 
            child++; //자식노드 증가
        if(temp.key >= h->heap[child].key) //감소전 힙사이즈가 2보다 크면
            break;
    
        h->heap[parent] = h->heap[child];
        parent = child; //자식이 부모가됨
        child *= 2; //자식의 자식에게로?
        
    }
    h->heap[parent] = temp; //템프는 부모노드... 
    //삭제연산 다시 공부해야겠다.
    return item;
}

int main() {

	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, e4 = { 40 };
	element max; //가장큰값변수
	HeapType* heap; //Heap타입의 heap변수선언

	heap = create(); 	// 히프 생성 (메모리 할당))
	init(heap);	// 초기화

	// 삽입
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	insert_max_heap(heap, e4);

	// 삭제
	
	max = delete_max_heap(heap);
	printf("< %d > ", max.key);
	max = delete_max_heap(heap);
	printf("< %d > ", max.key);
	max = delete_max_heap(heap);
	printf("< %d > ", max.key);
	max = delete_max_heap(heap);
	printf("< %d > \n", max.key);    
	
	free(heap); //메모리해제
    return 0;
}