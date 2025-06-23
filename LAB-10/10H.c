struct node* save=first
while (save->link==NULL)
{
    printf("The Current Node Is %d::\n",save->info)
}


struct node* save=first
while (save!=NULL)
{
    count++;
    save=save->link;
}

printf("Count");
