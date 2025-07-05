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

// Function to insert a new node at the end of the original list
void insert(struct node **first, int info)
{
    struct node *temp = newnode(info);
    if (*first == NULL)
    {
        *first = temp;
    }
    else
    {
        struct node *p = *first;
        while (p->link != NULL)
            p = p->link;
        p->link = temp;
    }
}

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