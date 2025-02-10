#include <stdio.h>
#include "../include/bst.h"

int main() {  
    Node *root = NULL;  

    // Insert values into the BST  
    insert(&root, 50);  
    insert(&root, 30);  
    insert(&root, 70);  
    insert(&root, 20);  
    insert(&root, 40);  
    insert(&root, 60);  
    insert(&root, 80);  

    // Print the BST in sorted order  
    printf("Inorder traversal: ");  
    inorder_traversal(root);  // Output: 20 30 40 50 60 70 80
    printf("\n");

    // Search for a value  
    Node *result = search(root, 40);  
    if (result) printf("Found: %d\n", result->data);  // Output: Found: 40  

    // Delete a value  
    free_node(root, 30);  
    printf("Inorder traversal after deletion: ");  
    inorder_traversal(root);  // Output: 20 40 50 60 70 80  
    printf("\n");

    // Free the BST  
    free_tree(&root);  
    return 0;  
}  
