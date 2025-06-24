//Insert At Last In Single Linear Linked List

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int info;              // Data part of the node
    struct node *link;     // Pointer to the next node
};

// Declare a global pointer that will always point to the head of the list
struct node *first = NULL;

// Function prototype to insert a node at the end
struct node* InsertAtLast(int x);

int main() {
    int x;

    // Ask user to enter a value to be added to the list At End
    printf("Enter the value to insert at the end:\n");
    scanf("%d", &x);

    // Call the function and update the global 'first' pointer
    first = InsertAtLast(x);

    return 0;
}

// Function to insert a new node at the end of the linked list
struct node* InsertAtLast(int x) {
    // Dynamically allocate memory for the new node
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    // Assign the value and set the next pointer to NULL since this will be the last node
    newnode->info = x;
    newnode->link = NULL;

    // If the list is empty, make the new node the first node
    if (first == NULL) {
        first = newnode;
    } else {
        // Otherwise, traverse the list to reach the last node
        struct node *save = first;
        while (save->link != NULL) {
            save = save->link;
        }
        // Link the last node to the new node
        save->link = newnode;
    }

    // Return the head of the list
    return first;
}