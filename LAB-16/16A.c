/*Write a menu driven program to implement Binary Search Tree (BST) & perform
following operations:
• Insert a Node
• Delete a Node
• Search a Node
• Preorder Traversal
• Postorder Traversal
• Inorder Traversal */

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

// Preorder Traversal in Tree
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal in Tree
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Searching in a tree
struct Node* searchInTree(struct Node* root, int data) {
    if (root == NULL || root->data == data) return root;
    if (data < root->data)
        return searchInTree(root->left, data);
    else
        return searchInTree(root->right, data);
}

//Deletion in Tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
    }
    return root;
}

// Main Method
int main()
{
    struct Node *root = NULL;
    int choice, data;

    // Menu Driven Program
    do
    {
        printf("\n:) Binary Search Tree Menu (:\n");
        printf("1. Insert a Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search Element\n");
        printf("6. Delete Element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter data to search: ");
            scanf("%d", &data);
            struct Node *found = searchInTree(root, data);
            if (found)
                printf("Node %d found in the BST.\n", data);
            else
                printf("Node %d not found.\n", data);
            break;
        case 6:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;
        case 7:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}