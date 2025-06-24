//Insert At End In Circular Linked List

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int info;              // Data to store
    struct node *link;     // Pointer to the next node
};

// Global pointer to the first node
struct node *first = NULL;

// Function to insert a new node at the end of a circular linked list
struct node *InsertAtEnd(int x) {
    //Allocate memory for the new node
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    // Assign data to the new node
    newnode->info = x;

    // If the list is empty
    if (first == NULL) {
        newnode->link = newnode;  // Point to itself to make it circular
        first = newnode;          // Set first to this new node
    } else {
        // Traverse to the last node
        struct node *save = first;
        while (save->link != first) {
            save = save->link;
        }

        // Insert the new node at the end
        newnode->link = first;    // New node links back to the first node
        save->link = newnode;     // Last node links to the new node
    }

    // Return the head pointer (unchanged)
    return first;
}