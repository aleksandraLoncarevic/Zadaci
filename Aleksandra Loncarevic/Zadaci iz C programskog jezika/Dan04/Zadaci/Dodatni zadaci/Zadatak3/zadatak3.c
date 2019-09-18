#include <stdio.h>

int proizvod_cifara(int n) {
    if(n>0 && n<10) {
        return n;
    } else {
        return n%10 * proizvod_cifara(n/10);
    }
}

int main() {
    int broj;
    printf("Unesite broj: ");
    scanf(" %i", &broj);
    printf("Proizvod cifara unetog broja %i je %i.\n", broj, proizvod_cifara(broj));
    return 0;
}
