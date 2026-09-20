#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

void writelinkedlist(struct Node* n){
    node* temp = n;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
        
    }
}



int main(){
    printf("\n-------------- Linked List Olusturma ---------------\n");

    node* n1 = (node*)malloc(sizeof(node));
    n1 -> data = 1;
    n1 -> next = NULL;
    
    n1 -> next = (node*)malloc(sizeof(node));;
    n1 -> next -> data = 2;
    n1 -> next -> next = NULL;

    printf("1. Node datasi: %d\n",n1->data);
    printf("2. Node datasi: %d\n",n1->next->data);


    printf("\n-------------- Node Adresleri ---------------\n");

    printf("1. Node pointer adresi: %p\n", &n1);
    printf("1. Node adresi: %p\n", n1);
    printf("1. Node data adresi: %p\n", &(n1->data));
    printf("1. Node next adresi: %p\n", &(n1->next));
    printf("2. Node adresi: %p\n", n1->next);
    printf("2. Node data adresi: %p\n", &(n1->next->data));

    printf("\n-------------- Linked List Yazdirma ---------------\n");
    writelinkedlist(n1);

    return 0;
}