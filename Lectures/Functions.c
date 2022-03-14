// March 15th
#include <stdio.h>
#include <math.h>

int faktorial(int);
int optfaktorial(int);
int pangkat(int, int);
int cekprima(int);
void cetakprima(int, int);

/* Uncomment sections according to your needs */
int main() {
    // Faktorial
    int buff;
    printf("Cari faktorial dari :"); scanf("%d", &buff);
    printf("%d\n", optfaktorial(buff));

    // Pangkat
    // int pngkt, n;
    // printf("Cari pangkat :"); scanf("%d", &pngkt);
    // printf("Dari bilangan :"); scanf("%d", &n);
    // printf("%d\n", pangkat(n, pngkt));

    // Cek prima
    // int prm;
    // printf("Cek prima untuk bilangan : "); scanf("%d", &prm);
    // if (cekprima(prm)) {
    //     printf("Bilangan %d prima\n", prm);
    // } else {
    //     printf("Bilangan %d bukan prima\n", prm);
    // }

    // Cetak prima
    // int from, to;
    // printf("Cetak bilangan prima dari : "); scanf("%d", &from);
    // printf("Cetak bilangan prima sampai : "); scanf("%d", &to);
    // cetakprima(from, to);
}

int faktorial(int x) { 
    // Using recursive
    // O(N^2)

    if (x == 0) {
        return 1;
    } else if (x == 1) {
        return 1;
    } else {
        return x * faktorial(x-1);
    }
}

int optfaktorial(int x) { 
    // Faktorial optimized (faster than the above)
    // O(N)

    int temp = 1;

    if (x == 0) {
        return 1;
    } else if (x == 1) {
        return 1;
    } else {
        for (int i = 2; i <= x; i++) {
            temp = i*temp;
        }
    }

    return temp;
}

int pangkat(int x, int y) {
    int buff = x;
    if (y == 0)
        return 1;

    while (y > 1) {
        x = x * buff;
        y--;
    }

    return x;
}

int cekprima(int x) {
    if (x == 0 || x == 1) {
        return 0;
    }

    /* Optimized using sqrt(x), alternative using 
    for (int i=2; pangkat(i, 2) <= x; i++)

    Any idea to optimize this more ? */
    for (int i=2; i <= sqrt(x); i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

void cetakprima(int x, int y) {
    // No idea to optimize this function
    for (int i = x; i <= y; i++) {
        if (cekprima(i)) {
            printf("%d ", i);
        }
    }
}
