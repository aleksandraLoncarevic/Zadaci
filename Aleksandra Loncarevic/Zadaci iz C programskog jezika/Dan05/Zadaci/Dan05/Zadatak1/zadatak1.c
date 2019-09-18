#include <stdio.h>

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
    for(int i = 0; i<n; i++) {
        printf("Unesite %i.element niza: ", i+1);
        scanf(" %i", &niz[i]);
    }
    printf("\nMaksimalni element niza je %i.\n", maxElement(niz, n));
    return 0;
}

