#include<stdio.h>

int s = 70;
char queue[s];
int f = -1;
int r = -1;

struct priority{
    int priority;
    int value;
};


void enqueue(int n ,int pri){
    if (r >= n){
        printf("Queue Owerflow");
        return;
    }
    r++;
    queue[r].value = n;
    queue[r].priority = pri;
    if (f == -1){
        f = 0;
    }
}

void dequeue(){
    if (f < 0){
        printf("Queue Underflow");
        return;
    }
    else {
        int temp;
        if (f == r){
            temp = queue[f];
            r = -1;
            f = -1;
            return temp;
        }
        int index = 0;
        temp = queue[f].priority
        for (int i = f ;i <= r ;i++){
            if (temp < queue[i].priority){
                temp = queue[i].priority;
                index = i;
            }
        }
        for (int i = index ;i <= r-1 ;i++){
            queue[i] = queue[i+1];
        }
        r--;
        return temp;
    }
}

void display(){
    for (int i = f ;i <= r ;i++){
        printf("%d\t",queue[i]);
    }
}

void main(){
    int choice ,priority ,value;
    while(1){
        printf("\nEnter 1 to enqueue value");
        printf("\nEnter 2 to dequeue value");
        printf("\nEnter 3 to display queue");
        printf("\nEnter 4 to exit program");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice){
        case 1: printf("Enter value and priority : ");
                scanf("%d %d",&value,&priority);
                enqueue(value ,priority);
                break;

        case 2: printf("Value we get is %d.",dequeue());
                break;

        case 3: display();
                break;

        case 4: return;
                break;
        
        default: printf("Invalid choice!");
                 break;
        }
    }
}