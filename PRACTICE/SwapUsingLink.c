// Insert At First

#include <stdio.h>
#include <stdlib.h>
// Declaring Structure of Node
struct node
{
    int info;
    struct node *link;
};

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
u look so sexy
// Function to print the linked list
void printList(struct node *first)
{
    if (first==NULL)
    {
        printf("Your Linked List Is Empty!!");
    
    struct node * save = first;
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
    fourth->link = NULL;

    // Display original list
    printList(first);

    // Asking Value Of First Node
    printf("Enter Value Of X The Position Of Node You Want To Swap ::\n");
    scanf(" %d", &x);
    
    // Calling Function
    first = insertAtFirst(x, first);

    // Display Current list
    printList(first);

}
}