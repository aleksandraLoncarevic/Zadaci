#include <stdio.h>

void uskrs(int godina){
    int a, b, c, d, e;
    a = godina % 19;
    b = godina % 4;
    c = godina % 7;
    d = (19 * a + 24) % 30;
    e = (2 * b + 4 * c + 6 * d + 5) % 7;
    if(22 + d + e <= 31) {
        printf("Uskrs je %i. marta.\n", 22 + d + e);
    } else {
        printf("Uskrs je %i. aprila.\n", 22 + d +e - 31);
    }
}

int main() {
    int godina;
    printf("Unesite godinu izmedju 1982. i 2048: ");
    scanf(" %i", &godina);
    uskrs(godina);
    return 0;
}
