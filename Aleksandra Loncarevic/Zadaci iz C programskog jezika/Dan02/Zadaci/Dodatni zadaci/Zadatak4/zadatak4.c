#include <stdio.h>

int main() {
    int celzijus;
    printf("Unesite temperaturu u Celzijusovim: ");
    scanf("%d", &celzijus);
    float farenhajt = celzijus*1.8 + 32;
    printf("Temperatura u Farenhajtovim je %f.\n", farenhajt);
    return 0;
}
