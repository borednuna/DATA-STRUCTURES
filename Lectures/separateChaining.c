#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int value;
    struct node *next;
};

struct arrayData {
    struct node *head;
};

struct arrayData *array;
int size = 0;
int max = 7;