#include <stdio.h>
#define SIZE 6
void get_integers(int list[]){ // 배열을 매개변수로 받음
    printf("6개의 정수 입력하세요.: ");
    for(int i=0;i<SIZE;i++){
        scanf("%d", &list[i]); // 입력한 값이 list배열의 0~5번째 원소에 순차적으로 들어감..
    }
}
int cal_sum(int list[]){
    int sum=0; //sum 선언, 0으로 값 초기화
    for(int i=0;i<SIZE;i++){ //i<6일 때까지 반복(i값은 1씩 증가됨)
        sum += sum *(list + i); // sum = sum + list+i주소가 가리키는 곳의 값
    }
    return sum; //누적된 합계
}

int main() {
    int list[SIZE]; //1. list[6] 배열 생성, list = list[0]의 주소
    get_integers(list); //2. list 주소를 get_integers의 인자로 넘긴다.
    printf("합: %d\n", cal_sum(list));
}
