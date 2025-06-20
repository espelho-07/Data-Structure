#include <stdio.h>
#include <stdlib.h>

struct node{
    int element;
    struct node *link;
};

struct node *first = NULL; 


void INSERT(int element){
    struct node *newNode = (struct node)malloc(sizeof(newNode));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }

    newNode->element = element;

    if (first == NULL) {
        newNode->link = NULL;
        first = newNode;
    }else{
        newNode->link=first;
        first=newNode;
    }
}

int main(){
    INSERT(10);
    INSERT(20);
    return 0;
}