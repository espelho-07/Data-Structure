#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int info;
    struct node *link;
};

// Global pointer to the head of the list
struct node *first = NULL;

// Function prototype to delete the first node
struct node* deleteAtFirst();

int main() {
    // Call the function to delete the first node
    first = deleteAtFirst();

    return 0;
}

// Function to delete the first node of the linked list
struct node* deleteAtFirst() {
    // If the list is empty, do nothing
    if (first == NULL) {
        return NULL;
    }

    // Store the first node in a temporary pointer
    struct node *temp = first;

    // Move the head pointer to the next node
    first = first->link;

    // Free memory of the old first node
    free(temp);

    // Return the updated head pointer
    return first;
}