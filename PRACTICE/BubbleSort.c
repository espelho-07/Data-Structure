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
   

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[j] = arr[i];
            }
            
        }
        
    }
    

    return 0;
}
