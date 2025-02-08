#ifndef LINKED_LIST_H  
#define LINKED_LIST_H  

typedef struct Node {  
    int data;  
    struct Node *next;  
} Node;

Node* create_node(int data);  
void insert_head(Node **head, int data);  
void print_list(Node *head);  
void reverse_list(Node **head);  
void delete_node(Node **head, int data);  

#endif
