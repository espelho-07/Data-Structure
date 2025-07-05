// Forming An Linked List

#include <stdio.h>
#include <stdlib.h>
//Strcture of node
struct node
{
    int info;
    struct node *link;
};
//Declaring Global Variable

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
}
//Function To display
void displayLinkedList(int noOfNodes , struct node * First) {
    struct node *display = First;
    for (int i = 1; i <= noOfNodes; i++)
    {
        printf("Node %d: %d\n", i, display->info);
        display = display->link;
    }
}
//Main Method
int main()
{
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
}