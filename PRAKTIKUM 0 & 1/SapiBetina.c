/* This code uses modified priority list.
Please refer to "listpriorqueue.h" at
"../Libraries/listpriorqueue.h". */

// 5025211051 - Hanun Shaka (borednuna)

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct pqueueNode_t {
    // modify attributes of the priority list nodes
    int age;
    int mass;
    int ID;
    struct pqueueNode_t *next;
} PQueueNode;

typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int age, int mass, int ID);
void pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);
void printEach(PriorityQueue *pqueue);

int main() {
    PriorityQueue cowList;
    pqueue_init(&cowList);
    int query, id, age, mass, amount;
    char order[10];

    scanf("%d", &query);
    for (int i=0; i < query; i++) {
        scanf("%s", order);
        if (strcmp(order, "DAFTAR") == 0) {
            scanf("%d %d %d", &id, &age, &mass);
            pqueue_push(&cowList, age, mass, id);
        } else {
            scanf("%d", &amount);
            for (int i=0; i < amount; i++) {
                if (pqueue_isEmpty(&cowList)) {
                    break;
                }
                pqueue_pop(&cowList);
            }
        }
    }
    printEach(&cowList);
}

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int age, int mass, int ID) // add age, mass and ID as arguments
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->age = age;
    // add inputs for mass and ID
    newNode->mass = mass;
    newNode->ID = ID;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if ( age > pqueue->_top->age || (age == pqueue->_top->age && mass > pqueue->_top->mass)) {
        // only put the new node as top if it has (bigger age) or (same age and bigger mass)
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    } else {
        while ( temp->next != NULL && temp->next->age > age ) {
            // iterate through the list until end of list nodes with bigger age
            temp = temp->next;
        }
        while ( temp->next != NULL && temp->next->age == age && temp->next->mass > mass ) {
            // once the node with same age is reached, iterate only through nodes with same age
            // until the node with (same age and fewer mass) is reached
            temp = temp->next;
        }
        // if there is no nodes with the same age, the iteration above will be neglected
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
        // return the ID instead of age or mass
    else return 0;
}

void printEach(PriorityQueue *pqueue) {
    // this function is made with the sole purpose of easier coding process
    PQueueNode *temp = pqueue->_top;
    while (temp != NULL) {
        printf("%d ", temp->ID);
        temp = temp->next;
    }
}
