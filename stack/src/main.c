#include <stdio.h>
#include "../include/stack.h"
#include "../include/linked_list.h"

#include <stdio.h>  
#include <stdlib.h>  
#include "../include/linked_list.h"  

int main() {  
    Node *top = NULL;  

    // Push elements onto the stack  
    push(&top, 10);  
    push(&top, 20);  
    push(&top, 30);  

    // Print the stack  
    printf("Stack before freeing:\n");  
    print_stack(top);  // Output: 30 -> 20 -> 10 -> NULL  

    // Free the stack  
    free_stack(&top);  

    // Verify the stack is empty  
    printf("Stack after freeing:\n");  
    print_stack(top);  // Output: NULL  

    // Check if top is NULL  
    if (top == NULL) {  
        printf("Stack freed successfully!\n");  
    } else {  
        printf("Error: Stack not freed properly.\n");  
    }  

    return 0;  
}  
