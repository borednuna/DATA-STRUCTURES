#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int value;
    struct node *next;
};

struct arrayData {
    struct node *head;
    struct node *tail;
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
        array[i].tail = NULL;
    }
}

int findKey(struct node *list, int key) {
    int returnValue = 0;
    struct node *temp = list;
    while (temp != NULL) {
        if (temp->key == key) {
            return returnValue;
        }

        temp = temp->next;
        returnValue++;
    }
    return -1;
}

void insertData();
void rehash() {
    struct arrayData *temp = array;
    int n = max;
    size = 0;
    max = 2 * max;

    array = (struct arrayData*) malloc(max * sizeof(struct node));
    initArray();

    for (int i = 0; i < n; i++) {
        struct node* list = (struct node*) temp[i].head;

        if (list == NULL) {
            continue;
        } else {
            while(list != NULL) {
                insertData(list->key, list->value);
                list = list->next;
            }
        }
    }

    temp = NULL;
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
        array[index].tail = newItem;
        size++;
    } else {
        int findIndex = findKey(list, key);
        if (findIndex == -1) {
            array[index].tail->next = newItem;
            array[index].tail = newItem;
            size++;
        } else {
            struct node *element = getElement(list, findIndex);
            element->value = value;
        }
    }

    loadFactor = (1.0 * size) / max;
    if (loadFactor >= 0.75) {
        printf("Rehashing.\n\n");
        rehash();
    }
}

void removeData(int key) {
    int index = hashIndex(key);
    struct node *list = (struct node*) array[index].head;

    if (list == NULL) {
        printf("Key %d tidak ditemukan.\n\n", key);
    } else {
        int findInd = findKey(list, key);

        if (findInd == -1) {
            printf("Key %d tidak ditemukan.\n\n", key);
        } else {
            struct node *temp = list;

            if (temp->key == key) {
                printf("Key %d berhasil dihapus.\n\n", key);
                array[index].head = temp->next;
                return;
            }

            while (temp->next->key != key) {
                temp = temp->next;
            }

            if (array[index].tail == temp->next) {
                temp->next = NULL;
                array[index].tail = temp;
            } else {
                temp->next = temp->next->next;
            }

            printf("Key %d berhasil dihapus.\n\n", key);
        }
    }
}

void displayHashtable() {
    if (size == 0) {
        printf("Hash table kosong.\n");
        return;
    }

    for (int i = 0; i < max; i++) {
        struct node *temp = array[i].head;
        if (temp == NULL) {
            printf("Array index ke-%d tidak memiliki elemen.\n", i);
        } else {
            printf("Array index ke-%d memiliki elemen berikut :\n", i);
            while (temp != NULL) {
                printf("\tKey %d dengan value %d\n", temp->key, temp->value);
                temp = temp->next;
            }
        }
    }
    printf("\n");
}

int main() {
    array = (struct arrayData*) malloc (max * sizeof(struct arrayData));
    initArray();

    displayHashtable();
    insertData(3, 65);
    insertData(10, 77);
    insertData(5, 41);
    insertData(5, 55);
    displayHashtable();
    removeData(17);
    removeData(10);
    displayHashtable();
}