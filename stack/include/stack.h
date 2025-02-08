#ifndef STACK_H
#define STACK_H
#include "./linked_list.h"

void push(Node **top, int data);
int pop(Node **top);
int peek(Node *top);
int is_empty(Node *top);
void print_stack(Node *top);
void free_stack(Node **top);

#endif
