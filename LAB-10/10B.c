/* Write a menu driven program to implement following operations on the singly
linked list.
• Insert a node at the front of the linked list.
• Display all nodes.
• Delete a first node of the linked list.
• Insert a node at the end of the linked list.
• Delete a last node of the linked list.
• Delete a node from specified position.
• count the number of nodes*/

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
}

// Insert At First
void InsertAtFirst(struct node *newnode,struct node*first)//struct node *newnode for newnode address 
{
    if (first == NULL)
    {
        printf("The Linked List In Which You Want To Insert Is EMPTY\n");
        first = newnode;
        return;
    }
    else
    {
        newnode->link = first;
        first = newnode;
        return;
    }

    // To Display All Nodes
    void DisplayAll(struct node * first)
    {
        if (first == NULL)
        {
            printf("There Is no Data Present\n");
        }
        else
        {
            struct node *save;
            save = first;
            while (save!= NULL)
            {
                printf("The Data Is %d", save->info);
                save = save->link;
            }
        }
    }

    // Delete a first node of the linked list.
    void DeleteFirst(struct node * first)
    {
        if (first == NULL)
        {
            printf("Nothing To Delete List Is Empty\n");
        }
        else
        {
            struct node *save;
            save = first;
            first = first->link;
            free(save);
        }
    }

    // Insert a node at the end of the linked list.
    void InsertAtLast(struct node *first, struct node *newnode)
    {
        if (first == NULL)
        {
            printf("The Linked List In Which You Want To Insert Is EMPTY\n");
            first = newnode;
            return;
        }
        else
        {

            struct node *save;
            save=first;
            while (save->link !=NULL)
            {
                save=save->link;
            }
            save=newnode->link;
        }
    }




    //Delete a last node of the linked list.
    void DeleteLast(struct node * first)
    {
        if (first == NULL)
        {
            printf("Nothing To Delete List Is Empty\n");
        }
        else
        {
            struct node *save;
            struct node *pred;
            save = first;
            while (save!= NULL)
            {
                pred=save;
                save=save->link;
            }
            pred->link=NULL;
            free(save);
        }
    }



    //Delete a node from specified position. 
    void DeleteFromSpecified(struct node * first,struct node *address)
    {
        if (first == NULL)
        {
            printf("Nothing To Delete List Is Empty\n");
        }
        else
        {
            struct node *save;
            struct node *pred;
            pred=NULL;
            save = first;
            while (save!=)
            {
                pred=save;
                save=save->link;
            }
            pred->link=NULL;
            free(save);
        }
    }