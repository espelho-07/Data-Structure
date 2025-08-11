#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new Node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a Node in Tree
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        printf("Tree is empty or reached leaf. Inserting new Node...\n");
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Inorder Traversal in Tree
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main Method
int main()
{
    struct Node *root = NULL;
    int data;

    printf("Enter data to insert: ");
    scanf("%d", &data);
    root = insert(root, data);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}