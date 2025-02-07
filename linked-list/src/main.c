#include <stdio.h>  
#include <stdlib.h>  
#include "../include/linked_list.h"  

int main() {  
    // Create an empty list  
    Node *head = NULL;  

    // Insert values 1 to 5  
    for (int i = 5; i >= 1; i--) {  
        insert_head(&head, i);  
    }  

    // Print the original list  
    printf("Original List: ");  
    print_list(head);  // Output: 1 -> 2 -> 3 -> 4 -> 5 -> NULL  

    // Reverse the list  
    reverse_list(&head);  

    // Print the reversed list  
    printf("Reversed List: ");  
    print_list(head);  // Output: 5 -> 4 -> 3 -> 2 -> 1 -> NULL  

    return 0;  
}
