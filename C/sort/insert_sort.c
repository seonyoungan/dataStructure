#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

void insert_sort(int list[], int n){
    int i, j, key; //비교대상1, 비교대상2, 키값
    for(int i = 1; i < n; i++){
        key = list[i];
        for(j=i-1;j>=0&&list[j]>key;j--) //j를 줄이면서 하나씨 ㄱ뒤로 미룸
            list[j+1] = list[i]; //list[j]값을 레코드의 오른쪽으로 이동
        list[j+1] = key;
    }
}


int main() {
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for(i = 0; i < n; i++)
		list[i] = rand() % 100;
    insert_sort(list, n);
    for(i=0;i<n;i++)
        printf("%d ", list[i]);
    
    printf("\n");
    
    return 0;
}