#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

// Function to create a new node with given info
struct node *newnode(int info)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info;
    temp->link = NULL;
    return temp;
}

//Function To Create New Linked List
struct node * createLinkedList(int firstNode, int noOfNodes, int restNodes , struct node * First)
{
    //Assigning Memory
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    //For First Node
    newNode->info = firstNode;
    newNode->link = NULL;
    First = newNode;
    //Declaring Save=first Fore Input of Rest of Nodes
    struct node *Save = First;
    //For Rest Of The Nodes
    for (int i = 2; i <= noOfNodes; i++)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        //Input For Rest Of Nodes
        printf("The %d Node IS::\n", i);
        scanf(" %d", &restNodes);
        //Assigning Values
        newNode->info = restNodes;
        newNode->link = NULL;
        Save->link = newNode;
        Save = newNode;
    }
    return First;

// Function to copy a linked list
struct node *copy(struct node *first)
{
    if (first == NULL)
        return NULL;

    struct node *save = first;
    struct node *newfirst = newnode(save->info);
    struct node *newsave = newfirst;

    while (save->link != NULL)
    {
        save = save->link;
        newsave->link = newnode(save->info);
        newsave = newsave->link;
    }

    return newfirst;
}

// Function to display a list
void display(struct node *first)
{
    while (first != NULL)
    {
        printf("%d -> ", first->info);
        first = first->link;
    }
    printf("NULL\n");
}

int main()
{
    struct node *original = NULL;
    struct node *copied = NULL;
    int n, value;
     struct node *First = NULL;
    int noOfNodes, firstNode, restNodes;
    //Asking No. of nodes
    printf("Enter The Number Of Nodes You want In Linked List::\n");
    scanf(" %d", &noOfNodes);
    //Asking About First Node
    printf("Enter The Data Of First Node::\n");
    scanf(" %d", &firstNode);
    //Calling Both Function
    First = createLinkedList(firstNode, noOfNodes, restNodes , First);
    displayLinkedList(noOfNodes , First);

    printf("How many Nodes do you want to enter? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter Node Info %d: ", i + 1);
        scanf("%d", &value);
        insert(&original, value);
    }

    printf("Original List: ");
    display(original);

    // Copy the list
    copied = copy(original);
    printf("Copied List:   ");
    display(copied);

    return 0;
}