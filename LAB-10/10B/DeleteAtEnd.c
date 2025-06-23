#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int info;               // Data part of the node
    struct node *link;      // Pointer to the next node
};

struct node *first = NULL;  // Initially, list is empty

// Function to delete the last node
struct node* deleteatend();

int main() {
    // Call the function and update the list
    first = deleteatend();
    return 0;
}

// Function to delete the last node in the linked list
struct node* deleteatend() {
    // If the list is empty
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    // If the list has only one node
    else if (first->link == NULL) {
        free(first);           // Free the only node
        return NULL;           // List is now empty
    }
    // If the list has more than one node
    else {
        struct node *save = first;     // Pointer to traverse the list
        struct node *pred = NULL;      // Pointer to keep track of previous node

        // Traverse the list to find the last node
        while (save->link != NULL) {
            pred = save;
            save = save->link;
        }

        pred->link = NULL;     // Detach the last node
        free(save);            // Free memory of last node
        return first;          // Return the updated list
    }
}