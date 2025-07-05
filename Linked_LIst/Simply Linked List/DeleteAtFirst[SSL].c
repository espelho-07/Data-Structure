//Delete At First

#include<stdio.h>
#include<stdlib.h>

//Declaring Structure Of Node
struct node
{
    int info;
    struct node * link;
};

// Function To Delete At First
struct node * deleteAtFirst(struct node * first)
{
    if (first == NULL)
    {
        printf("Your Linked List Is Empty.Nothing To DELETE!!!");
    }
    else
    {
        struct node * save = first;
        first=first->link;
        free(save);
        return first; 
    }
}

// Function to print the linked list
void printList(struct node *save)
{
    printf("Current Linked List: ");
    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

// main method
int main()
{
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
    fourth->link = NULL;

    // Display original list
    printList(first);

    // Calling Function
    first = deleteAtFirst(first);

    // Display current list
    printList(first);

}