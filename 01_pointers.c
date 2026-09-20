#include <stdio.h>
#include <stdlib.h>

int main(){

    int a = 10;

    int* ptr;
    int** ptr2;
    int*** ptr3;

    ptr = &a;

    printf("The value of a is: %d\n", a);
    printf("The value of a using pointer is: %d\n", *ptr);
    printf("The address of a is: %p\n", &a);
    printf("The address of a using pointer is: %p\n", ptr);
    printf("The address of pointer is: %p\n", &ptr);

    printf("\n");
    ptr2 = &ptr;
    printf("The value of ptr2 is: %p\n", ptr2);
    printf("The value of ptr1 using pointer is: %p\n", *ptr2);
    printf("The value of a using pointer to pointer is: %d\n", **ptr2);
    printf("The address of pointer to pointer is: %p\n", &ptr2);

    ptr3 = &ptr2;
    printf("\n");   
    printf("The value of ptr3 is: %p\n", ptr3);
    printf("The value of ptr2 using pointer is: %p\n", *ptr3);
    printf("The value of ptr1 using pointer to pointer is: %p\n", **ptr3);
    printf("The value of a using pointer to pointer to pointer is: %d\n", ***ptr3);


    return 0;
}