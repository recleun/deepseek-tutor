#include <stdio.h>  
#include <stdlib.h>  
#include "../include/linked_list.h"  

Node* create_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert_head(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d", current->data);
        printf(" -> ");
        current = current->next;
    }
    printf("NULL \n");
}

void reverse_list(Node **head) {
    Node *prev = NULL;
    Node *next = NULL;
    Node *current = *head;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void delete_node(Node **head, int data) {
    if (!*head) return;

    if ((*head)->data == data) {
        Node *target = *head;
        *head = (*head)->next;
        free(target);
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    if (current->next) {
        Node *target = current->next;
        current->next = current->next->next;
        free(target);
    }
}
