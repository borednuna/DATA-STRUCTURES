// 5025211051 - Hanun Shaka P (borednuna)

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int indx;
int array[100];

typedef struct bstnode_t {
    int key;
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

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

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

void __bstInd(BSTNode *root, int val) {
    if (root) {
        __bstInd(root->left, val);
        array[indx++] = root->key;
        __bstInd(root->right, val);
    }
}

void bstInd(BST *bst, int val) {
    __bstInd(bst->_root, val);
}

int predecessorValue(BSTNode *root, int value) {
    int pre = 0;
    while (root != NULL) {
        if (value < root->key) {
            pre = root->key;
            root = root->left;
        } else if (value > root->key) {
            pre = root->key;
            root = root->right;
        } else {
            return pre;
        }
    }
    return 0;
}

int bst_predecessor(BST *bst, int value) {
    int temp = predecessorValue(bst->_root, value);
    return temp;
}

int main() {
    BST tree;
    bst_init(&tree);

    int query, value;
    char order[20];
    scanf("%d", &query);

    for (int i=0; i < query; i++) {
        indx = 1;
        scanf("%s %d", order, &value);
        if (strcmp(order, "masukin") == 0) {
            bst_insert(&tree, value);
        } else if (strcmp(order, "anaksiapa") == 0) {
            if (bst_predecessor(&tree, value) == 0)
                printf("ini anak siapa dah\n");
            else
                printf("%d\n", bst_predecessor(&tree, value));
        } else {
            bstInd(&tree, value);
            for (int i=1; i < indx; i++) {
                if (array[i] == value)
                    printf("%d\n", i);
            }
        }
    }
}
