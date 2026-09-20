#include <stdio.h>
#include <stdlib.h>

void create2dDynamicArray(int*** x, int row_number, int column_number){
    
    int i, j; 

    *x =(int**)malloc(sizeof(int*) * row_number);

    for(i=0; i < row_number; i++){
        *(*x+i) = (int*)malloc(sizeof(int) * column_number);
    
        for(j=0; j < column_number; j++){
            *(*(*x+i) + j) = rand()%3;

        }
    }
}

void print2dDynamicArray(int** x, int row_number, int column_number){
    int i, j;

    for(i=0; i < row_number; i++){
        for(j=0; j < column_number; j++){
            printf("%d ", *(*(x+i) + j));

        }
        printf("\n");
    }
}

int** addDynamicArray(int** x1, int row_number1, int column_number1,
                      int** x2, int row_number2, int column_number2){
    int i,j;
    int** x3;
    create2dDynamicArray(&x3, row_number1, column_number1);

    if(column_number1 == column_number2 && row_number1 == row_number2){
        for(i=0; i < row_number1; i++){
            for(j=0; j< column_number1; j++){
                //*(*(x3+i) + j) = *(*(x1+i) + j) + *(*(x2+i) + j);
                x3[i][j] = x1[i][j] + x2[i][j];
            }
        }

        return x3;
    }
    else{
        printf("Satir ve sutun sayilari esit degil!\n");
    }
       
}

int** multiplyDynamicArray(int** x1, int row_number1, int column_number1,
                           int** x2, int row_number2, int column_number2){
    int** x3;
    int i, j, k;

    create2dDynamicArray(&x3, row_number1, column_number2);
    
    if(row_number2 == column_number1){
        for(i=0; i < row_number1; i++){
            for(j=0; j< column_number2; j++){
                x3[i][j] = 0;
                for(k=0; k < column_number1; k++){
                    x3[i][j] = x3[i][j] + x1[i][k] * x2[k][j];
                    //*(*(x3 + i) + j) = *(*(x3 + i) + j) + *(*(x1 + i) + k) * *(*(x2 + k) + j);

                }
            }

        return x3;
        }
    }
    else{
        printf("Carpma islemi yapilamaz.\n");
    }
}


int main(){

int** ptr1;
int** ptr2;
int** ptr3;
int** ptr4;
int column_number1, row_number1, column_number2, row_number2;

printf("1. Satir sayisini giriniz: ");
scanf("%d", &row_number1);

printf("1. Sutun sayisini giriniz: ");
scanf("%d", &column_number1);

printf("2. Satir sayisini giriniz: ");
scanf("%d", &row_number2);

printf("2. Sutun sayisini giriniz: ");
scanf("%d", &column_number2);



create2dDynamicArray(&ptr1, row_number1, column_number1);
create2dDynamicArray(&ptr2, row_number2, column_number2);

print2dDynamicArray(ptr1, row_number1, column_number1);
printf("==========================\n");
print2dDynamicArray(ptr2, row_number2, column_number2);

//ptr3 = addDynamicArray(ptr1, row_number1, column_number1,
//                ptr2, row_number2, column_number2);

//printf("==========================\n");
//print2dDynamicArray(ptr3, row_number1, column_number1);

ptr4 = multiplyDynamicArray(ptr1, row_number1, column_number1,
                     ptr2, row_number2, column_number2);

printf("==========================\n");
print2dDynamicArray(ptr4, row_number1, column_number2);


return 0;
}