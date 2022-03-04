#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../Libraries/char_arrstack.h"

void pushstr(StackArray *stack, char* str);
int checkpal(StackArray *stack, char* str);
void retpal(int check);

int main() {
    int check = 1;
    char str[100];
    StackArray myStack;
    stackArray_init(&myStack, 20);
    
    pushstr(&myStack, str);
    retpal(checkpal(&myStack, str));
}

void pushstr(StackArray *stack, char* str) {
    scanf("%[^\n]s", str);

    for (int i=0; i < strlen(str); i++) {
        stackArray_push(stack, str[i]);
    }
}

int checkpal(StackArray *stack, char* str) {
    for (int j=0; j < strlen(str)/2; j++) {
        if (str[j] != stackArray_top(stack)) {
            return 0;
        }
        stackArray_pop(stack);
    }

    return 1;
}

void retpal(int check) {
    (check == 1 ? printf("palindrom\n") : printf("mahal, eh bukan palindrom\n"));
}