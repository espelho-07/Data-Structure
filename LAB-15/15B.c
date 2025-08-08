// WAP to delete alternate nodes of a doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *LPTR;
    int info;
    struct node *RPTR;
};

// Function to delete at Specific Position DLL
struct node *deleteAtAlternatePosition(struct node *first)
{

    // If List Is Empty
    if (first == NULL)
    {
        printf("Your Linked List Is Empty!! Nothing To Delete");
    }
    // If List Is NOt EMPTY but has Only first node
    else if (first->RPTR == NULL)
    {
        printf("We Can't Start As We Didn't See Any Alternate Node\n");
    }

    // Delete at Alternate Logic
    else
    {
        // Making An Temporary Pointer Variable Save & pred
        struct node *pred = first;
        // Loop Will Go on until
        while ( pred->RPTR != NULL)
        {
            
            struct node *save = pred->RPTR;
            struct node *temp = save;

            save->RPTR->LPTR = pred;
            save->LPTR->RPTR = save->RPTR;

            pred = save->RPTR;

            free(temp);
        }
        
    }
}

// Function To Display DLL
void displayDLL(struct node *first)
{
    // If Linked List Is Empty
    if (first == NULL)
    {
        printf("Your Linked List List is Empty!! Nothing To Display");
    }
    // If Linked List Is Not Empty
    else
    {
        // Declaring A Temporary Pointer Variable Save
        struct node *save = first;
        while (save != NULL)
        {
            printf("%d ,", save->info); // Printing Save info
            save = save->RPTR;          // Updating Save
        }
    }
}

// Main Method
int main()
{
    struct node *first = NULL;
    int choice;

    struct node *second, *third, *fourth , *fifth;
    // Memory allocation
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    // Assigning values and RPTRs
    first->info = 2;
    first->LPTR = NULL;
    first->RPTR = second;

    second->info = 4;
    second->LPTR = first;
    second->RPTR = third;

    third->info = 6;
    third->LPTR = second;
    third->RPTR = fourth;

    fourth->info = 8;
    fourth->LPTR = third;
    fourth->RPTR = fifth;

    fifth->info = 18;
    fifth->LPTR = fourth;
    fifth->RPTR = NULL;

    deleteAtAlternatePosition(first);
    displayDLL(first);
}
