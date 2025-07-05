// Queue Using Linked List
// As Queue Means First in Woul be first out so for that insert at first and delte at end.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

// Function To Create New Linked List
struct node *inqueue(int firstNode, int noOfNodes, int restNodes, struct node *First)
{
    // Assigning Memory
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    // For First Node
    newNode->info = firstNode;
    newNode->link = NULL;
    First = newNode;
    // Declaring Save=first Fore Input of Rest of Nodes
    struct node *Save = First;
    // For Rest Of The Nodes
    for (int i = 2; i <= noOfNodes; i++)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        // Input For Rest Of Nodes
        printf("The %d Node IS::\n", i);
        scanf(" %d", &restNodes);
        // Assigning Values
        newNode->info = restNodes;
        newNode->link = NULL;
        Save->link = newNode;
        Save = newNode;
    }
    return First;
}
// Function To Delete At First
struct node *dequeue(struct node *first)
{
    if (first == NULL)
    {
        printf("Your Linked List Is Empty.Nothing To DELETE!!!");
    }
    else
    {
        struct node *save = first;
        first = first->link;
        printf("Deleted node with value %d\n", save->info);
        free(save);
        return first;
    }
}

// Function To display
void displayLinkedList(int noOfNodes, struct node *First)
{
    if (First == NULL)
    {
        printf("The List Is Empty");
    }
    struct node *display = First;
    for (int i = 1; i <= noOfNodes; i++)
    {
        printf("Node %d: %d\n", i, display->info);
        display = display->link;
    }
}

// Main Method
int main()
{
    struct node *First = NULL;
    int noOfNodes, firstNode, restNodes, choice;

    for (int i = 1; i > 0; i++)
    {
        // Asking Choice
        printf("Enter Your Choice -\n 1- TO INQUEUE \n 2- TO DEQUEUE\n 3- To DISPLAY\n");
        scanf(" %d", &choice);
        if (choice == 1)
        {
            // Asking No. of nodes
            printf("Enter The Number Of Nodes You want In Linked List::\n");
            scanf(" %d", &noOfNodes);

            // Asking About First Node
            printf("Enter The Data Of First Node::\n");
            scanf(" %d", &firstNode);

            First = inqueue(firstNode, noOfNodes, restNodes, First);
        }
        else if (choice == 2)
        {
            First = dequeue(First);
        }
        else if (choice == 3)
        {
            displayLinkedList(noOfNodes, First);
        }
        else
        {
            printf("Enter Valid Choice From 1 And 2\n");
            exit(1);
        }
    }
}