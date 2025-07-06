#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void findDuplicate(struct node *first)
{
    if (first == NULL)
    {
        printf("The Linked List Is Empty!!\n");
        return;
    }

    struct node *save = first;
    while (save != NULL)
    {
        struct node *temp = save->link;
        while (temp != NULL)
        {
            if (save->info == temp->info)
            {
                printf("Duplicate found for value: %d\n", save->info);
                break; // Found one match, no need to check further
            }
            temp = temp->link;
        }
        save = save->link;
    }
}

// Function to print the linked list
void printList(struct node *first)
{
    struct node *save = first;
    printf("Current Linked List: ");
    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

// Main method
int main()
{
    struct node *first = NULL;
    struct node *second, *third, *fourth;

    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    first->info = 8;
    first->link = second;

    second->info = 4;
    second->link = third;

    third->info = 4; // duplicate for demo
    third->link = fourth;

    fourth->info = 8;
    fourth->link = NULL;

    printList(first);
    findDuplicate(first);
    
    return 0;
}