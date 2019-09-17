#include <stdio.h>

int main() {
    int farenhajt;
    printf("Unesite broj stepeni u Farenhajtovim: ");
    scanf("%d", &farenhajt);
    float celzijus = (farenhajt - 32)/ 1.8;
    printf("Temperatura u Celzijusovim stepenima iznosi %f.\n", celzijus);

    return 0;
}

