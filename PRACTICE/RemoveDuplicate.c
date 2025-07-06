#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

// Function to remove duplicates
struct node* RemoveDuplicate(struct node* first) {
    if (first == NULL) {
        printf("The Linked List Is Empty!!\n");
        return first;
    }

    struct node* current = first;

    while (current != NULL && current->link != NULL) {
        if (current->info == current->link->info) {
            printf("Repeated Node Data Is :: %d\n", current->info);
            struct node* save = current->link;
            current->link = save->link;
            free(save);
        } else {
            current = current->link;
        }
    }

    return first;
}

// Function to print the linked list
void printList(struct node* first) {
    struct node* save = first;
    printf("Current Linked List: ");
    while (save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

// Main method
int main() {
    struct node* first = NULL;
    struct node* second, *third, *fourth;

    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    first->info = 4;
    first->link = second;

    second->info = 4;
    second->link = third;

    third->info = 4; // duplicate for demo
    third->link = fourth;

    fourth->info = 8;
    fourth->link = NULL;

    printList(first);
    first = RemoveDuplicate(first);
    printList(first);

    return 0;
}