#include <stdlib.h>
#include <stdio.h>
#include "../include/stack.h"
#include "../include/linked_list.h"

void push(Node **top, int data) {
    Node *new_node = create_node(data);
    new_node->next = *top;
    *top = new_node;
}

int pop(Node **top) {
    Node *target = *top;
    *top = target->next;
    int data = target->data;
    free(target);
    return data;
}

int peek(Node *top) {
    return top->data;
}

int is_empty(Node *top) {
    if (top) return 1;
    return 0;
}

void print_stack(Node *top) {
    Node *current = top;
    while (current) {
        printf("%d", peek(current));
        printf(" -> ");
        current = current->next;
    }
    printf("NULL\n");
}

void free_stack(Node **top) {
    Node *current = *top;
    while (current) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    *top = NULL;
}
