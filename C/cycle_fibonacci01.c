#include <stdio.h>

int recursive(int n);

int main(){
    int ret =0;
    ret = recursive(5);
    printf("반환값: %d", ret);
}


int recursive(int n){
    printf("현재 n값: %d", n);
    if(n<1) return 2;
    else return (2*(n-1)+1);
}
