/* main.c */
#include <stdio.h>
#include "header.h"
#include <stdlib.h>

int main() {
    Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    printf("Linked List: ");
    print_list(head);

    free_list(head);
    return 0;
}

