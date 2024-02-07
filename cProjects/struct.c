#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char fName[24];
    char MI;
    char lName[16];
    int age;
    char gender;
}PERSON;

PERSON getData();
void display(PERSON person);

int main() {
    PERSON person = getData();
    display(person);
    return 0;
}

PERSON getData() {
    PERSON p;
    printf("Enter first name: ");
    scanf(" %s", p.fName);
    printf("Enter middle initial: ");
    scanf(" %c", &p.MI);
    printf("Enter last name: ");
    scanf(" %s", p.lName);
    printf("Enter age: ");
    scanf("%d", &p.age);
    printf("Enter gender [M or F]: ");
    scanf(" %c", &p.gender);
    return p;
}

void display(PERSON person) {
    printf("Name: %c%s %c. %c%s\n", toupper(person.fName[0]), (person.fName) + 1, toupper(person.MI), toupper(person.lName[0]), person.lName + 1);
    printf("Age: %d\n", person.age);
    printf("Gender: %c", toupper(person.gender));
}