//Sort SLL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

// Function to insert node at the end
struct node *insertEnd(struct node *First, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->link = NULL;

    if (First == NULL) {
        return newNode;
    }

    struct node *temp = First;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
    return First;
}

// Function to sort the linked list in ascending order
struct node *sortLinkedList(struct node *First) {
    if (First == NULL) {
        printf("Your Linked List Is Empty!!\n");
        return NULL;
    }

    struct node *i, *j;
    int temp;

    for (i = First; i != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->info > j->info) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }

    return First;
}

// Function to display the linked list
void displayLinkedList(struct node *First) {
    if (First == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    struct node *display = First;
    int i = 1;
    while (display != NULL) {
        printf("Node %d: %d\n", i++, display->info);
        display = display->link;
    }
}

// Main method
int main() {
    struct node *First = NULL;
    int noOfNodes, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &noOfNodes);

    for (int i = 1; i <= noOfNodes; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        First = insertEnd(First, data);
    }

    printf("\nOriginal Linked List:\n");
    displayLinkedList(First);

    First = sortLinkedList(First);

    printf("\nSorted Linked List:\n");
    displayLinkedList(First);

    return 0;
}