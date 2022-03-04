#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../Libraries/listlibrary.h"

void forEachElement (SinglyList *list, void (*function)(int *data));
void printElement(int *elem);
void multiply2(int *elem);

int main() {
    SinglyList myList;
    slist_init (&myList);
    slist_pushBack (&myList, 9);
    slist_pushBack (&myList, 8);
    slist_pushBack (&myList, 1);
    slist_pushBack (&myList, 7);
    slist_pushBack (&myList, 5);

    forEachElement(&myList, printElement);
    forEachElement(&myList, multiply2);
    forEachElement(&myList, printElement);
}

void forEachElement (SinglyList *list, void (*function)(int *data)) {
    SListNode *temp = list->_head;
    while(temp != NULL){
        function(&temp->data);
        temp = temp->next;
    }
}

void printElement(int *elem) {
    printf("%d\n", *elem);
}

void multiply2(int *elem) {
    *elem = *elem * 2;
}