/*Write a menu driven program to implement following operations on the circular
linked list.
• Insert a node at the front of the linked list.
• Delete a node from specified position.
• Insert a node at the end of the linked list.
• Display all nodes. */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *insertAtFront(struct node *first, int x, struct node *last)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;
    if (first == NULL)
    {
        printf("Your Linked List Is Empty!! Your Newnode Will Be Your first Node And Last Node Itself.\n");
        newNode->link = newNode;
        first = newNode;
        return first;
    }
    else
    {

        newNode->link = last->link;
        last->link = newNode;
        first = newNode;
        return first;
    }
}

struct node *deleteAtSpecific(struct node * first , int position , int count)
{
    if (first == NULL)
    {
        printf("Your Linked List Is Empty!! Nothing To DELETE  :)\n");
    }
    else
    {
        struct node * save = first;
        struct node * pred = NULL;
        while (save->link != first && count != position)
        {
            pred = save;
            save = save->link;
            count++;
        }
        pred->link = save->link;
        free(save);
    }
    
}

struct node *insertAtLast(struct node *first, int x, struct node *last)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;
    if (first == NULL)
    {
        printf("Your Linked List Is Empty!! Your Newnode Will Be Your first Node And Last Node Itself.\n");
        newNode->link = newNode;
        last = newNode;
        return first;
    }
    else
    {
        newNode->link = last->link;
        last->link = newNode;
        last = newNode;
        return first;
    }
}



void displayCircularLinkedList(struct node *first)
{
    struct node *save = first;
    if (first == NULL)
    {
        printf("Your Linked List Is Empty!! Nothing To DISPLAY  :)\n");
    }
    else
    {
        printf("Current Linked List::");
        do
        {
            printf(" %d ->", save->info);
            save = save->link;
        } while (save != first);
        printf(" (Points to start)\n");
    }
}

int main()
{
    int choice, x, position;
    int count = 1;
    struct node *first = NULL;
    struct node *last = NULL;

    // Sample initialization (optional; remove if starting from empty list)
    struct node *second, *third, *fourth;
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    first->info = 2;
    first->link = second;

    second->info = 4;
    second->link = third;

    third->info = 6;
    third->link = fourth;

    fourth->info = 8;
    fourth->link = first;
    last = fourth;

   while (1)
{
    printf("\n====== Circular Linked List Menu ======\n");
    printf("1. Insert at Front\n");
    printf("2. Insert at End\n");
    printf("3. Delete at Specific Position\n");
    printf("4. Display List\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter value to insert at front: ");
        scanf("%d", &x);
        first = insertAtFront(first, x, last);
        if (last == NULL)
            last = first;
        displayCircularLinkedList(first);
        break;

    case 2:
        printf("Enter value to insert at end: ");
        scanf("%d", &x);
        first = insertAtLast(first, x, last);
        if (last == NULL)
            last = first;
        displayCircularLinkedList(first);
        break;

    case 3:
        printf("Enter position to delete (starting at 1): ");
        scanf("%d", &position);
        deleteAtSpecific(first, position, 1); // Initial count = 1
        displayCircularLinkedList(first);
        break;

    case 4:
        displayCircularLinkedList(first);
        break;

    case 5:
        printf("Exiting program. Bye!\n");
        exit(0);

    default:
        printf("Invalid choice! Try again.\n");
    }
}
}