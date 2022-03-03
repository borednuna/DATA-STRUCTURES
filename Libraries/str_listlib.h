/**
 * Implementasi ADT SInglyList (Singly Linked List)
 *
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 *
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struktur Node */

typedef struct snode_t {
    char data[101];
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* DAFTAR FUNGSI YANG TERSEDIA */

// void slist_init(SinglyList *list);
// bool slist_isEmpty(SinglyList *list);
// void slist_pushFront(SinglyList *list, char *value);
// void slist_popFront(SinglyList *list);
// void slist_pushBack(SinglyList *list, char *value);
// void slist_popBack(SinglyList *list);
// char *slist_front(SinglyList *list);
// char *slist_back(SinglyList *list);

/* Function definition below */

void slist_init(SinglyList *list) {
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, char *value) {
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        strcpy(newNode->data, value);//== +strcpy

        if (slist_isEmpty(list))
            newNode->next = NULL;
        else
            newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list) {
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, char *value) {//=
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        strcpy(newNode->data, value);//==+strcpy
        newNode->next = NULL;//= char=NULL ,int=0

        if (slist_isEmpty(list))
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

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

char *slist_front(SinglyList *list) {
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

char *slist_back(SinglyList *list) {
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL)
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

// int main(int argc, char const *argv[]) {
//     SinglyList myList;
//     slist_init(&myList);

//     char newString[100];
//     scanf("%s", newString);

//     slist_pushFront(&myList, "| Modul 0 |");
//     slist_pushFront(&myList, "| Strukdat |");
//     slist_pushBack(&myList, "| List |");
//     slist_pushFront(&myList, newString);

//     printf("String di front: %s\n", slist_front(&myList));
//     printf("String di belakang: %s\n", slist_back(&myList));

//     while (!slist_isEmpty(&myList)) {
//         printf("%s ", slist_back(&myList));
//         slist_popBack(&myList);
//     }

//     return 0;
// }