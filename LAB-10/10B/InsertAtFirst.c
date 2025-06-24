//Insert At First In Single Linear Linked List

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct node
{
    int info;          // Data part of the node
    struct node *link; // Pointer to the next node
};

// Declare a global pointer that always points to the start of the list
struct node *first = NULL;

// Function prototype (declaring the function before using it in main)
struct node *InsertAtFirst(int x);

int main()
{
    int x;
    printf("Enter The Value Of Element You Want To Enter:\n");
    scanf("%d", &x);

    // Call the function to insert at the beginning and update the head pointer
    first = InsertAtFirst(x);

    // Display the value of the first node after insertion
    printf("Element inserted at beginning: %d\n", first->info);
    return 0;
}

// Function to insert a new node at the beginning of the linked list
struct node *InsertAtFirst(int x)
{
    // Allocate memory for a new node
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    // Assign the data to the node
    newnode->info = x;

    // Link the new node to the current first node
    newnode->link = first;

    // Make the new node the first node
    first = newnode;

    // Return the updated head pointer
    return first;
}