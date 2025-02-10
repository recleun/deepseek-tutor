#ifndef BST_H
#define BST_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int data);
Node* free_node(Node *root, int data);
void insert(Node **root, int data);
Node* search(Node *root, int data);
void inorder_traversal(Node *root);
void free_tree(Node **root);

#endif
