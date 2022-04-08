#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 6
typedef struct{
    int degree; //차수
    float coef[MAX_DEGREE]; //계수, 그냥 float타입으로 만든거구, int여도 상관없음
} polynomial;

//C = A+B
polynomial poly_add1(polynomial A, polynomial B){
    polynomial C;
    int Apos = 0, Bpos = 0, Cpos = 0; //배열의 인덱스 변수(위치를 알려줄 것)
    int degree_a = A.degree; //매개변수에서 가져온 A의 차수, 최초: 5
    int degree_b = B.degree; //매개변수에서 가져온 B의 차수, 최초: 4
    C.degree = MAX(A.degree, B.degree); //결과 다항식 차수
    //C.degree: 최초: 삼항연산자인 MAX(a,b)함수에 의해 a항이 더 크므로, 5를 복사

    while (Apos <= A.degree && Bpos <= B.degree){  //배열의 인덱수변수들이 각각 A,B 작거나 같을때까지 반복
        if(degree_a > degree_b){  //차수가 A항 > B항이면
            C.coef[Cpos++] = A.coef[Apos++]; 
            degree_a--;
        }
        else if(degree_a == degree_b){ //차수가  A항 = B항이면
            C.coef[Cpos++] = A.coef[Apos++]+B.coef[Bpos++];
            degree_a--; degree_b--;
        }
        else{ //차수가 A항 < B항이면
            C.coef[Cpos++] = B.coef[Bpos++];
                degree_b--;
            }
        }
    return C;
}

void print_poly(polynomial p){
    for(int i=p.degree; i>0;i--)
        printf("%3.1fx^%d+", p.coef[p.degree-i], i);
    printf("%3.1f\n",p.coef[p.degree]);
    
}
int main(void){
    polynomial a = {5,{3,6,0,0,0,10}}; //다항식을 a변수에 대입
    polynomial b = {4,{7,0,5,0,1}}; //다항식을 a변수에 대입
    polynomial c; 
    
    print_poly(a);
    print_poly(b);
    c = poly_add1(a,b);
    printf("------------------------------\n");
    print_poly(c);
    return 0;
}

