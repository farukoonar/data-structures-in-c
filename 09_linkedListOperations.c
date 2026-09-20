#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

node* createLinkedList(int data){
    node* n = (node*)malloc(sizeof(node));
    n -> data = data;
    n -> next = NULL;

    return n;
}

void writelinkedlist(struct Node* n){
    node* temp = n;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
        
    }
}

void add_node_head_of_linkedlist(node** linkedList, int data){
    node* newNode = createLinkedList(data);
    newNode -> next = *linkedList;
    *linkedList = newNode;

}

void add_node_end_of_linkedlist(node** linkedList, int data){
    node* temp = *linkedList;

    if(*linkedList == NULL){
        *linkedList = createLinkedList(data);
    }
    else{
        while(temp -> next != NULL){
            temp = temp -> next;

        } 
        temp -> next = createLinkedList(data);
    }
}

void delete_node_from_linkedlist(node** linkedlist, int data){
    node* temp;
    node* iter = *linkedlist;


    if((*linkedlist) == NULL){
        printf("Linked list is empty.\n");
    }
    else if((*linkedlist)->data == data){
        temp = (*linkedlist)->next;
        free(*linkedlist);
        *linkedlist = temp;
        
    }
    else{
        while(iter !=NULL && iter->data != data){
            temp = iter;
            iter = iter->next;
        }    
        if(iter == NULL){
            printf("Data is not in the list.\n");
        }else{
            free(iter);
            temp->next = temp->next->next; 
        }
        
    }
}

void liste_sirala(struct Node **liste_basi){

    node *a,*b,*c,*d;

    if(*liste_basi == NULL || (*liste_basi)->next==NULL) return;

    d = (*liste_basi) -> next; 
    (*liste_basi) -> next = NULL;

    while (d != NULL){ 
        c = d; 
        d = d -> next; 
        b = *liste_basi;

        while (b != NULL && b->data < c->data){
            a = b;
            b = b -> next; 
        }
        if (b == *liste_basi){ 
            c -> next = *liste_basi;
            *liste_basi = c;
        }
        else{
            a->next = c;
            c->next = b;
        }
    }
}

void add_node_to_sirali_linkedlist(node **liste_basi, int data){
    node* iter = *liste_basi;
    node* temp;
    
    if(*liste_basi == NULL){
        *liste_basi= createLinkedList(data);

    }
    else if((*liste_basi)->data > data){
        add_node_head_of_linkedlist(liste_basi,data);
    }
    else{
        while(iter != NULL && iter->data < data){
            temp = iter;
            iter = iter->next;
        }

        temp->next = createLinkedList(data);
        temp->next->next = iter;
    }
}

void reverse_linkedlist(node **liste_basi){
    node* temp;
    node* iter; 

    if((*liste_basi) == NULL)
        printf("Liste bos knk");
    else{
        iter = (*liste_basi)->next;
        (*liste_basi)->next = NULL;
        
        while(iter != NULL){
            temp = iter;
            iter = iter->next;
            temp->next= *liste_basi;
            *liste_basi = temp;
        }
    }
}


int main(){
    printf("\n-------------- Linked List Olusturma ---------------\n");
    node* n1;
    n1 = createLinkedList(5);
    writelinkedlist(n1);

    printf("\n-------------- Linked List Basina Node Ekleme ---------------\n");
    add_node_head_of_linkedlist(&n1, 4);
    add_node_head_of_linkedlist(&n1, 3);
    writelinkedlist(n1);

    printf("\n-------------- Linked List Sonuna Node Ekleme ---------------\n");
    add_node_end_of_linkedlist(&n1, 1);
    writelinkedlist(n1);

    printf("\n-------------- Linked List Bos Ise Sonuna Node Ekleme ---------------\n");
    node* n2 = NULL;
    add_node_end_of_linkedlist(&n2,10);
    writelinkedlist(n2);

    printf("\n-------------- Bos Linked Listden Node Silme ---------------\n");
    node* n3 = NULL;
    delete_node_from_linkedlist(&n3,3);
    writelinkedlist(n3);

    printf("\n-------------- Linked Listden Node Silme ---------------\n");
    delete_node_from_linkedlist(&n1,7);
    writelinkedlist(n1);

    printf("\n-------------- Linked List Siralama ---------------\n");
    liste_sirala(&n1);
    writelinkedlist(n1);

    printf("\n-------------- Sirali Linked Liste Node Ekleme ---------------\n");
    add_node_to_sirali_linkedlist(&n1,-1);
    writelinkedlist(n1);

    printf("\n-------------- Liste Tersine Cevirme ---------------\n");
    reverse_linkedlist(&n1);
    writelinkedlist(n1);

    return 0;
}