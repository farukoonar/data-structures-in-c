#include <stdio.h>
#include <stdlib.h>

void create2dDynamicArray(int*** x, int column_number, int row_number){
    
    int i, j; 

    *x =(int**)malloc(sizeof(int*) * row_number);

    for(i=0; i < row_number; i++){
        *(*x+i) = (int*)malloc(sizeof(int) * column_number);
    
        for(j=0; j < column_number; j++){
            *(*(*x+i) + j) = rand()%100;

        }
    }
}

void print2dDynamicArray(int** x, int column_number, int row_number){
    int i, j;

    for(i=0; i < row_number; i++){
        for(j=0; j < column_number; j++){
            printf("%d ", *(*(x+i) + j));

        }
        printf("\n");
    }
}


int main(){

int** ptr;
int column_number, row_number;

printf("Sutun sayisini giriniz: ");
scanf("%d", &column_number);

printf("Satir sayisini giriniz: ");
scanf("%d", &row_number);

create2dDynamicArray(&ptr, column_number, row_number);
print2dDynamicArray(ptr, column_number, row_number);

return 0;
}