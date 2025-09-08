// Write a program to implement a Linear Search using Array.Write a program to implement a Linear Search using Array. ---SIMPLE ITERATIVE APPROACH

#include <stdio.h>
int main()
{
    int ToSearch; // Element To Search
    int N;        // Size Of Array

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

    // Asking Element From User Which He Want To Search
    printf("Enter The Element You Want To Search:-\n");
    scanf(" %d", &ToSearch);

    // Declaring Flag As 0
    int flag = 0;

    // Logic For Searching An Elements In array
    for (int i = 0; i < N; i++)
    {
        // If Element Found In Array
        if (array[i] == ToSearch)
        {
            printf("Element Found At Position %d And Index %d\n", i + 1, i);
            flag = 1;
            break;
        }
    }

    // If elements Not Found In array
    if (flag == 0)
    {
        printf("The Element You Want To find Is Not Present In The Array\n");
    }
}



-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



// Write a program to implement a Linear Search using Array.Write a program to implement a Linear Search using Array Using Making Function. ---FUNCTION ITERATIVE APPROACH

int *createArray(int N)
{
    int *array;
    for (int i = 0; i < N; i++)
    {
        printf("Enter %dst Element Of Array:-\n", i + 1);
        scanf(" %d", &array[i]);
    }
}

int linearSearch(int ToSearch)
{
    createArray(N);
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        if (array[i] == ToSearch)
        {
            printf("Element Found At Position %d And Index %d\n", i + 1, i);
            flag = 1;
            break;
        }

        if (flag == 0)
        {
            printf("The Element You Want To find Is Not Present In The Array\n");
        }
    }
}
