#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct item {
    int value;
    int priority;
};

struct item PriorityQueue[SIZE];
int count = 0; 


void enQueue(int val, int pri) {
    if (count == SIZE) {
        printf("Priority Queue Overflow!\n");
        return;
    }
    PriorityQueue[count].value = val;
    PriorityQueue[count].priority = pri;
    count++;
    printf("Inserted: %d with priority %d\n", val, pri);
}


int getHighestPriorityIndex() {
    int i, highest = 0;
    for (i = 1; i < count; i++) {
        if (PriorityQueue[i].priority < PriorityQueue[highest].priority) {
            highest = i;
        }
        
    }
    return highest;
}


void deQueue() {
    if (count == 0) {
        printf("Priority Queue Underflow!\n");
        return;
    }
    int index = getHighestPriorityIndex();
    printf("Deleted: %d with priority %d\n", PriorityQueue[index].value, PriorityQueue[index].priority);

    
    for (int i = index; i < count - 1; i++) {
        PriorityQueue[i] = PriorityQueue[i + 1];
    }
    count--;
}


void displayQueue() {
    if (count == 0) {
        printf("Priority Queue is Empty!\n");
        return;
    }
    printf("Priority Queue elements: \n");
    for (int i = 0; i < count; i++) {
        printf("Value: %d  Priority: %d\n", PriorityQueue[i].value, PriorityQueue[i].priority);
    }
}

int main() {
    int choice, val, pri;
    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. EnQueue\n");
        printf("2. DeQueue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter its priority (smaller = higher priority): ");
                scanf("%d", &pri);
                enQueue(val, pri);
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
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
