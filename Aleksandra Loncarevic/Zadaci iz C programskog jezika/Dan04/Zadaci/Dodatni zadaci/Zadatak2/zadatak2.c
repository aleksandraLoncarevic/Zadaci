#include <stdio.h>

float rek_niz(int n) {
    if(n==1) {
        return 2;
    } else if(n==2) {
        return 4;
    } else {
        return 3*rek_niz(n-1) - rek_niz(n-2)/2 +6;
    }
}

int main() {
    int broj;
    printf("Unesite broj: ");
    scanf(" %i", &broj);
    printf("%i.clan rekurentnog niza je %.3f.\n", broj, rek_niz(broj));
    return 0;
}
