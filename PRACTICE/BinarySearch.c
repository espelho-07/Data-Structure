#include <stdio.h>

int main() {
    int size, element;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d integers in sorted order:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element you want to search: ");
    scanf("%d", &element);

    int low = 0, high = size - 1, found = 0;

    while (low <= high) {
        int middle = (low + high) / 2;

        if (arr[middle] == element) {
            printf("Element Found at position %d\n", middle + 1);
            found = 1;
            break;
        } else if (arr[middle] > element) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }

    if (!found) {
        printf("Element Not Found\n");
    }

    return 0;
}


// if recursive function

// int binarySearch(int arr[], int low, int high, int element) {
//     if (low > high) return -1; // not found

//     int middle = (low + high) / 2;

//     if (arr[middle] == element)
//         return middle; // found
//     else if (arr[middle] > element)
//         return binarySearch(arr, low, middle - 1, element);
//     else
//         return binarySearch(arr, middle + 1, high, element);
// }
