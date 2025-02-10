#include <stdlib.h>
#include <stdio.h>
#include "../include/bst.h"

Node* create_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }

    if ((*root)->data > data) {
        insert(&(*root)->left, data);
    } else if ((*root)->data < data) {
        insert(&(*root)->right, data);
    }
}

Node* search(Node *root, int data) {
    if (root->data == data) return root;
    else if (root->data > data) return search(root->left, data);
    else if (root->data < data) return search(root->right, data);
    else return NULL;
}

void inorder_traversal(Node *root) {
    if (root) {
        if (root->left) inorder_traversal(root->left);
        printf("%d ", root->data);
        if (root->right) inorder_traversal(root->right);
    } else {
        printf("NULL");
    }
}

Node* free_node(Node *root, int data) {
    if (!root) return NULL;
    Node *parent = NULL;
    Node *current = root;

    while (current->data != data) {
        parent = current;
        if (current->data > data) {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current == NULL) return root;
    }

    // if there are no children
    if (!current->left && !current->right) {
        if (parent) {
            if (parent->left->data == data) parent->left = NULL;
            if (parent->right->data == data) parent->right = NULL;
        }
        free(current);
        return NULL;
    }

    // if there is only a left child
    if (current->left && !current->right) {
        Node *new_node = current->left;
        if (parent) {
            if (parent->left->data == data) {
                parent->left = current->left;
            }
            if (parent->right->data == data) {
                parent->right = current->left;
            }
        }
        free(current);
        return new_node;
    // if there is only a right child
    } else if (current->right && !current->left) {
        Node *new_node = current->right;
        if (parent) {
            if (parent->left->data == data) {
                parent->left = current->right;
            }
            if (parent->right->data == data) {
                parent->right = current->right;
            }
        }
        free(current);
        return new_node;
    }

    // if there are two children
    Node *new_parent = current;
    Node *new_current = current->right;
    while (new_current->left != NULL) {
        new_parent = new_current;
        new_current = new_current->left;
    }

    new_current->left = current->left;
    if (current->right != new_current) new_current->right = current->right;

    if (parent) {
        if (parent->left == current) parent->left = new_current;
        else if (parent->right == current) parent->right = new_current;
    } else {
        root = new_current;
    }
    
    free(current);
    new_parent->left = NULL;
    return new_current;
}

void free_tree(Node **root) {
    if (!*root) return;
    free_tree(&(*root)->left);
    free_tree(&(*root)->right);
    free(*root);
    *root = NULL;
}

