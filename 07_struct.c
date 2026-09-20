#include <stdio.h>
#include <stdlib.h>

typedef struct Person{
    char *name;
    int age;
}person;

typedef struct Student{
    int sn;
    struct Person p;
}student;

void displayPerson(struct Person p){
    printf("Person's name is: %s\n", p.name);
    printf("Person's age is: %d\n", p.age);
}

void displayStudent(student s){
    printf("Student's name is: %s\n", s.p.name);
    printf("Student's age is: %d\n", s.p.age);
    printf("Student's number: %d\n", s.sn);
}

int main(){
    printf("\n-------------- Struct ---------------\n");
    struct Person p1;

    p1.name = "Ahmet";
    p1.age = 20;

    displayPerson(p1);
    printf("-----------------------------\n");


    printf("\n-------------- Ic Ice Struct ---------------\n");
    student s1;
    s1.p.name = "Faruk";
    s1.p.age = 25;
    s1.sn = 40210810;

    displayStudent(s1);
    printf("-----------------------------\n");


    printf("\n-------------- Struct Pointer ---------------\n");
    person *ptr;

    ptr = &p1;

    printf("Person's name: %s\n", ptr -> name);
    printf("Person's age: %d\n", ptr -> age);
    printf("Person's name with pointer: %s\n", (*ptr).name);
    printf("Person's age with pointer: %d\n", (*ptr).age);


    printf("\n-------------- Struct Adreslemesi ---------------\n");

    printf("Structin adresi: %p\n", &p1);
    printf("Name adresi: %p\n", &p1.name);
    printf("Age adresi: %p\n", &p1.age);

    printf("\n-------------- Struct Icinde Struct Adreslemesi ---------------\n");

    student* ptr2;

    ptr2 = (student*)malloc(sizeof(student));

    ptr2 -> sn = 40210811;
    ptr2 -> p.age = 21;
    ptr2 -> p.name = "Melike";

    printf("Structin adresi: %p\n", &ptr2);
    printf("studentin adresi: %p\n", ptr2);
    printf("Ogrenci numarasi adresi: %p\n", &ptr2 -> sn);
    printf("Struct icinde structin adresi: %p\n", &ptr2->p);
    printf("Struct icinde structin adinin adresi: %p\n", &ptr2->p.name);
    printf("Struct icinde structin yasinin adresi: %p\n", &ptr2->p.age);

return 0;
}