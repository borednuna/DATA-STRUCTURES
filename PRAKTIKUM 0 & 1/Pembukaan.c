/* Please refer to "../Libraries/arrstack.h" */

// 5025211051 - Hanun Shaka (borednuna)

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct stackarr_t {
    int *_element, _topIndex;
    unsigned int _size, _capacity;
} StackArray;

void stackArray_init(StackArray *stack, unsigned stackSize);
bool stackArray_isEmpty(StackArray *stack);
void stackArray_push(StackArray *stack, int value);
void stackArray_pop(StackArray *stack);
int  stackArray_top(StackArray *stack);

int main() {
    StackArray print, sign, cover;
    stackArray_init(&print, 20);
    stackArray_init(&sign, 20);
    stackArray_init(&cover, 20);

    int query, amount, code = 1;
    char order[10];

    scanf("%d", &query);
    for (int i=0; i < query; i++) {
        scanf("%s", order);
        if (strcmp(order, "CETAK") == 0) {
            scanf("%d", &amount);
            for (int j=0; j < amount; j++) {
                stackArray_push(&print, code++);
            }
        } else if (strcmp(order, "TTD") == 0) {
            scanf("%d", &amount);
            for (int k=0; k < amount; k++) {
                stackArray_push(&sign, stackArray_top(&print));
                stackArray_pop(&print);
            }
        } else {
            scanf("%d", &amount);
            for (int l=0; l < amount; l++) {
                stackArray_push(&cover, stackArray_top(&sign));
                stackArray_pop(&sign);
            }
        }
    }

    printf("tumpukan 1: ");
    for (int i=0; i < print._size; i++) {
        printf("%d ", print._element[i]);
    }
    printf("\n");

    printf("tumpukan 2: ");
    for (int i=0; i < sign._size; i++) {
        printf("%d ", sign._element[i]);
    }
    printf("\n");

    printf("tumpukan 3: ");
    for (int i=0; i < cover._size; i++) {
        printf("%d ", cover._element[i]);
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
