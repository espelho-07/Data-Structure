#include <stdio.h>
#include <stdlib.h>

// Function prototype
int happy(int x);

// Declaring Structure of Node
struct node
{
    int info;
    struct node *link;
};

// Declaring Insert At First Function
struct node *insertAtFirst(int x, struct node *first)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = first;

    if (first == NULL)
    {
        printf("Your List Is Empty. So Your NewNode Will Be Your FIRST Node\n");
    }

    happy(x);  // Calling happy number check
    first = newNode;
    return first;
}

// Happy Number Check Function
int happy(int x)
{
    int s, r;
    while (x != 1 && x != 4)
    {
        s = 0;
        while (x != 0)
        {
            r = x % 10;
            s += r * r;
            x = x / 10;
        }
        x = s;
    }

    if (x == 1)
    {
        printf("It is a Happy Number\n");
        return 1;
    }
    else
    {
        printf("It is NOT a Happy Number\n");
        return 0;
    }
}

// Function to print the linked list
void printList(struct node *first)
{
    if (first == NULL)
    {
        printf("Your Linked List Is Empty!!\n");
        return;
    }

    struct node *save = first;
    printf("Current Linked List: ");
    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

// Main method
int main()
{
    int x;
    struct node *first = NULL;

    printf("Enter Value Of X The Data Of Node You Want To Insert At First::\n");
    scanf(" %d", &x);

    first = insertAtFirst(x, first);
    printList(first);

    return 0;
}