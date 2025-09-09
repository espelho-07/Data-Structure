// Write a program to implement Selection Sort using Array.

#include <stdio.h>
int main()
{
    int N; // Size Of Array

    // Asking Size Of Array From User
    printf("Enter The Number Of elemnets You Want To Enter In A Array:-\n");
    scanf(" %d", &N);

    // Declaring Array
    int array[N];

    // Taking Array Elements Input From User
    for (int i = 0; i < N; i++)
    {
        printf("Enter %d Element Of Array:-\n", i + 1);
        scanf(" %d", &array[i]);
    }

    //Printing Original array
    printf("The Original Array You Entered Is:-\n");
    for (int i = 0; i < N; i++)
    {
        printf(" %d", array[i]);
    }
    
    int i = 1;
    int j;
    int key; //This The Is UnSorted Array Part
    

    // Insertion Sort Logic
    while (i < N)
    {
        key = array[i];
        j = i-1;
        while (j >= 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
        i = i+1;
    }
    

    //Printing Sorted Array
    printf("\nDo You Want To Print Sorted Array:-\n");
    printf("Enter 1 To Print-\n");
    int choice;
    scanf(" %d", &choice);
    if (choice == 1)
    {
        for (int i = 0; i < N; i++)
        {
            printf(" %d", array[i]);
        }
        
    }
}