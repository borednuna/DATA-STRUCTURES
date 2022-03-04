#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Libraries/str_arrlib.h"

int main() {
    DynamicArray myArray;
    darray_init(&myArray);

    // printf("%s\n", darray_back(&myArray));

    dArray_pushBack(&myArray, "TEST");
    dArray_pushBack(&myArray, "CASE");
    dArray_pushBack(&myArray, "STRUKTUR DATA");
    dArray_pushBack(&myArray, "DATA");

    printf("\n");
    for (int i=0; i < myArray._size; i++) {
        printf("%s ", myArray._arr[i]);
    }
    printf("\n");

    darray_setAt(&myArray, 1, "NUNA");
     printf("\n");
    for (int i=0; i < myArray._size; i++) {
        printf("%s ", myArray._arr[i]);
    }
    printf("\n");

    printf("%s\n", darray_getAt(&myArray, 3));
    printf("%s\n", darray_front(&myArray));
    printf("%s\n", darray_back(&myArray));

    while(!darray_isEmpty(&myArray)) {
        printf("%s\n", darray_back(&myArray));
        darray_popBack(&myArray);
    }

    printf("%s\n", darray_back(&myArray));
}