#include <stdio.h>

int main()
{
    int size;
    int element;

    // Ask user for array size
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    // Input elements
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element you want to search: ");
    scanf("%d", &element);

    int found = 0; 

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("Element Found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Element Not Found\n");
    }

    return 0;
}
