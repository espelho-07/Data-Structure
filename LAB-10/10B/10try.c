int choice , data , position;
while (1)
{
    printf("Enter 1 for Insert At Null");
    scanf("%d",&choice);
    printf("Enter 2 for Insert At Null");
    scanf("%d",&choice);
    printf("Enter 3 for Insert At Null");
    scanf("%d",&choice);
    printf("Enter 4 for Insert At Null");
    scanf("%d",&choice);
    printf("Enter 5 for Insert At Null");
    scanf("%d",&choice);
    printf("Enter 6 for Insert At Null");
    scanf("%d",&choice);
    printf("Enter 7 for Insert At Null");
    scanf("%d",&choice);
    printf("Enter 8 for Insert At Null");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter The Element U Want to Insert");
        scanf("%d",&data);
        first = insertAtFront(data);
        break;
    
    default:
        break;
    }
}
