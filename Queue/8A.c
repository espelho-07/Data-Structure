// Write a menu driven program to implement following operations on the Queue
// using an Array
// • E5QUEUE
// • DEQUEUE
// • DISPLAY

// 5 - no. of elements in array
//  noToInsert- no. to insert in array
//  f- front from where deletion occours
//  r- rear from where deletion occours
//  q- is our queue

#include <stdio.h>
#include<stdlib.h>


int Q[5] = {3,4,5};
int F = -1;
int R = -1;

void enQueue(int numberToInsert)
{
    if (R > 5)
    {
        printf("Queue Overflow");
        return;
    }
    else
    {
        R = R + 1;
        Q[R] = numberToInsert;
        if (F = -1)
        {
            F = 0;
        }
    }
}

void deQueue()
{
    if (R < F)
    {
        printf("Queue UnderFlow");
        return;
    }
    else
    {
        if (F = R)
        {
            F = R = 0;
        }
        else
        {
            F = F + 1;
        }
    }
}

void displayQueue()
{
    F=0,R=4;
    for (int i = F; i <= R; i++)
    {
        printf("The %d Element in Queue Is - %d\n", i + 1,Q[i]);
    }
}

int main()
{
    int numberToInsert;
    int choice;
    while (1)
    {
        // Display menu
        printf("\n--- Menu ---\n");
        printf("1. EnQueue\n");

        printf("2. DeQueue\n");

        printf("3. Display\n");

        printf("4. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);

        // Handle user choice
        switch (choice)
        {
        case 1:
            printf("Enter Number to EnQueue: ");
            scanf("%d", &numberToInsert);
            enQueue(numberToInsert);
            break;
        case 2:
            deQueue();
            break;

        case 3:
           displayQueue();
            break;

        case 4:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}