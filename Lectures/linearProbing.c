#include <stdio.h>
#include <stdlib.h>

struct item {
    long long key;
    long long value;
};

struct hashTableItem {
    long long flag;
    struct item *data;
};

struct hashTableItem *array;
long long size = 0;
long long max = 7;

void initArray() {
    for (long long i=0; i < max; i++) {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}

long long getHashIndex(long long key) {
    return (key % max);
}

void insertItem(long long key, long long value) {
    long long index = getHashIndex(key);
    long long i = index;

    struct item* newItem = (struct item*) malloc(sizeof(struct item));
    newItem->key = key;
    newItem->value = value;

    while(array[i].flag == 1) {
        if (array[i].data->key == key) {
            array[i].data->value = value;
            printf("Data telah di-update.\n\n");
            return;
        }

        i = (i + 1) % max;
        if (i == index) {
            printf("Hash table penuh.\n\n");
            return;
        }
    }

    array[i].flag = 1;
    array[i].data = newItem;
    size++;
    printf("Key %d telah ditambahkan\n\n", key);
}

void removeItem(long long key) {
    long long index = getHashIndex(key);
    long long i = index;

    while (array[i].flag != 0) {
        if (array[i].flag == 1 && array[i].data->key) {
            array[i].flag = 2;
            array[i].data = NULL;
            size--;
            printf("Data key %d telah dihapus\n\n", key);
            return;
        }

        i = (i + 1) % max;
        if (i == index) {
            break;
        }
    }
    printf("Data key %d tidak ditemukan.\n\n", key);
}

void searchItem(long long key) {
    long long index = getHashIndex(key);
    long long i = index;

    while (array[i].flag != 0) {
        if (array[i].flag == 1 && array[i].data->key) {
            printf("Data key %d ada pada index %d\n\n", key, i);
            return;
        }

        i = (i + 1) % max;
        if (i == index) {
            break;
        }
    }
    printf("Data key %d tidak ditemukan.\n\n", key);
}

void displayHashTable() {
    if (size == 0) {
        printf("Hash Table kosong.\n");
    } else {
        for (long long i = 0; i < max; i++) {
            if (array[i].data == NULL) {
                printf("Indeks array ke-%d tidak memiliki item.\n", i);
            } else {
                printf("Indeks array ke-%d memiliki key %d dan value %d.\n", i, array[i].data->key, array[i].data->value);
            }
        }
    }
    printf("\n");
}

int main() {
    array = (struct hashTableItem*) malloc(max * sizeof(struct hashTableItem));
    initArray();
    insertItem(11051, 2002);
    displayHashTable();
    searchItem(11051);
    removeItem(11051);
    displayHashTable();
}
