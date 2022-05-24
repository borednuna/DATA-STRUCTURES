#include <stdio.h>
#include <stdlib.h>

typedef struct tipeS {
    struct tipeS *Left;
    int INFO;
    struct tipeS *Right;
};

typedef struct tipeS simpul;
simpul *p, *FIRST, *LAST, *PVertex, *PEdge, *Q, *R, *S;
simpul *PointS[5];

void main() {
    int A[5][5] = {0, 5, 0, 2, 0,   6, 0, 3, 0, 0,
                    0, 0, 0, 0, 9,   0, 0, 12, 0, 7,     0, 14, 0, 0, 0};
    char NmS[5] = "ABCDE";
    int I, J;

    // Simpul vertex yang pertama
    I = 0;
    J = 0;
    p = (simpul*) malloc(sizeof(simpul));
    p->INFO = NmS[0];
    FIRST = p;
    LAST = p;
    p->Left = NULL;
    p->Right = NULL;
    PointS[0] = p;
    printf("%c", p->INFO);
    printf(" alamat %d ", PointS[0]);

    // Simpul vertex yang berikutnya
    for (int i=1; i <=4; i++) {
        p = (simpul*) malloc(sizeof(simpul));
        p->INFO = NmS[i];
        LAST->Left = p;
        LAST = LAST->Left;
        p->Left = NULL;
        p->Right = NULL;
        PointS[i] = p;
        printf("\n%c ", p->INFO);
        printf("alamat %d ", PointS[i]);
    }
    printf("\n\n");

    // Simpul edge untuk semua vertex
    Q = FIRST;
    for (int i = 0; i <= 4; i++) {
        R = Q;
        printf("Vertex %c .... \n", Q->INFO);
        for (int j = 0; j <= 4; j++) {
            if (A[i][j] != 0) {
                p = (simpul*) malloc(sizeof(simpul));
                p->INFO = A[i][j];
                p->Right = p;
                p->Left = PointS[j];
                printf("\tBerhubungan dengan %c : ", p->Left->INFO);
                printf("bobot %d\n", p->INFO);
                p->Right = NULL;
                R = p;
            }
        }
        printf("\n");
        Q = Q->Left;
    }
}
