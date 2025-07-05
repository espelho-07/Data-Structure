//Delete At Last

#include<stdio.h>
#include<stdlib.h>

//Declaring Structure of node
struct node
{
    int info;
    struct node * link;
};

//Function For Delete At Last
struct node * deleteAtLast(struct node * first)
{
    if (first == NULL)
    {
        printf("Nothing To Delete!! Linked Listv Is Empty.\n");
    }
    else
    {
        struct node * save = first;
        struct node * pred = NULL;

        while (save->link != NULL)
        {
            pred=save;
            save=save->link;
        }
        printf("Deleted node with value %d\n", save->info);
        pred->link=NULL;
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
    first = deleteAtLast(first);

    // Display Current list
    printList(first);

}
