#include <stdio.h>
int main()
{

    int array[6] = {1, 4, 9, 3, 12, 6};

    for (int i = 0; i < 5; i++)
    {
        int element = i;
        int j = i + 1;

        if (array[j] > array[element])
        {
            element = j;
        }

        int temp = array[i];
        array[i] = array[element];
        array[element] = temp;

        printf("Sorted Array: ");
        for (int i = 0; i < 6; i++)
        {
            printf("%d ", array[i]);
        }
        return 0;
    }
}
