#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct {
    char FName[16];
    char LName[20];
    char MI;
}Nametype;

typedef struct {
    Nametype name;
    unsigned ID;
    char Course[8];
    int Year;
}Studtype;

typedef struct {
    Studtype Stud[SIZE];
    int count;
}Studlist;

Studlist initList();
void displayList(Studlist L);
Studtype getInput();
void populateList(Studlist *pL, int n);

int main() {
    Studlist L = initList();
    populateList(&L, 1);
    populateList(&L, 1);
    displayList(L);
    return 0;
}

Studlist initList() {
    Studlist L = {.count = 0};
    return L;
}

void displayList(Studlist L) {
    if(L.count > 0) {
        for(int i = 0; i < L.count; i++) {
            printf("Name: %s, %s %c.\n", L.Stud[i].name.LName, L.Stud[i].name.FName, L.Stud[i].name.MI);
            printf("ID: %u\n", L.Stud[i].ID);
            printf("Course: %s\n", L.Stud[i].Course);
            printf("Year Level: %d\n\n", L.Stud[i].Year);
        }
    }
}

Studtype getInput() {
    Studtype S;
    printf("First name: ");
    scanf(" %s", S.name.FName);
    printf("Middle Initial: ");
    scanf(" %c", &S.name.MI);
    printf("Last name: ");
    scanf( "%s", S.name.LName);
    printf("ID: ");
    scanf("%u", &S.ID);
    printf("Course: ");
    scanf(" %s", S.Course);
    printf("Year: ");
    scanf("%d", &S.Year);
    printf("\n");
    return S;
}

void populateList(Studlist *pL, int n) {
    if(pL->count + n <= SIZE) {
        for(int i = 0; i < n; i++) {
            pL->Stud[pL->count++] = getInput();
        }
    }
}