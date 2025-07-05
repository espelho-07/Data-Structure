//Find The Duplicates

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node * link;
};

struct node * findDuplicate(struct node * first)
{
    if (first==NULL)
    {
        printf("The Linked List Is Empty!!");
    }
    else
    {
        struct node * save = first->link;
        struct node * pred = first;

        while (save != NULL && pred != NULL)
        {
           while (save != NULL && save->info == pred->info)
        {
            printf("Repeated Node Data Is ::\n",pred->info);
        }
        pred=save;
        save=save->link;
        }
        
    }
    
    
}