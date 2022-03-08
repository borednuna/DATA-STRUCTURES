#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int alph[26] = {0};

    int check = 1;
    printf("Kata 1: "); scanf("%s", str1);
    printf("Kata 2: "); scanf("%s", str2);

    char *first, *sec;
    first = &str1[0];
    sec = &str2[0];

    if (strlen(str1) != strlen(str2)) {
        check = 0;
    }

    while (*first != '\0' && *sec != '\0') {
        alph[(int)(*first - 'a')]++;
        alph[(int)(*sec - 'a')]--;
        first++; sec++;
    }

    for (int i=0; i < 26; i++) {
        if (alph[i] != 0) {
            check = 0;
            break;
        }
    }

    if (check) {
        printf("ANAGRAM\n");
    } else {
        printf("BUKAN ANAGRAM\n");
    }
}