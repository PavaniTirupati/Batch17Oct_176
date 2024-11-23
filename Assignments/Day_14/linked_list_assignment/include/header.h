/* header.h */
#ifndef HEADER_H
#define HEADER_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print_list(Node* head);
void push(Node** head_ref, int new_data);
void free_list(Node* head);

#endif

