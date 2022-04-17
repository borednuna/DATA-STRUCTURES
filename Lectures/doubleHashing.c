#include <stdio.h>
#include <stdlib.h>

struct data {
    int key;
    int value;
};

struct hashTable {
    int flag;
    struct data *item;
};

struct hashTable *array;
int max = 7;
int size = 0;
int constant = 3;

void initArray() {
    for (int i=0; i < max; i++) {
        array[i].item = NULL;
        array[i].flag = 0;
    }
}

int hashIndex1(int key) {
    return (key % max);
}

int hashIndex2(int key) {
    return (constant - (key % constant));
}

void insertData(int key, int value) {
    int hashInd1 = hashIndex1(key);
    int hashInd2 = hashIndex2(key);
    int index = hashInd1;

    struct data *newItem = (struct data*) malloc(sizeof(struct data));
    newItem->key = key;
    newItem->value = value;

    if (size == max) {
        printf("Hashtable penuh.\n\n");
        return;
    }

    while (array[index].flag == 1) {
        if (array[index].item->key == key) {
            array[index].item->value = value;
            printf("Memperbarui data key %d.\n\n", key);
            return;
        }

        index = (index + hashInd2) % max;
        if (index == hashInd1) {
            printf("Penambahan data gagal.\n\n");
            return;
        }
    }

    array[index].item = newItem;
    array[index].flag = 1;
    size++;
    printf("Data %d pada key %d berhasil ditambahkan.\n\n", value, key);
}

void removeData(int key) {
    int hashInd1 = hashIndex1(key);
    int hashInd2 = hashIndex2(key);
    int index = hashInd1;

    if (size == 0) {
        printf("Hash table kosong.\n\n");
        return;
    }

    while (array[index].flag != 0) {
        if (array[index].flag == 1 && array[index].item->key == key) {
            array[index].item = NULL;
            array[index].flag = 2;
            size--;
            printf("Key %d berhasil dihapus.\n\n", key);
            return;
        }

        index = (index + hashInd2) % max;
        if (index == hashInd1) {
            break;
        }
    }
    
    printf("Key %d tidak ditemukan.\n\n", key);
}

void displayHashtable() {
    if (size == 0) {
        printf("Hash table kosong.\n\n");
        return;
    }

    for (int i=0; i < max; i++) {
        if (array[i].flag != 1) {
            printf("Array[%d] tidak memiliki data.\n", i);
        } else {
            printf("Array[%d] memiliki key %d dan value %d.\n", i, array[i].item->key, array[i].item->value);
        }
    }
    printf("\n");
}

void findKey(int key) {
    int hashInd1 = hashIndex1(key);
    int hashInd2 = hashIndex2(key);
    int index = hashInd1;

    if (size == 0) {
        printf("Hash table kosong.\n\n");
        return;
    }

    while (array[index].flag != 0) {
        if (array[index].flag == 1 && array[index].item->key == key) {
            printf("Key %d ditemukan di index %d.\n\n", key, index);
            return;
        }

        index = (index + hashInd2) % max;
        if (index == hashInd1) {
            break;
        }
    }
    
    printf("Key %d tidak ditemukan.\n\n", key);
}

int main() {
    array = (struct hashTable*) malloc(max * sizeof(struct hashTable));
    initArray();

    displayHashtable();
    insertData(3, 76);
    insertData(10, 54);
    insertData(3, 10);
    displayHashtable();
    findKey(10);
    findKey(1);
    removeData(1);
    removeData(3);
    displayHashtable();
}