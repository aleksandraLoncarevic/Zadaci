#include <stdio.h>

int sumaPrethodnihEl(int niz[], int pozicija) { /*funkcija koja racuna sumu prethodnih elemenata*/
    int suma = 0;
    for(int i=0; i<pozicija; i++) {
        suma+= niz[i];
    }
    return suma;
}

int provera(int niz[], int n) {  /*funkcija koja vraca broj elemenata koji su jednaki sumi prethodnih elemenata*/
    int brojac = 0;
    for(int i=0; i<n; i++) {
        if(sumaPrethodnihEl(niz, i) == niz[i]) {
            brojac++;
        }
    }
    return brojac;
}

int main() {
    int n;
    printf("Unesite velicinu niza: ");
    scanf(" %i", &n);
    int niz[n];
    for(int i=0; i<n; i++) {
        printf("Unesite %i.element niza: ", i+1);
        scanf(" %i", &niz[i]);
    }
    printf("Broj elemenata u nizu koji su jednaki sumi prethodnih elemenata je %i.\n", provera(niz, n));
    return 0;
}
