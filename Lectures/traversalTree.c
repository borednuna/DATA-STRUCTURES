#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
    int data;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __initNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __initNode(value);

    if (value < root->data)
        root->left = __insert(root->left, value);
    else if (value > root->data)
        root->right = __insert(root->right, value);
    
    return root;
}

BSTNode* __search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->data);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->data);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->data);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __insert(bst->_root, value);
        bst->_size++;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}
 
int main()
{
    BST tree;
    bst_init(&tree);
    int buff;

    while (scanf("%d", &buff) != EOF) {
        bst_insert(&tree, buff);
    }

    printf("Inorder : ");
    bst_inorder(&tree);
    printf("\nPreorder : ");
    bst_preorder(&tree);
    printf("\nPostorder : ");
    bst_postorder(&tree);
}
