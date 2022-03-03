#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Libraries/arrlibrary.h"

void dArray_insertAt(DynamicArray *darray, unsigned index, int value);
void dArray_removeAt(DynamicArray *darray, unsigned index);

int main() {
    DynamicArray myArray;
    dArray_init(&myArray);

    dArray_pushBack(&myArray, 7);
    dArray_pushBack(&myArray, 9);
    dArray_pushBack(&myArray, 11);
    dArray_pushBack(&myArray, 13);

    int index = 2, value = 99;
    for (int i = 0; i < myArray._size; ++i) {
        printf("%d ", myArray._arr[i]);
    }
    printf("\n\n");

    dArray_insertAt(&myArray, index, value);

    for (int i = 0; i < myArray._size; ++i) {
        printf("%d ", myArray._arr[i]);
    }
    printf("\n---\n");

    dArray_removeAt(&myArray, index);

    for (int i = 0; i < myArray._size; ++i) {
        printf("%d ", myArray._arr[i]);
    }
    printf("\n---\n");
    // free(&myArray);
}

void dArray_insertAt(DynamicArray *darray, unsigned index, int value)
{
    if(dArray_isEmpty(darray) || index >= darray->_size)
        dArray_pushBack(darray, value);
    else{
        darray->_size++;
        int temp = darray->_arr[index];
        int temp2 = 0;
        for(unsigned i = index; i <= darray->_size; i++){
            temp2 = darray->_arr[i];
            darray->_arr[i] = temp;
            temp = temp2;
        }
        darray->_arr[index] = value;
    }
}

void dArray_removeAt(DynamicArray *darray, unsigned index)
{
    if(!dArray_isEmpty(darray)){
        for(;index <= darray->_size;index++)
            darray->_arr[index] = darray->_arr[index+1];
        darray->_size--;
    }
}