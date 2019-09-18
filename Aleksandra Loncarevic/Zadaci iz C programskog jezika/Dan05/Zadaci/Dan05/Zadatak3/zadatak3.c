#include <stdio.h>

int pronadjiIndexElementa(int niz[], int n, int element) {
    for(int i=0; i<n; i++) {
        if(niz[i]==element) {
            return i;
        }
    }
    return -1;
}

int obrisiElement(int niz[], int n, int element) {
    int pozicija = pronadjiIndexElementa(niz, n, element);
    if(pozicija!=-1) {
        for(int c = pozicija; c<n-1; c++) {
            niz[c]=niz[c+1];
        }
    } else {
        printf("Uneti element ne postoji u nizu!!!");
    }
    return n-1;
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
    int element;
    printf("Unesite element koji zelite da obrisete: ");
    scanf(" %i", &element);
    n = obrisiElement(niz, n, element);
    printf("Rezultat:\n");
    for(int i=0; i<n; i++) {
        printf("%i\t", niz[i]);
    }
    return 0;
}
