#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Struktur ADT DynamicArray

typedef struct dynamicarr_t {
    char **_arr;
    unsigned _size, _capacity;
} DynamicArray;

// Prototipe fungsi

// void darray_init(DynamicArray *darray);
// bool darray_isEmpty(DynamicArray *darray);
// void darray_pushBack(DynamicArray *darray, char *value);
// void darray_popBack(DynamicArray *darray);
// char *darray_back(DynamicArray *darray);
// char *darray_front(DynamicArray *darray);
// void darray_setAt(DynamicArray *darray, unsigned index, char *value);
// char *darray_getAt(DynamicArray *darray, unsigned index);
// void darray_insertAt(DynamicArray *darray, unsigned index, char *value);
// void darray_removeAt(DynamicArray *darray, unsigned index);

// Definisi fungsi

void darray_init(DynamicArray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (char **) malloc(sizeof(char*) * 2);
    for (int i = 0; i < 100; i++)
    darray->_arr[i] = (char *) malloc(sizeof(char) * (100+1));
}

bool darray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, char* value)
{
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        char **newArr = (char**) malloc(sizeof(char*) * darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            strcpy(newArr[it], darray->_arr[it]);
        
        char **oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    strcpy(darray->_arr[darray->_size++], value);
    darray->_capacity += 1;
}

void darray_popBack(DynamicArray *darray) {
    if (!darray_isEmpty(darray)) darray->_size--;
    else return;
}

char *darray_back(DynamicArray *darray) {
    if (!darray_isEmpty(darray))
        return darray->_arr[darray->_size-1];
    else return 0;
}

char *darray_front(DynamicArray *darray) {
    if (!darray_isEmpty(darray))
        return darray->_arr[0];
    else return 0;
}

void darray_setAt(DynamicArray *darray, unsigned index, char * value){
    if (!darray_isEmpty(darray)) {
        if (index >= darray->_size)
            strcpy(darray->_arr[darray->_size-1], value);
        else
            strcpy(darray->_arr[index], value);
    }
}

char *darray_getAt(DynamicArray *darray, unsigned index){
    if (!darray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_arr[darray->_size-1];
        else
            return darray->_arr[index];
    }
}

/* Gunakan ini untuk mempersingkat penulisan kode */

// #define d_init darray_init
// #define d_isEmpty darray_isEmpty
// #define d_pushBack darray_pushBack
// #define d_popBack darray_popBack
// #define d_back darray_back
// #define d_front darray_front
// #define d_setAt darray_setAt
// #define d_getAt darray_getAt

// /* */

// int main(int argc, char const *argv[])
// {
//     // Buat objek DynamicArray
//     DynamicArray myArray;

//     // PENTING! Jangan lupa diinisialisasi
//     darray_init(&myArray);

//     // Operasi-operasi
//     // myArray => [11, 14, 17, 23]
//     darray_pushBack(&myArray, "Selamat Datang di Strukdat.");
//     darray_pushBack(&myArray, "Semoga harimu menyenangkan!");
//     int i = 0;
//     for (; i < myArray._size; ++i) {
//         printf("%s ", darray_getAt(&myArray, i));
//     }

//     printf("\n");

//     printf("%s\n", darray_front(&myArray));

//     while (!darray_isEmpty(&myArray)) {
//         printf("%s ", darray_back(&myArray));
//         darray_popBack(&myArray);
//     }
//     printf("\n");

//     return 0;
// }