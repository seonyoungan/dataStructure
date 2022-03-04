#include <stdio.h>

int main(){
    asterisk(5);
}

void asterisk(int i){
    if(i>1){
        asterisk(i/2);
        asterisk(i/2);
    }
    printf("*");
}