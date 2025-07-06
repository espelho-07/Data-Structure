// Insert At Last

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *last = NULL;

struct node *insertAtLast(int x, struct node *first)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;
    if (first == NULL)
    {
        printf("Your Linked List Is Empty\n");
        newNode->link = newNode;
        last = newNode;
        return newNode;
    }
    else
    {
        last->link = newNode;
        newNode->link = first;
        last = newNode;
        return first;
    }
}
// Function to print the linked list
void printList(struct node *first)
{
    if (first == NULL)
    {
        printf("The Linked List Is Empty!!\n");
    }
    else
    {
        struct node *save = first;
        printf("Current Linked List: ");
        while (save->link != first)
        {
            printf("%d -> ", save->info);
            save = save->link;
        }
        // Print the last node
        printf("%d (back to start)\n", save->info);
    }
}

// main method
int main()
{
    // Declaring X
    int x;
    // Declaring First
    struct node *first = NULL;

    // Sample Linked List
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

    // Display original list
    printList(first);

    // Asking Value Of First Node
    printf("Enter Value Of X The Data Of Node You Want To Insert At Last::\n");
    scanf(" %d", &x);

    // Calling Function
    first = insertAtLast(x, first);

    // Display Current list
    printList(first);
}
