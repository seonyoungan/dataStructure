#include <stdio.h>

int f_recursive(int n);
int f_repeat(int n);

double power_recursive(double x, int n);
double power_repeat(double x, int n);

int fib_recursive(int n);
int fib_repeat(int n);

int main(){
    printf("1. 팩토리얼, 순환: %d\n", f_recursive(5));
    printf("1. 팩토리얼, 반복: %d\n\n", f_repeat(5));
    
    printf("2. 거듭제곱, 순환: %3.1lf\n", power_recursive(3.0, 3));
    printf("2. 거듭제곱, 반복: %3.1lf\n\n", power_repeat(3.0, 3)); 
    
    printf("3. 피보나치, 순환: %d\n", fib_recursive(6)); 
    printf("3. 피보나치, 반복: %d\n\n", fib_repeat(6)); 
}

//1. 팩토리얼
//순환, 빅오: O(n)
int f_recursive(int n){ 
    if(n<=1) return (1); //순환 멈추는부분
    else return (n*f_recursive(n-1)); //순환 호출 부분
}

//반복, 빅오: O(n)
int f_repeat(int n){
    int a, b=1;
    for(a=n;a>0;a--)
        b = b*a;
    return b;
}

//2. 거듭제곱
//순환, 빅오: O(n)
double power_recursive(double x, int n){
    //순환 멈추는부분
    if(n==0)
        return 1; 
    //순환 호출 부분
    else if((n%2 == 0)) 
        return power_recursive(x*x, n/2); //짝수
    else
        return x*power_recursive(x*x, (n-1)/2); //홀수
}

//반복, 빅오: O(log n)
double power_repeat(double x, int n){
    int result=1.0;
    for(int i=0;i<n;i++)
        result = result * x;
    return result;
}

//3. 피보나치
//순환, 빅오: O(2^n)
int fib_recursive(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return (fib_recursive(n-2)+fib_recursive(n-1));
}

//반복, 빅오: O(n)
int fib_repeat(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int result = 0;
    int pp = 0;
    int p = 1;
    
    for(int i=2;i<=n;i++){
        result = p+pp;
        pp=p;
        p=result;
    }
    return result;
}

/*결과 출력
1. 팩토리얼, 순환: 120
1. 팩토리얼, 반복: 120

2. 거듭제곱, 순환: 27.0
2. 거듭제곱, 반복: 27.0

3. 피보나치, 순환: 8
3. 피보나치, 반복: 8
*/
