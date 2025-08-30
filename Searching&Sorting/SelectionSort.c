#include <stdio.h>
int main()
{

    int array[6] = {1, 4, 9, 3, 12, 6};

    for (int i = 0; i < 5; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < 6; j++)
        {
            if (array[j] < array[smallest])
            {
                smallest = j;
            }
        }
        int temp = array[i];
        array[i] = array[smallest];
        array[smallest] = temp;
    }
    printf("Sorted Array: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
