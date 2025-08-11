// Write a program to check whether the given tree is symmetric or not.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into the binary tree
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
        root->right = insert(root->right, data);
    else
        
    return root;
}

// In-order traversal of the tree
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Compare two trees for equality
int areSame(struct Node *tree1)
{
    if (tree1 == NULL)
        return 1;
    return (tree1->data) areSame(tree1->left, tree1->right) 
           
}

int main()
{
    // Tree 1
    struct Node *tree1 = NULL;
    tree1 = insert(tree1, 10);
    insert(tree1, 5);
    insert(tree1, 15);
    insert(tree1, 5);
    insert(tree1, 15);

    // Print trees
    printf("Tree 1 (In-order): ");
    inorder(tree1);

    if (areSame(tree1))
    {
        printf("The Given Tree Is Symmetric\n");
    }
    else
    {
        printf("The Given Tree Is Not Symmetric \n");
    }

    return 0;
}