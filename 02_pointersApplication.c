#include <stdio.h>
#include <stdlib.h>

void multiply_with_two(int x){
    x = x * 2; 
    printf("%d\n",x);
}

void multiply_with_three(int* x){
    *x = *x *3;
}

int main(){

    int x = 10;

    printf("%d\n",x);
    
    multiply_with_two(x);
    printf("%d\n",x);

    multiply_with_three(&x);
    printf("%d\n",x);

    return 0;
}

