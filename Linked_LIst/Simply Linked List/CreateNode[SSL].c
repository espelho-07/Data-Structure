// Write a program to implement a node structure for singly linked list. Read the data in a node, print the node.

#include<stdio.h>
#include<stdlib.h>

//Creating Structure Of Node
struct node
{
    int info;
    struct node * link;
};

//Taking FIRST as Global Pointer
struct node * First = NULL;

//Function For Create A New Node In Linked List
struct node * createNewNode(int x)
{
    //Assigning Memory To Newnode
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    //Assigning Value To newNode          
    newNode->info = x;
    newNode->link = NULL;
    return newNode;
}


//main Function
int main()
{
    int x;
    
    //Asking Value Of x
    printf("Enter The Data X You Want To Enter In The Node::\n");
    scanf(" %d", &x);
    //Calling A Function
    struct node * newNode = createNewNode(x);
    //Printing Newly Created Node
    printf("The Data Of New Node Entered Is::%d\n", newNode->info );
}
