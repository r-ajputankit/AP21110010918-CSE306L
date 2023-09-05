#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    char key[50];
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createTreeNode(const char* key, int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode != NULL) {
        strncpy(newNode->key, key, sizeof(newNode->key));
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

struct TreeNode* insert(struct TreeNode* current, const char* key, int value) {
    if (current == NULL) {
        return createTreeNode(key, value);
    }
    int compareResult = strcmp(key, current->key);
    if (compareResult < 0) {
        current->left = insert(current->left, key, value);
    } else if (compareResult > 0) {
        current->right = insert(current->right, key, value);
    }
    return current;
}

int search(struct TreeNode* current, const char* key) {
    if (current == NULL || strcmp(key, current->key) == 0) {
        return (current != NULL) ? current->value : -1;   
    }
    int compareResult = strcmp(key, current->key);
    if (compareResult < 0) {
        return search(current->left, key);
    }
    return search(current->right, key);
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, "variable1", 42);

    int result = search(root, "variable1");
    if (result != -1) {
        printf("Value found: %d\n", result);
    } else {
        printf("Key not found\n");
    }
    return 0;
}
