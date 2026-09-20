#include <stdio.h>
#include <stdlib.h>

int main(){

// Static Array

int array[] = {1, 2, 3};

// Dynamic Array

int* ptr;
int column_number, i;

printf("Sutun sayisini giriniz: ");
scanf("%d", &column_number);

ptr =(int*)malloc(sizeof(int) * column_number);

for(i=0; i < column_number; i++){
    printf("%d. indeksi giriniz: ", i+1);
    scanf(" %d", (ptr+i));
}

for(i=0; i < column_number; i++){
    printf("%d. indeks:", i+1);
    printf(" %d\n", *(ptr+i));
}

return 0;
}