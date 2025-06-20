//WAP to calculate area of a Circle (A = πr2). 

#include<stdio.h>

void main(){
    float radius;
    float area;
    float PI=3.14;

    printf("Enter The Radius Of Circle\n");
    scanf("%f",&radius);

    area = PI * radius * radius;

    printf("The area of the circle is: %.2f\n", area);

    return 0;

}