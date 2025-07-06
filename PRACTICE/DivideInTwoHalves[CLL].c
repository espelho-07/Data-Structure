#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *last = NULL;

// Function prototype to prevent compiler warnings
void printList(struct node *first);

// Function to divide a circular linked list into two halves at position x
struct node *divideInHalves(int x, struct node *first, int i, struct node *last)
{
    if (first == NULL)
    {
        printf("Your Linked List Is Empty\n");
        return NULL;
    }

    struct node *save = first->link;
    struct node *pred = first;
    i++;

    while (i != x && save->link != first)
    {
        pred = save;
        save = save->link;
        i++;
    }

    // Divide into two circular halves
    pred->link = first;     // first half ends at pred and loops to first
    last->link = save;      // second half starts at save and loops to last

    printf("\nFirst Half:\n");
    printList(first);

    printf("\nSecond Half:\n");
    printList(save);

    return first;
}

// Function to print circular linked list
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

// Main method
int main()
{
    struct node *first = NULL;
    int x;
    int i = 0;

    // Creating sample circular linked list
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

    printList(first);

    printf("Enter Value Of X The Position Where You Want To Divide:\n");
    scanf(" %d", &x);

    if (x > 4 || x <= 0)
    {
        printf("Invalid input\n");
    }
    else
    {
        divideInHalves(x, first, i, last);
    }

    return 0;
}