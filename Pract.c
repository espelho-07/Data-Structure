#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Find the minimum value node
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return root;
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search a node
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) return root;
    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Inorder Traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main menu-driven program
int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search a node\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* found = search(root, value);
                if (found)
                    printf("Node %d found in the BST.\n", value);
                else
                    printf("Node %d not found.\n", value);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into the binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// In-order traversal of the tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Compare two trees for equality
int areSame(struct Node* tree1, struct Node* tree2) {
    if (tree1 == NULL && tree2 == NULL) return 1;
    if (tree1 == NULL || tree2 == NULL) return 0;
    return (tree1->data == tree2->data) &&
           areSame(tree1->left, tree2->left) &&
           areSame(tree1->right, tree2->right);
}

int main() {
    // Tree 1
    struct Node* tree1 = NULL;
    tree1 = insert(tree1, 10);
    insert(tree1, 5);
    insert(tree1, 15);

    // Tree 2
    struct Node* tree2 = NULL;
    tree2 = insert(tree2, 10);
    insert(tree2, 5);
    insert(tree2, 15);

    // Print both trees
    printf("Tree 1 (In-order): ");
    inorder(tree1);
    printf("\n");

    printf("Tree 2 (In-order): ");
    inorder(tree2);
    printf("\n");

    // Compare trees
    if (areSame(tree1, tree2)) {
        printf("✅ The trees are the same.\n");
    } else {
        printf("❌ The trees are different.\n");
    }

    return 0;
}