//WAP to determine whether the entered character is vowel or not. 

#include<stdio.h>
void main(){
    char c;

    printf("Enter The Character\n");
    scanf("%c", &c);

    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
    {
        printf("The Entered Character Is VOWEL\n");
    }
    else
    {
        printf("The Entered Character Is NOT VOWEL\n");
    }
    
    return 0;
}