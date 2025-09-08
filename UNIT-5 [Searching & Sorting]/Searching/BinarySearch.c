// Write a program to implement a Binary Search using Array. (Iterative &recursive) --- ITERATIVE APPROACH

#include <stdio.h>
int main()
{
    int ToSearch; // Element To Search
    int N;        // Size Of Array

    // Asking Size Of Array From User
    printf("--------- Please Enter An Sorted Array Only ----------\n");
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

    int left = 0;
    // Does First Element Is The One Which We Need To Find
    if (ToSearch == array[left])
    {
        printf("Element Found At Position %d And Index %d\n", left + 1, left);
    }

    int right = N - 1;
    // Does Last Element Is The One Which We Need To Find
    if (ToSearch == array[right])
    {
        printf("Element Found At Position %d And Index %d\n", right + 1, right);
    }

    int middle = ((left + right) / 2);
    int flag = 0;

    // Logic For Binary Search
    while (left <= right)
    {
        // If ToSearch Is Equal To Middle
        if (array[middle] == ToSearch)
        {
            printf("Element Found At Position %d And Index %d\n", middle + 1, middle);
            flag = 1;
            break;
        }
        // If Middle Is Larger Than ToSearch As Array Is Sorted It Will Search Middles's left Side
        else if (array[middle] > ToSearch)
        {
            right = middle - 1;
        }
        // If Middle Is Smaller Than ToSearch As Array Is Sorted It Will Search Middles's Right Side
        else if (array[middle] < ToSearch)
        {
            left = middle + 1;
        }
    }

    // If Element Not Found
    if (flag == 0)
    {
        printf("The Element You Want To find Is Not Present In The Array\n");
    }
}



--------------------------------------------------------------------------------------------------------------------------------------------------


// Write a program to implement a Binary Search using Array. (Iterative &recursive) --- FUNCTION APPROACH


---------------------------------------------------------------------------------------------------------------------------------------------------


// Write a program to implement a Binary Search using Array. (Iterative &recursive) --- RECURSIVE APPROACH
