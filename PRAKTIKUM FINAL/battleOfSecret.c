// This code passed the sample test case, but failed 1 test case

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int isNotSafe;

typedef struct bstnode_t {
    int key;
    int safe;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    newNode->safe = 1;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);

    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        if (root->safe) {
            printf("%d ", root->key);
            isNotSafe = 0;
        }
        __bst__inorder(root->right);
    }
}

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void markFormationLeft(BSTNode *root) {
    if (root) {
        root->safe = 0;
        markFormationLeft(root->left);
    }
}

void markFormationRight(BSTNode *root) {
    if (root) {
        root->safe = 0;
        markFormationRight(root->right);
    }
}

void markFormationLeaf(BSTNode *root) {
    if (root) {
        if (root->right == NULL && root->left == NULL) {
            root->safe = 0;
        }
        markFormationLeaf(root->left);
        markFormationLeaf(root->right);
    }
}

int main() {
    int nodes;
    isNotSafe = 1;

    BST formation;
    bst_init(&formation);

    scanf("%d", &nodes);

    for (int i = 0; i < nodes; i++) {
        int buff;
        scanf("%d", &buff);
        bst_insert(&formation, buff);
    }

    markFormationLeft(formation._root);
    markFormationRight(formation._root);
    markFormationLeaf(formation._root);
    bst_inorder(&formation);

    if (isNotSafe)
        printf("It's not safe\n");
}

// note: 1 means safe, 0 means not safe
