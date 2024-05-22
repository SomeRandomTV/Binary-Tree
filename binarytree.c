#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treenode {
    int data;
    struct treenode *left;
    struct treenode *right;
} node;

node *getNewNode(int x) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


void inorderLeafNodes(node* root, int* leafValues, int* index) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            leafValues[(*index)++] = root->data;
        }
        inorderLeafNodes(root->left, leafValues, index);
        inorderLeafNodes(root->right, leafValues, index);
}


bool leafSimilar(node* root1, node* root2) {
    
    int leafValues1[100] = {};
    int leafValues2[100] = {};
    int index1 = 0, index2 = 0;

    
    inorderLeafNodes(root1, leafValues1, &index1);
    inorderLeafNodes(root2, leafValues2, &index2);

    if (index1 != index2)
        return false;
    for (int i = 0; i < index1; i++) {
        if (leafValues1[i] != leafValues2[i])
            return false;
    }
    return true;
}



int main() {

    node *root = getNewNode(3);
    root->left = getNewNode(5);
    root->left->left = getNewNode(6);          // leaf
    root->left->right = getNewNode(2);
    root->left->right->left = getNewNode(7);   // leaf
    root->left->right->right = getNewNode(4);  // leaf

    root->right = getNewNode(1);
    root->right->left = getNewNode(9);         // leaf
    root->right->right = getNewNode(8);        // leaf

    node* root2 = getNewNode(3);
    root2 = getNewNode(3);
    root2->left = getNewNode(5);
    root2->left->left = getNewNode(6);
    root2->left->right = getNewNode(7);
    root2->right = getNewNode(1);
    root2->right->left = getNewNode(4);
    root2->right->right = getNewNode(2);
    root2->right->right->right = getNewNode(8);
    root2->right->right->left = getNewNode(9);


    if (leafSimilar(root, root2)) {
        printf("They are root similar\n");
    } else {
        printf("They are not root similar\n");
    }
    
    findMin(root);
    return 0;
}