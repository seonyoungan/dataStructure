#include <stdio.h>

int recursive(int n);

int main(){
    int ret =0;
    ret = recursive(5);
    printf("반환값: %d", ret);
    
    return 0;
}


int recursive(int n){
    printf("현재 n값: %d", n);
    if(n<1) return 2;
    else return (2*recursive(n-1)+1);
}

/*결과값
현재 n값: 5
현재 n값: 4
현재 n값: 3
현재 n값: 2
현재 n값: 1
현재 n값: 0
반환값: 95
*/
