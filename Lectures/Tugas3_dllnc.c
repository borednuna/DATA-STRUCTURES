// DLLNC - Doubly Linked List Non Circular

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struktur Node
typedef struct snode_t {
    int data;
    struct snode_t *next;
    struct snode_t *prev;
} dlnncNode;

// Struktur DLNNC
typedef struct slist_t {
    unsigned _size;
    dlnncNode *_head;
} DLNNC;

// Initialize Linked List
void dlnncInit(DLNNC *list) 
{
    list->_head = NULL;
    list->_size = 0;
}

// Check if linked list is empty
bool isEmpty(DLNNC *list) {
    return (list->_head == NULL);
}

// Add data in front
void insertFront(DLNNC *list, int value) 
{
    dlnncNode *newNode = (dlnncNode*) malloc(sizeof(dlnncNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty(list)) {
            list->_head = newNode;
            return;
        } else {
            list->_head->prev = newNode;
            newNode->next = list->_head;
            list->_head = newNode;
        }
    }
}

// Add data in back
void insertBack(DLNNC *list, int value)
{
    dlnncNode *newNode = (dlnncNode*) malloc(sizeof(dlnncNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (isEmpty(list)) 
            list->_head = newNode;
        else {
            dlnncNode *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

// Add data among nodes with index
void insertAt(DLNNC *list, int index, int value)
{
    if (isEmpty(list) || index >= list->_size) {
        insertBack(list, value);
        return;    
    }
    else if (index == 0) {
        insertFront(list, value);
        return;
    }
    
    dlnncNode *newNode = (dlnncNode*) malloc(sizeof(dlnncNode));
    if (newNode) {
        dlnncNode *temp = list->_head;
        newNode->data = value;
        int _i = 0;
        
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }

        newNode->next = temp->next;
        temp->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
        list->_size++;
    }
}

// Display data in front
int dlnncFront(DLNNC *list)
{
    if (!isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

// Display data in back
int dlnncBack(DLNNC *list)
{
    if (!isEmpty(list)) {
        dlnncNode *temp = list->_head;
        while (temp->next != NULL) 
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

// Display data in certain index
int getAt(DLNNC *list, int index)
{
    if (!isEmpty(list)) {
        dlnncNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index) {
            temp = temp->next;
            _i++;
        }
        return temp->data;
    }
    return 0;
}

// Display all data
void displayAll(DLNNC *list)
{
    if (!isEmpty(&list)) {
        dlnncNode *temp = list->_head;
        printf("Isi SLNNC : ");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    } else {
        printf("DLNNC kosong\n\n");
    }
}

// Remove data at back
void removeBack(DLNNC *list)
{
    if (!isEmpty(list)) {
        dlnncNode *nextNode = list->_head->next;
        dlnncNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

// Remove data at front
void removeFront(DLNNC *list)
{
    if (!isEmpty(list)) {
        dlnncNode *temp = list->_head;
        list->_head = list->_head->next;
        list->_head->prev = NULL;
        free(temp);
        list->_size--;
    }
}

// Clear data
void clearSlnnc(DLNNC *list)
{
    if (!isEmpty(&list)) {
        while(list->_head != NULL) {
            dlnncNode *temp = list->_head;
            list->_head = list->_head->next;
            free(temp);
            list->_size--;
        }
    }
}

// Search data
void searchData(DLNNC *list, int value)
{
    if (!isEmpty(&list)) {
        dlnncNode *temp = list->_head;
        while(temp != NULL) {
            if (temp->data == value) {
                printf("Data %d ada dalam SLLNC\n\n", value);
                return;
            }
            temp = temp->next;
        }
    }

    printf("Data %d tidak ada\n\n", value);
}

// Main program
int main() {
    DLNNC slnncExample;
    dlnncInit(&slnncExample);
    
    // Tambahkan data awal
    insertFront(&slnncExample, 18);
    insertFront(&slnncExample, 19);
    insertFront(&slnncExample, 20);
    displayAll(&slnncExample);

    // Tambahkan data di depan
    insertFront(&slnncExample, 12);
    displayAll(&slnncExample);

    // Tambahkan data di belakang
    insertBack(&slnncExample, 313);
    displayAll(&slnncExample);

    // Tambahkan data di index tertentu
    insertAt(&slnncExample, 2, 42);
    displayAll(&slnncExample);

    // Display data di awal, akhir, dan index tertentu
    printf("Index 0 : %d\n\n", dlnncFront(&slnncExample));
    printf("Index akhir : %d\n\n", dlnncBack(&slnncExample));
    printf("Index 1 : %d\n\n", getAt(&slnncExample, 1));

    // Cari data
    searchData(&slnncExample, 12);
    searchData(&slnncExample, 9);

    // Hapus data di belakang
    removeBack(&slnncExample);
    displayAll(&slnncExample);

    // Hapus data di depan
    removeFront(&slnncExample);
    displayAll(&slnncExample);

    // Hapus semua data
    clearSlnnc(&slnncExample);
    printf("Size : %d\n\n", slnncExample._size);
    displayAll(&slnncExample);
}
