//Linked List Equality

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

// Function to compare two linked lists
int linkedListEqual(struct node *first1, struct node *first2) {
    while (first1 != NULL && first2 != NULL) {
        if (first1->info != first2->info) {
            printf("Linked Lists are NOT the same.\n");
            return 0;
        }
        first1 = first1->link;
        first2 = first2->link;
    }

    if (first1 == NULL && first2 == NULL) {
        printf("Linked Lists are the SAME.\n");
        return 1;
    } else {
        printf("Linked Lists are NOT the same (length mismatch).\n");
        return 0;
    }
}

int main() {
    // First linked list: 1 -> 3 -> 5 -> 7
    struct node *first1, *second1, *third1, *fourth1;
    first1 = (struct node *)malloc(sizeof(struct node));
    second1 = (struct node *)malloc(sizeof(struct node));
    third1 = (struct node *)malloc(sizeof(struct node));
    fourth1 = (struct node *)malloc(sizeof(struct node));

    first1->info = 1;
    first1->link = second1;
    second1->info = 3;
    second1->link = third1;
    third1->info = 5;
    third1->link = fourth1;
    fourth1->info = 7;
    fourth1->link = NULL;

    // Second linked list: 1 -> 3 -> 5 -> 7
    struct node *first2, *second2, *third2, *fourth2;
    first2 = (struct node *)malloc(sizeof(struct node));
    second2 = (struct node *)malloc(sizeof(struct node));
    third2 = (struct node *)malloc(sizeof(struct node));
    fourth2 = (struct node *)malloc(sizeof(struct node));

    first2->info = 1;
    first2->link = second2;
    second2->info = 3;
    second2->link = third2;
    third2->info = 5;
    third2->link = fourth2;
    fourth2->info = 7;
    fourth2->link = NULL;

    // Compare the two linked lists
    linkedListEqual(first1, first2);

    // Free allocated memory
    free(first1); free(second1); free(third1); free(fourth1);
    free(first2); free(second2); free(third2); free(fourth2);

    return 0;
}