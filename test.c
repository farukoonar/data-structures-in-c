#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    int dizi1[3] = {1,2,3};
    int *dizi2 = dizi1;

    for(i=0; i < 3; i++){
        printf("%d ", dizi1[i]);
    }
    printf("\n");
    for(i=0; i < 3; i++){
        printf("%d ", dizi2[i]);
    }
    dizi1[0] = 31;

    printf("Degisiklik sonrasi.. \n");
    for(i=0; i < 3; i++){
        printf("%d ", dizi1[i]);
    }
    printf("\n");
    for(i=0; i < 3; i++){
        printf("%d ", dizi2[i]);
    }

}