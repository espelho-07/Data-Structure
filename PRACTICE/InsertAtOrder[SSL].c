//Insert At According To Order Maintain Order

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node * link;
};

struct node * insertInOrder(int x , struct node * first)
{
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    //For New Node
    newNode->info = x;
    newNode->link = NULL;
    //Checking If List Is Empty or Not

    // Case 1: Empty list or insert at beginning
    if (first == NULL || x < first->info) {
        newNode->link = first;
        return newNode;
    }
    else
    {
        // Case 2: Insert in the middle or end
        struct node * save = first;
        struct node * pred = NULL;

        while (save != NULL && save->info < x)
        {
            pred=save;
            save=save->link;
        }
        pred->link = newNode;
        newNode->link = save;
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
    printf("Enter Value Of X The Data Of Node You Want To Insert::\n");
    scanf(" %d", &x);
    
    // Calling Function
    first = insertInOrder(x, first);

    // Display Current list
    printList(first);

}

