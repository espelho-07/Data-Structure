//Insert At First In Circular Linked List

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int info;              // Data to store
    struct node *link;     // Pointer to the next node
};

// Global pointer to the first node in the list
struct node *first = NULL;

// Function to insert a new node at the beginning of a circular linked list
struct node *InsertAtFirst(int x) {
    // Step 1: Allocate memory for the new node
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    // Step 2: Assign data to the new node
    newnode->info = x;

    // Step 3: If the list is empty (first node being inserted)
    if (first == NULL) {
        newnode->link = newnode;  // Point it to itself to make it circular
        first = newnode;          // Set first to this new node
    } else {
        // Step 4: Traverse to the last node
        struct node *save = first;
        while (save->link != first) {
            save = save->link;
        }

        // Step 5: Link the new node into the list
        newnode->link = first;    // New node points to the current first node
        save->link = newnode;     // Last node points to the new node

        // Step 6: Update first to point to the new node
        first = newnode;
    }

    // Step 7: Return the updated first pointer
    return first;
}