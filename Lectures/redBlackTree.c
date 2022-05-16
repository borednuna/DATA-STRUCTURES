#include<stdio.h>
#include<stdlib.h>

struct rbtNode {
    int data;
    char color;
    struct rbtNode \
    *left, *right, *parent;
};

void LeftRotate(struct rbtNode **root, struct rbtNode *node) {
    if (!node || !node->right)
        return ;
    struct rbtNode *y = node->right;

    node->right = y->left;

    if (node->right != NULL)
        node->right->parent = node;

    y->parent = node->parent;

    if (node->parent == NULL)
        (*root) = y;

    else if (node == node->parent->left)
        node->parent->left = y;
    else    node->parent->right = y;

    y->left = node;

    node->parent = y;
}
 
void rightRotate(struct rbtNode **root,struct rbtNode *y) {
    if (!y || !y->left)
        return ;
    struct rbtNode *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent =y->parent;
    if (x->parent == NULL)
        (*root) = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}
 
void insertRecolor(struct rbtNode **root,struct rbtNode *z) {
    while (z != *root && z != (*root)->left && z != (*root)->right && z->parent->color == 'R')
    {
        struct rbtNode *y;

        if (z->parent && z->parent->parent && z->parent == z->parent->parent->left)
            y = z->parent->parent->right;
        else
            y = z->parent->parent->left;

        if (!y)
            z = z->parent->parent;
        else if (y->color == 'R')
        {
            y->color = 'B';
            z->parent->color = 'B';
            z->parent->parent->color = 'R';
            z = z->parent->parent;
        }

        else
        {
            if (z->parent == z->parent->parent->left &&
                z == z->parent->left)
            {
                char ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root, z->parent->parent);
            }

            if (z->parent && z->parent->parent && z->parent == z->parent->parent->left &&
                z == z->parent->right)
            {
                char ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent);
                rightRotate(root,z->parent->parent);
            }

            if (z->parent && z->parent->parent &&
                z->parent == z->parent->parent->right &&
                z == z->parent->right)
            {
                char ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent->parent);
            }

            if (z->parent && z->parent->parent && z->parent == z->parent->parent->right &&
                z == z->parent->left)
            {
                char ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent);
                LeftRotate(root,z->parent->parent);
            }
        }
    }
    (*root)->color = 'B';
}
 
void insert(struct rbtNode **root, int data) {
    struct rbtNode *z = (struct rbtNode*)malloc(sizeof(struct rbtNode));
    z->data = data;
    z->left = z->right = z->parent = NULL;

    if (*root == NULL)
    {
        z->color = 'B';
        (*root) = z;
    }
    else
    {
        struct rbtNode *y = NULL;
        struct rbtNode *node = (*root);

        while (node != NULL)
        {
            y = node;
            if (z->data < node->data)
                node = node->left;
            else
                node = node->right;
        }
        z->parent = y;
        if (z->data > y->data)
            y->right = z;
        else
            y->left = z;
        z->color = 'R';

        insertRecolor(root,z);
    }
    printf("Berhasil menambahkan data %d.\n", data);
}
 
void inorder(struct rbtNode *root) {
    int last = 0;
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d %s\n", root->data, (root->color == 'R' ? "Merah" : "Hitam"));
    inorder(root->right);
}

void findData(struct rbtNode *root, int data) {
    while (root != NULL) {
        if (data < root->data) {
            root = root->left;
        } else if (data > root->data) {
            root = root->right;
        } else {
            printf("Data %d ada dalam tree.\n", data);
            return;
        }
    }

    printf("Data %d tidak ditemukan dalam tree.\n", data);
}

struct rbtNode* minVal(struct rbtNode* node) {
    struct rbtNode* current = node;

    while (current && current->left != NULL)
        current = current->left;
    
    return current;
}

void removeData(struct rbtNode **root, int data) {
    if (*root == NULL) {
        printf("Tree kosong.\n");
    } else {
        struct rbtNode *node = (*root);

        while (node != NULL) {
            if (data < node->data) {
                node = node->left;
            } else if (data > node->data) {
                node = node->right;
            } else {
                if (node->left == NULL) {
                    struct rbtNode *rightChild = node->right;
                    
                    if (node->data > node->parent->data) {
                        node->parent->right = rightChild;
                        rightChild->parent = node->parent;
                    } else {
                        node->parent->left = rightChild;
                        rightChild->parent = node->parent;
                    }
                    free(node);
                    insertRecolor(root, rightChild);
                    printf("Berhasil menghapus data %d.\n", data);
                    return;
                } else if (node->right == NULL) {
                    struct rbtNode *leftChild = node->left;
                    if (node->data > node->parent->data) {
                        node->parent->right = leftChild;
                        leftChild->parent = node->parent;
                    } else {
                        node->parent->left = leftChild;
                        leftChild->parent = node->parent;
                    }
                    free(node);
                    insertRecolor(root, leftChild);
                    printf("Berhasil menghapus data %d.\n", data);
                    return;
                }
                
                struct rbtNode* temp = minVal(node->right);
                node->data = temp->data;
                node->color = temp->color;
                node->left = temp->left;
                node->right = temp->right;
                node->parent = node->parent;
                free(temp);
                insertRecolor(root, node);
                printf("Berhasil menghapus data %d.\n", data);
                return;
            }
        }

        printf("Data %d tidak ditemukan.\n", data);
    }
}

int main() {
    struct rbtNode *root = NULL;
    insert(&root,20);
    insert(&root,40);
    insert(&root,50);
    insert(&root,35);
    insert(&root,25);
    insert(&root,37);
    printf("inorder Traversal Is : \n");
    inorder(root);
    findData(root, 35);
    findData(root, 23);
    removeData(&root, 40);
}