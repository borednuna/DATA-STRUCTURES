#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../Libraries/listlibrary.h"

void printElement(int *elem) {
    printf("%d\n", *elem);
}

void multiply2(int *elem) {
    *elem = *elem * 2;
    printElement(elem);
}

void forEachElement (SinglyList *list, void (*function)(int *data)){
    SListNode *temp = list->_head;
    while(temp != NULL){
        function(&temp->data);
        temp = temp->next;
    }
}

void sumDigit(int *elem){
    int sum = 0, temp;
    while(*elem > 0){
        temp = *elem % 10;
        sum += temp;
        *elem /= 10;
    }
    *elem = sum;
    printElement(elem);
}

void reverseEach(int *elem){
    int result = 0;
    while(*elem > 0){
        result *= 10;
        result = result + *elem % 10;
        *elem /= 10;
    }
    *elem = result;
    printElement(elem);
}

int main(int argc, char const *argv[]){
    SinglyList myList;
    slist_init (&myList);
    slist_pushBack (&myList, 12);
    slist_pushBack (&myList, 34);
    slist_pushBack (&myList, 56);
    slist_pushBack (&myList, 78);
    slist_pushBack (&myList, 981);

    forEachElement(&myList, printElement);
    printf("============================\n");
    forEachElement(&myList, multiply2);
    printf("============================\n");
    forEachElement(&myList, sumDigit);
    printf("============================\n");
    forEachElement(&myList, reverseEach);
}