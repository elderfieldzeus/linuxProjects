#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *next;
}*LIST;

void init(LIST *head);
void putStart(LIST *head, int newNum);
void display(LIST head);

int main() {
    LIST head;
    init(&head);
    putStart(&head, 1);
    putStart(&head, 2);
    putStart(&head, 3);
    putStart(&head, 5);
    display(head);
    return 0;
}

void init(LIST *head) {
    *head = NULL;
}

void putStart(LIST *head, int newNum) {
    LIST temp = malloc(sizeof(LIST));
    temp->next = (*head);
    temp->num = newNum;
    *head = temp;
}

void display (LIST head) {
    for(LIST current = head; current != NULL; current = current->next) {
        printf("%d\n", current->num);
    }
}