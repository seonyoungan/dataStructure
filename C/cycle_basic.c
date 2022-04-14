#include <stdio.h>

int recursive(int n);
int f_repeat(int n);

int main(){
    printf("%d\n", f_recursive(5));
    printf("%d\n", f_repeat(5));
    
}

//순환, 빅오: O(n)
int f_recursive(int n){ 
    if(n<=1) return (1);
    else return (n*f_recursive(n-1));
}

//반복, 빅오: O(n)
int f_repeat(int n){
    int a, b=1;
    for(a=n;a>0;a--)
        b = b*a;
    return b;
}
