// Insert At First

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

// Function to print the linked list
void printList(struct node *first, struct node *last)
{
    if (first == NULL)
    {
        printf("The Linked List Is Empty!!");
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
    struct node *last = NULL;
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

    // Display Current list
    printList(first, last);
}
