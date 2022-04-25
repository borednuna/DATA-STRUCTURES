#include <stdio.h>
#include <stdlib.h>

struct AVLNode {
    int data;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
};

int getHeight(struct AVLNode *node) {
    if (node == NULL)
        return 0;

    return node->height;
}

int getMax(int a, int b) {
    return (a > b) ? a : b;
}

struct AVLNode *rotateRight(struct AVLNode *y) {
    struct AVLNode *x = y->left;
    struct AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;
    y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

struct AVLNode *rotateLeft(struct AVLNode *x) {
    struct AVLNode *y = x->right;
    struct AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;
    x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

int getBalance(struct AVLNode *node) {
    if (node == NULL)
        return 0;
    
    return getHeight(node->left) - getHeight(node->right);
}

struct AVLNode* newNode(int data) {
    struct AVLNode* node = (struct AVLNode*) malloc(sizeof(struct AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct AVLNode* insertData(struct AVLNode *node, int data) {
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insertData(node->left, data);
    else if (data > node->data)
        node->right = insertData(node->right, data);
    else
        return node;

    node->height = 1 + getMax(getHeight(node->left), getHeight(node->right));
    
    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data)
        return rotateRight(node);
    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);
    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

struct AVLNode * minValueNode(struct AVLNode* node) {
    struct AVLNode* current = node;
    while (current->left != NULL)
    current = current->left;
    return current;
}

void findNode(struct AVLNode* node, int data) {
    if (node == NULL) {
        printf("Data %d tidak ada dalam tree.\n", data);
        return;
    }

    if (data < node->data) {
        findNode(node->left, data);
    } else if (data > node->data) {
        findNode(node->right, data);
    } else {
        printf("Data %d ada dalam tree.\n", data);
    }
}

struct AVLNode* removeNode(struct AVLNode* node, int data) {
    if (node == NULL)
        return node;
    if (data < node->data) {
        node->left = removeNode(node->left, data);
    } else if (data > node->data) {
        node->right = removeNode(node->right, data);
    } else {
        if ((node->left == NULL) || (node->right == NULL)) {
            struct AVLNode *temp = node->left ? node->left : node->right;

            if (temp == NULL) {
                temp = node;
                node = NULL;
            } else {
                *node = *temp;
                free(temp);
            }
        } else {
            struct AVLNode *temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }
    }

    if (node == NULL)
        return node;
    node->height = 1 + getMax(getHeight(node->left), getHeight(node->right));


    int balance = getBalance(node);
    if (balance > 1 && getBalance(node->left) >= 0)
        return rotateRight(node);
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0)
        return rotateLeft(node);
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right - rotateRight(node->right);
        return rotateLeft(node);
    }
    
    return node;
}

void preOrder(struct AVLNode *node) {
    if(node != NULL) {
        printf("%d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

int main() {
    struct AVLNode *node = NULL;
    node = insertData(node, 27);
    node = insertData(node, 9);
    node = insertData(node, 19);
    node = insertData(node, 91);
    node = insertData(node, 90);
    node = insertData(node, 72);
    printf("AVL tree node dengan urutan preorder : \n");
    preOrder(node);
    printf("\n");

    findNode(node, 90);
    findNode(node, 2);

    node = removeNode(node, 9);
    node = removeNode(node, 72);
    printf("AVL tree node dengan urutan preorder setelah penghapusan: \n");
    preOrder(node);
    printf("\n");
}
