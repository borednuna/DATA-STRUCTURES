#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int value;
    struct node *next;
};

struct arrayData {
    struct node *head;
};

struct arrayData *array;
int size = 0;
int max = 7;

int hashIndex(int key) {
    return (key % max);
}



struct node* getElement(struct node *list, int findIndex) {
    int i = 0;
    struct node *temp = list;

    while (i != findIndex) {
        temp = temp->next;
        i++;
    }
    return temp;
}

void initArray() {
    for (int i=0; i < max; i++) {
        array[i].head = NULL;
    }
}

int find(struct node *list, int key) {
    int returnValue = 0;
}

void insertData (int key, int value) {
    float loadFactor = 0.0;

    int index = hashIndex(key);

    struct node *list = (struct node*) array[index].head;
    struct node *newItem = (struct node*) malloc(sizeof(struct node));
    newItem->key = key;
    newItem->value = value;
    newItem->next = NULL;

    if (list == NULL) {
        printf("Data key %d berhasil ditambahkan.\n\n", key);
        array[index].head = newItem;
        size++;
    } else {
        
    }
}