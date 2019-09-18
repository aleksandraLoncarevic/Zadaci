#include <stdio.h>

long long binarni_broj;

int binarni() {
    int decimalni_broj = 0;
    int baza = 1;
    while(binarni_broj!=0) {
        int c1 = binarni_broj%10;
        decimalni_broj += c1*baza;
        binarni_broj = binarni_broj/10;
        baza= baza*2;
    }
    return decimalni_broj;
}

int main() {
    printf("Unesite broj u binarnom zapisu koji zelite da konvertujete u decimalni zapis(dozvoljene su samo cifre 0 i 1): ");
    scanf(" %lld", &binarni_broj);
    printf("Decimalni zapis unetog broja je %d.\n", binarni());
    return 0;
}
