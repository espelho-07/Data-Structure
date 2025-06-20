//WAP to find whether a number is odd or even.

#include<stdio.h>
void main(){
    int Num;
    
    printf("Enter The Number You want To Check\n");
    scanf("%d",&Num);

    if (Num%2==0)
    {
        printf("The Entered Number Is EVEN\n");
    }else
    {
        printf("The Entered Number Is ODD\n");
    }
    
    return 0;
}