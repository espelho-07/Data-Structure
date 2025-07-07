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
        struct node *save = first;
        while (save != first)
        {
            save = save->link;
        }
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
    int x;
    int count=1;
    int i;
    int position;
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

    // Display original list
    displayCircularLinkedList(first);

    // Asking Value Of First Node
   // printf("\nEnter Value Of X The Data Of Node You Want To Insert At First::\n");
    //scanf(" %d", &x);

    printf("\nEnter Value Of X The Node You Want To Delete::\n");
    scanf(" %d", &position);

    // Calling Function
    //first = insertAtFront(first, x, last);

    deleteAtSpecific(first , position ,count);

    // Display Current list
    displayCircularLinkedList(first);
}
