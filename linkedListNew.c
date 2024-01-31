#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *next;
}LinkedList;

void insertFirst(LinkedList **head, int newNum);
void insertLast(LinkedList **head, int newNum);
void display(LinkedList *head);

int main(){
    LinkedList *head = NULL;

    insertLast(&head, 6);
    insertLast(&head, 4);
    insertFirst(&head, -1);
    insertLast(&head, 5);
    insertLast(&head, 7);
    insertFirst(&head, -2);
    insertLast(&head, 2);
    insertLast(&head, 4);
    display(head);
}

void insertFirst(LinkedList **head, int newNum) {
    LinkedList *new = malloc(sizeof(struct node));
    new->next = *head;
    new->num = newNum;
    *head = new;
}

void insertLast(LinkedList **head, int newNum) {
    LinkedList *current = NULL, *temp = NULL;
    if(*head == NULL) {
        *head = malloc(sizeof(struct node));
        (*head)->next = NULL;
        (*head)->num = newNum;
    }
    else {
        for(current = *head; current->next != NULL; current = current->next);
        current->next = malloc(sizeof(struct node));
        current = current->next;
        current->num = newNum;
        current->next = NULL;
    }
}

void display(LinkedList *head) {
    LinkedList *current = NULL;
    for(current = head; current != NULL; current = current->next) {
        printf("%d ", current->num);
    }
}