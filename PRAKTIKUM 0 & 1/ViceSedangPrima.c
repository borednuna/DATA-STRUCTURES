/* Please refer to "../Libraries/arrstack.h" */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct stackarr_t {
    int *_element, _topIndex;
    unsigned int _size, _capacity;
} StackArray;

void stackArray_init(StackArray *stack, unsigned stackSize);
bool stackArray_isEmpty(StackArray *stack);
void stackArray_push(StackArray *stack, int value);
void stackArray_pop(StackArray *stack);
int  stackArray_top(StackArray *stack);
int primes(int);

int main() {
    int query, buff;
    StackArray ordinary, prime;
    stackArray_init(&ordinary, 1000);
    stackArray_init(&prime, 1000);

    scanf("%d", &query);
    for(int i=0; i < query; i++) {
        scanf("%d", &buff);
        if (primes(buff) != -1) {
            stackArray_push(&prime, buff);
        } else {
            stackArray_push(&ordinary, buff);
        }
    }

    while (!stackArray_isEmpty(&prime)) {
        printf("%d\n", stackArray_top(&prime));
        stackArray_pop(&prime);
    }
    while (!stackArray_isEmpty(&ordinary)) {
        printf("%d\n", stackArray_top(&ordinary));
        stackArray_pop(&ordinary);
    }
}

void stackArray_init(StackArray *stack, unsigned int stackSize) 
{
    stack->_element  = (int*) malloc(sizeof(int) * stackSize);
    stack->_size     = 0;
    stack->_topIndex = -1;
    stack->_capacity = stackSize;
}

bool stackArray_isEmpty(StackArray *stack) {
    return (stack->_topIndex == -1);
}

void stackArray_push(StackArray *stack, int value)
{
    if (stack->_size + 1 <= stack->_capacity) {
        stack->_element[++stack->_topIndex] = value;
        stack->_size++;
    }
}

void stackArray_pop(StackArray *stack)
{
    if (!stackArray_isEmpty(stack)) {
        stack->_topIndex--;
        stack->_size--;
    }
}

int stackArray_top(StackArray *stack)
{
    if (!stackArray_isEmpty(stack)) {
        return stack->_element[stack->_topIndex];
    }
    return 0;
}


int primes(int n) {
    if (n == 0 || n == 1)
        return -1;

    for (int i = 2; i <= n/2; ++i) {
        if (n % i == 0) 
            return -1;
    }
    return 1;
 }