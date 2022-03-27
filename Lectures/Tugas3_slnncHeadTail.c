// SLNNC - Single Linked List non Circular

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struktur Node
typedef struct snode_t {
    int data;
    struct snode_t *next;
} slnncNode;

// Struktur SLNNC
typedef struct slist_t {
    unsigned _size;
    slnncNode *_head;
    slnncNode *_tail;
} SLNNC;

// Initialize Linked List
void slnncInit(SLNNC *list) 
{
    list->_head = list->_tail = NULL;
    list->_size = 0;
}

// Check if linked list is empty
bool isEmpty(SLNNC *list) {
    return (list->_tail == NULL || list->_head == NULL);
}

// Add data in front
void insertFront(SLNNC *list, int value) 
{
    slnncNode *newNode = (slnncNode*) malloc(sizeof(slnncNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            list->_tail->next = NULL;
        } else {
            newNode->next = list->_head;
            list->_head = newNode;
        }
    }
}

// Add data in back
void insertBack(SLNNC *list, int value)
{
    slnncNode *newNode = (slnncNode*) malloc(sizeof(slnncNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            list->_tail->next = NULL;
        } else {
            list->_tail->next = newNode;
            list->_tail = newNode;
            // slnncNode *temp = list->_head;
            // while (temp->next != NULL) 
            //     temp = temp->next;
            // temp->next = newNode;
        }
    }
}

// Add data among nodes with index
void insertAt(SLNNC *list, int index, int value)
{
    if (isEmpty(list) || index >= list->_size) {
        insertBack(list, value);
        return;    
    }
    else if (index == 0) {
        insertFront(list, value);
        return;
    }
    
    slnncNode *newNode = (slnncNode*) malloc(sizeof(slnncNode));
    if (newNode) {
        slnncNode *temp = list->_head;
        int _i = 0;
        
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

// Display data in front
int slnncFront(SLNNC *list)
{
    if (!isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

// Display data in back
int slnncBack(SLNNC *list)
{
    if (!isEmpty(list)) {
        return list->_tail->data;
    }
    return 0;
}

// Display data in certain index
int getAt(SLNNC *list, int index)
{
    if (!isEmpty(list)) {
        slnncNode *temp = list->_head;
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
void displayAll(SLNNC *list)
{
    if (!isEmpty(&list)) {
        slnncNode *temp = list->_head;
        printf("Isi SLNNC : ");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    } else {
        printf("SLNNC kosong\n\n");
    }
}

// Remove data at back
void removeBack(SLNNC *list)
{
    if (!isEmpty(list)) {
        slnncNode *nextNode = list->_head->next;
        slnncNode *currNode = list->_head;

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
        list->_tail = currNode;
        free(nextNode);
        list->_size--;
    }
}

// Remove data at front
void removeFront(SLNNC *list)
{
    if (!isEmpty(list)) {
        slnncNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

// Clear data
void clearSlnnc(SLNNC *list)
{
    if (!isEmpty(&list)) {
        while(list->_head != NULL) {
            slnncNode *temp = list->_head;
            list->_head = list->_head->next;
            free(temp);
            list->_size--;
        }
    }
}

// Main program
int main() {
    SLNNC slnncExample;
    slnncInit(&slnncExample);
    
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
    printf("Index 0 : %d\n\n", slnncFront(&slnncExample));
    printf("Index akhir : %d\n\n", slnncBack(&slnncExample));
    printf("Index 1 : %d\n\n", getAt(&slnncExample, 1));

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
