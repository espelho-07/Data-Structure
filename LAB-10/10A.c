// Write a program to implement a node structure for singly linked list. Read the data in a node, print the node.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *Link;
    ;
};

struct node *first = NULL;

struct node *newnode(int info)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = info;
    newnode->Link = NULL;
    return newnode;
}

void main()
{
    int info;
    printf("Enter A Number :\n");
    scanf("%d",&info);
    struct node *first=newnode(info);
    printf("Data Inside This Node Is %d",first->info);
    free(first);

}