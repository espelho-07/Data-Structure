// Insert At Last

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *last = NULL;

struct node *deleteAtPosition(int x, struct node *first, int i)
{
    if (first == NULL)
    {
        printf("Your Linked List Is Empty\n");
    }
    struct node *save = first;
    struct node *pred = NULL;
    while (i != x && save->link != first)
    {
        pred = save;
        save = save->link;
        i++;
    }
    pred->link = save->link;
    free(save);
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
    // Declaring First
    struct node *first = NULL;

    // Declaring X
    int x;
    int i = 1;

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
    printf("Enter Value Of X The Position Of Node You Want To Delete::\n");
    scanf(" %d", &x);
    if (x > 4 || x <= 0)
    {
        printf("invalid input");
    }
    else
    {

        // Calling Function
        deleteAtPosition(x, first , i);

        // Display Current list
        printList(first);
    }
}
