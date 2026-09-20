#include <stdio.h>
#include <stdlib.h>

int main(){


int x = 20;
int* ptr = &x;

int array[3] = {1, 2, 3};

printf("The value of x is: %d\n", x);
printf("The value of array[0] is: %d\n", array[0]);
printf("The value of array[1] is: %d\n", array[1]);
printf("The value of array[2] is: %d\n", array[2]);

printf("================================\n");
printf("The value of ptr is: %p\n", ptr);
printf("The value of array is: %p\n", array);

printf("================================\n");
printf("The address of array[0] using the address-of operator is: %p\n", &array[0]);
printf("The address of array[1] using the address-of operator is: %p\n", &array[1]);
printf("The address of array[2] using the address-of operator is: %p\n", &array[2]);

printf("================================\n");
printf("The value of array[0] using pointer arithmetic is: %d\n", *array);
printf("The value of array[1] using pointer arithmetic is: %d\n", *(array + 1));
printf("The value of array[2] using pointer arithmetic is: %d\n", *(array + 2));


return 0;
}