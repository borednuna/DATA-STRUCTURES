#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int bstLevel[100];
int isNotSafe;

typedef struct bstnode_t {
    int key;
    int floorIndex;
    int depth;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value, int depth) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    newNode->depth = depth;
    bstLevel[depth]++;
    newNode->floorIndex = bstLevel[depth];
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int depth) {
    depth = depth + 1;
    if (root == NULL) 
        return __bst__createNode(value, depth);

    if (value < root->key) {
        root->left = __bst__insert(root->left, value, depth);
    } else if (value > root->key) {
        root->right = __bst__insert(root->right, value, depth);
    }

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

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        if ((root->depth != 1) && (root->floorIndex != 1) && (root->floorIndex < bstLevel[root->depth]) &&
            ((root->left != NULL) || (root->right !=NULL))) {
            printf("%d ", root->key);
            isNotSafe = 0;
        }
        __bst__inorder(root->right);
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
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value, int depth) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, depth);
        bst->_size++;
    }
}

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

int main() {
    isNotSafe = 1;
    for (int i = 0; i < 100; i++) {
        bstLevel[i] = 0;
    }

    BST formation;
    bst_init(&formation);
    int order, buff, depth = 0;

    scanf("%d", &order);

    for (int i = 0; i < order; i++) {
        scanf("%d", &buff);
        bst_insert(&formation, buff, depth);
    }

    bst_inorder(&formation);

    if (isNotSafe)
        printf("It's not safe\n");
}
