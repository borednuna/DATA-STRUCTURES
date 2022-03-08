#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Libraries/str_listpriorqueue.h"
#include "../Libraries/str_listqueue.h"
#include "../Libraries/str_listdequeue.h"
#include "../Libraries/str_arrqueue.h"
#include "../Libraries/str_liststack.h"
#include "../Libraries/str_arrstack.h"

int main() {
    // Priority Queue
    PriorityQueue mypqueue;
    pqueue_init(&mypqueue);

    pqueue_push(&mypqueue, "TEST");
    pqueue_push(&mypqueue, "CASE");
    pqueue_push(&mypqueue, "STRUKTUR DATA");

    while (!pqueue_isEmpty(&mypqueue)) {
        printf("\n%s\n", pqueue_top(&mypqueue));
        pqueue_pop(&mypqueue);
    }

    // list queue
    // Queue myList;
    // queue_init(&myList);

    // queue_push(&myList, "TEST");
    // queue_push(&myList, "CASE");
    // queue_push(&myList, "STRUKTUR DATA");

    // while (!queue_isEmpty(&myList)) {
    //     printf("\n%s\n", queue_front(&myList));
    //     queue_pop(&myList);
    // }

    // List dequeue
    // Deque myDeq;
    // deq_init(&myDeq);

    // deq_pushFront(&myDeq, "TEST");
    // deq_pushFront(&myDeq, "CASE");
    
    // printf("\n%s\n", deq_front(&myDeq));
    // deq_popFront(&myDeq);

    // deq_pushBack(&myDeq, "STRUKTUR");
    // deq_pushBack(&myDeq, "DATA");

    // while (!deq_isEmpty(&myDeq)) {
    //     printf("\n%s\n", deq_back(&myDeq));
    //     deq_popBack(&myDeq);
    // }

    // Array queue
    // QueueArray myArr;
    // queueArray_init(&myArr, 10);

    // queueArray_push(&myArr, "TEST");
    // queueArray_push(&myArr, "CASE");
    // queueArray_push(&myArr, "STRUKTUR DATA");

    // while (!queueArray_isEmpty(&myArr)) {
    //     printf("\n%s\n", queueArray_front(&myArr));
    //     queueArray_pop(&myArr);
    // }

    // List stack
    // Stack myStack;
    // stack_init(&myStack);

    // stack_push(&myStack, "TEST");
    // stack_push(&myStack, "CASE");
    // stack_push(&myStack, "STRUKTUR DATA");

    // while (!stack_isEmpty(&myStack)) {
    //     printf("\n%s\n", stack_top(&myStack));
    //     stack_pop(&myStack);
    // }

    // Array Stack
    // StackArray myArr;
    // stackArray_init(&myArr, 10);

    // stackArray_push(&myArr, "TEST");
    // stackArray_push(&myArr, "CASE");
    // stackArray_push(&myArr, "STRUKTUR DATA");

    // while (!stackArray_isEmpty(&myArr)) {
    //     printf("\n%s\n", stackArray_top(&myArr));
    //     stackArray_pop(&myArr);
    // }
}