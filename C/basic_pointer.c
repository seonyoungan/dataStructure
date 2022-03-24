#include <stdio.h>
#define SIZE 6
void get_integers(int list[]){
    printf("6개의 정수 입력하세요.: ");
    for(int i=0;i<SIZE;i++){
        scanf("%d", &list[i]); // 입력한 값이 list배열의 0~5번째 원소에 순차적으로 들어가겠지..
    }
}
int cal_sum(int list[]){
    int sum=0; //sum 선언, 0으로 값 초기화
    for(int i=0;i<SIZE;i++){ //넘겨진값+1
        sum = sum + *(list + i); //
    }
    return sum;
}

int main() {
    int list[SIZE]; // SIZE크기만큼의 배열 선언
    get_integers(list); //0~5번째 원소값 불려와진다
    printf("합: %d\n", cal_sum(list));
}