#include <stdio.h>

int minNiza(int *niz, int n) { /*Funkcija koja vraca poziciju najmanjeg elementa*/
    int min = niz[0];
    int minIndex = 0;
    for(int i=1; i<n; i++) {
        if(niz[i]<min) {
            min = niz[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int maxNiza(int *niz, int n) { /*Funkcija koja vraca poziciju najveceg elementa*/
    int max = niz[0];
    int maxIndex = 0;
    for(int i=1; i<n; i++) {
        if(niz[i]>max) {
            max = niz[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int obrisiElement(int niz[], int n, int pozicija) {
    for(int c = pozicija; c<n-1; c++) {
            niz[c]=niz[c+1];
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
    printf("Najmanji element je na poziciji %i, a najveci element je poziciji %i.\n", minNiza(niz, n)+1, maxNiza(niz, n)+1);
    n = obrisiElement(niz, n, minNiza(niz, n));
    n = obrisiElement(niz, n, maxNiza(niz, n));
    for(int i=0; i<n; i++) {
        printf("%i\t", niz[i]);
    }
    return 0;
}
