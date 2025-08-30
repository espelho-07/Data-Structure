// Linear Search in C

#include <stdio.h>
int main()
{
    int noToSearch;
    int array[5] = {1, 2, 3, 5, 0};
    int found = 0;

    printf("Enter the Number you want to search--\n");
    scanf("%d", &noToSearch);

    for (int i = 0; i < 5; i++)
    {
        if (array[i] == noToSearch)
        {
            found = 1;
            printf("Element Found at index -- %d\n", i); 
            break;
        }
    }

    if (found != 1)
    {
        printf("Element Not Found\n");
    }

    return 0;
}
