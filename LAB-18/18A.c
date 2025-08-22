#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to construct tree from preorder and postorder
struct Node *constructTree(int pre[], int post[], int postStart, int postEnd, int size, int preIndex)
{

    if (preIndex >= size || postStart > postEnd)
        return NULL;

 
    struct Node *root = createNode(pre[preIndex]);


    if (postStart == postEnd || preIndex == size - 1)
        return root;

    int i;
    for (i = postStart; i <= postEnd; i++)
    {
        if (post[i] == pre[preIndex + 1])
            break;
    }

    // Construct left and right subtrees Using Recursion
    if (i <= postEnd)
    {
        root->left = constructTree(pre, post, postStart, i, size, preIndex + 1);
        root->right = constructTree(pre, post, i + 1, postEnd - 1, size, preIndex + (i - postStart + 2));
    }

    return root;
}

// Print inorder traversal
void printInorder(struct Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// Main function
int main()
{
    int pre[] = {1, 2, 4, 5, 3, 6, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};
    int size = 7;

    struct Node *root = constructTree(pre, post, 0, size - 1, size, 0);

    printf("Inorder traversal of constructed tree:\n");
    printInorder(root);

    return 0;
}
