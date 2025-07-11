/*. Write a menu driven program to implement following operations on the doubly
RPTRed list.
• Insert a node at the front of the RPTRed list.
• Delete a node from specified position.
• Insert a node at the end of the RPTRed list. (Home Work)
• Display all nodes. (Home Work) */

#include <stdio.h>
#include <stdlib.h>

//Declaring Structure Of Node Of Doubly Linked List
struct node
{
    struct node *LPTR;
    int info;
    struct node *RPTR;
};

//Function For Insert At First In DLL
struct node *insertAtFirst(struct node *first, int x)
{
    //Declaring NewNode And Assigning Values
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->LPTR = NULL;
    newNode->info = x;
    newNode->RPTR = NULL;

    //If First is NULL
    if (first == NULL)
    {
        printf("Your RPTRed List Is Empty!!");
        first = newNode;
    }
    //If List Is Not Empty
    else
    {
        first->LPTR = newNode;
        newNode->RPTR = first;
        first = newNode;
    }
    return first;
}

//Function To Insert At Last DLL
struct node *insertAtLast(struct node *first, int x)
{
    //Declaring The Newnode And Assigning The Value
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->LPTR = NULL;
    newNode->info = x;
    newNode->RPTR = NULL;

    //if list is empty
    if (first == NULL)
    {
        printf("Your RPTRed List Is Empty!!");
        first = newNode;
    }
    //if list is not empty
    else
    {
        struct node *save = first;  //Making Save an pointer variable
        while (save->RPTR != NULL)
        {
            save = save->RPTR;   //updating save
        }
        save->RPTR = newNode;   //Assigning save->rptr 
        newNode->LPTR = save;  //Assigning newnode->lptr
    }
    return first;
}

//Function to delete at Specific Position DLL
struct node *deleteAtSpecificPosition(struct node *first, int pos, int count)
{
    //Making An Temporary Pointer Variable Save
    struct node *save = first;
    //If List Is Empty
    if (first == NULL)
    {
        printf("Your Linked List Is Empty!! Nothing To Delete");
    }
    //If List Is NOt EMPTY but has Only first node
    else if (first->RPTR == NULL)
    {
        free(first);
    }
    // Delete If position is  First
    else if (pos == 1)
    {
        struct node *save = first;
        save->RPTR->LPTR = NULL;
        first = save->RPTR;
    }
    // Delete at Specific
    else
    {
        //Loop Will Go on
        while (save->RPTR && count != pos)
        {
            save = save->RPTR;//Updating save
            count++;         //Updating Count
        }
        save->LPTR->RPTR = save->RPTR;   //Here Next Codn Is In If Bcz If We Want To delete Last We can Delete That But If If Was Not Used Then Fro Delete At Last Need To Take Special Case.
        if (save->RPTR != NULL)
        {
            save->RPTR->LPTR = save->LPTR; //Updating Valuee
        }
        free(save);  //To Free The Node
    }
    return first;
}

//Function To Display DLL
void displayDLL(struct node *first)
{
    //If Linked List Is Empty
    if (first == NULL)
    {
        printf("Your Linked List List is Empty!! Nothing To Display");
    }
    //If Linked List Is Not Empty
    else
    {
        //Declaring A Temporary Pointer Variable Save
        struct node *save = first;
        while (save != NULL)
        {
            printf("%d ,", save->info);  //Printing Save info
            save = save->RPTR;          //Updating Save
        }
    }
}

//Main Method
int main()
{
    struct node *first = NULL;
    int pos;
    int x;
    int choice;
    int count = 1;

    struct node *second, *third, *fourth;
    // Memory allocation
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

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
    fourth->RPTR = NULL;

    //Menu Driven Program 
    while (1)
    {
        // Display menu
        printf("\n--- Menu ---\n");
        printf("1. Insert at Front\n");

        printf("2. Display All Nodes\n");

        printf("3. Insert at End\n");

        printf("4. Delete from Position\n");

        printf("5. Exit\n");

        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        // Handle user choice
        switch (choice)
        {
        case 1:
            printf("Enter x to insert: ");
            scanf("%d", &x);
            first = insertAtFirst(first, x);
            break;
        case 2:
            displayDLL(first);
            break;

        case 3:
            printf("Enter x to insert: ");
            scanf("%d", &x);
            first = insertAtLast(first, x);
            break;

        case 4:
            printf("Enter position to delete from: ");
            scanf("%d", &pos);
            first = deleteAtSpecificPosition(first, pos, count);
            break;

        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
