//WAP to find the largest among the given three numbers by user.

#include<stdio.h>
void main(){
    int num1;
    int num2;
    int num3;
    int largest;

    printf("Enter The First Number A\n");
    scanf("%d",&num1);

    printf("Enter The First Number B\n");
    scanf("%d",&num2);

    printf("Enter The First Number C\n");
    scanf("%d",&num3);

    largest = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);

    printf("The largest number is: %d\n", largest);

    return 0;
}