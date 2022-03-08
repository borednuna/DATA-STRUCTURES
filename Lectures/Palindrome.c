#include <stdio.h>
#include <string.h>

void main() {
    char str[100];
    char *start, *end;
    int check = 1;

    scanf("%[^\n]s", str);
    start = &str[0];
    end = &str[strlen(str)-1];

    while (start != end) {
        if (toupper(*start) != toupper(*end)) {
            check = 0;
            break;
        }
        start++;
        end--;
    }

    if (check) {
        printf("PALINDROM\n");
    } else {
        printf("BUKAN PALINDROM\n");
    }
}