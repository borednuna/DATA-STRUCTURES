#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct pqueueNode_t {
    int data;
    int ID;
    struct pqueueNode_t *next;
} PQueueNode;

typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int value, int ID)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->ID = ID;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value < pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    } else {
        while ( temp->next != NULL && 
                temp->next->data < value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->ID;
    else return 0;
}

int main() {
    int num;
    scanf("%d", &num);

    char type[10];
    int ID, value;

    PriorityQueue myqueue;
    pqueue_init(&myqueue);

    for (int i=0; i < num; i++) {
        scanf("%s", type);
        if (strcmp(type, "MASUK") == 0) {
            scanf("%d %d", &ID, &value);
            pqueue_push(&myqueue, value, ID);
        } else {
            if (pqueue_top(&myqueue) == 0) {
                printf("HORE\n");
            } else {
                printf("%d\n", pqueue_top(&myqueue));
                pqueue_pop(&myqueue);
            }
        }
    }
}