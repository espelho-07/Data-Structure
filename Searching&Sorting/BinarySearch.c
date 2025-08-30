#include <stdio.h>
int main()
{
    int noToSearch;
    int array[6] = {1, 2, 3, 4, 5, 6};
    int left = 0;
    int right = 5;
    int middle;

    printf("Enter the Number you want to search--\n");
    scanf("%d", &noToSearch);

    while (left <= right)
    {
        middle = (left + right) / 2;

        if (array[middle] > noToSearch)
        {
            right = middle - 1;
        }
        else if (array[middle] < noToSearch)
        {
            left = middle + 1;
        }
        else
        {
            printf("Element Found at index %d\n", middle);
            return 0;  // exit program
        }
    }

    printf("Element Not Found\n");
    return 0;
}
