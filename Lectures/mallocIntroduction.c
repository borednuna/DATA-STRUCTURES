#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

typedef struct Mahasiswa {
    int nim;
    struct Mahasiswa *next;
} Mahasiswa;

void init(Mahasiswa **p) {
    *p == NULL;
}

Mahasiswa *alokasi(int nim) {
    Mahasiswa *P;
    P = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    if (P != NULL) {
        P->next = NULL;
        P->nim = nim;
    }
    return P;
}

void Add(Mahasiswa **P, int nim) {
    *P = alokasi(nim);
    printf("%d", (*P)->nim);
}

int main() {
    Mahasiswa *head;
    init(&head);
    Add(&head, 20);
}