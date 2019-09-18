#include <stdio.h>

void swap(int *niz) {
    int temp = *(niz+1);
    *(niz+1) = *(niz+4);
    *(niz+4) = temp;
}

int maxElement(int *niz, int n) {
    int *p = niz;
    int max = niz[0];
    for(int i=0; i<n; i++, p++) {
        if(max<=*p) {
            max=*p;
        }
    }
    return max;
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

    swap(niz);
    printf("Posle zamene 2. i 5. elementa niz izgleda:\n");
    for(int i=0; i<n; i++) {
        printf("%i\t", niz[i]);
    }

    printf("\n\nMaksimalni element niza je %i.\n", maxElement(niz, n));
    return 0;
}
