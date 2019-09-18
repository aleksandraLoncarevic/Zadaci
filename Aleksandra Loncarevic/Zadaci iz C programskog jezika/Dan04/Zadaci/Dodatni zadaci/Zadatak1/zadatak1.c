#include <stdio.h>

float rek_niz(int n) {
    if(n==1) {
        return 3;
    }else{
        return 2+rek_niz(n-1)/2;
    }
}

int main() {
    int n;
    printf("Unesite clan niza koji zelite da izracunate: ");
    scanf(" %i", &n);
    printf("%i.clan datog niza je %.2f.\n", n, rek_niz(n));
    return 0;
}

