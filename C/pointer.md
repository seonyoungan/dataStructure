## 0. pointer 기본
```c
int main() {
    int a=1;
    int b=2;
    int *c = &a; //a의 주소값을 반환
    int *d = &b; //b의 주소값을 반환

    printf("c의 값:%d\n", *c);
    printf("d의 값:%d\n\n", *d);
    
    printf("c의주소값:%d\n", c);
    printf("d의 주소값:%d\n", d);
    return 0;
}
```

결과   
```c
c의 값:1
d의 값:2

c의주소값:1002327760
d의 주소값:1002327764
```


## 1. call by value
a와 b의 값을 swap하는 프로그램을 포인터를 사용하지 않고 만들어 보자   
```c
void swap_value(int x, int y){
  int tmp = x;
  x= y;
  y= tmp;
}

int main() {
    int a=1, b=2;
    printf("swap_value 호출전: a=%d, b=%d\n",a,b);
    swap_value(a,b);
    printf("swap_value 호출후: a=%d, b=%d\n", a,b);

    return 0;
}
```

결과는   
```c
swap_value 호출전: a=1, b=2  
swap_value 호출후: a=1, b=2
```
위와 같이 나온다.   

이유는 함수의 동작원리에 있다.   
함수의 동작원리에 의하면, 매개변수가 넘어갈 때 값이 넘어간다.   
넘겨진 값을 swap해주고 함수가 끝나게 된다.   
따라서 `a=1, b=2, x=2, y=2`의 상태이므로 위와 같은 결과가 나오는 것이다.   
이것을 `call by value`라고 한다.

`main`에서 a와 b의 값을 swap하고 싶다면, 포인터를 사용해 `주소값`으로 넘기면 된다.
   
     
## 2. call by reference   
a와 b의 값을 swap하는 프로그램을 포인터를 사용해 만들어 보자   
```c
void swap(int *x, int *y){ // (a의 주소값(100), b의 주소값(200))
  int tmp = *x; // int tmp에 a의 주소값(100)을 대입함
  *x= *y; //*x = a의 주소값(100)에서 b의 주소값(200)으로 바뀜
  *y= tmp; // *y = b의 주소값(200)에서 a의 주소값(100)으로 바뀜
}
```
위와 같이 `swap`함수에 `main`의 a,b의 주소에 들어있는 값을 넘겨준다.(=a와 b의 메모리에 위치한 값이 참조된 것)   
그러면 위의 주석과 같이 처리가 된다.   
   
아래처럼 `main`에서는 값으로 넘겨 받을 것이다.   
```c
int main() {
    int a=1, b=2;
    printf("swap_reference 호출전: a=%d, b=%d\n",a,b);
    swap_reference(&a,&b);
    printf("swap_reference 호출후: a=%d, b=%d\n", a,b);

    return 0;
}
```

결과는
```c
swap_reference 호출전: a=1, b=2
swap_reference 호출후: a=2, b=1
```
위와 같이 나온다.   
