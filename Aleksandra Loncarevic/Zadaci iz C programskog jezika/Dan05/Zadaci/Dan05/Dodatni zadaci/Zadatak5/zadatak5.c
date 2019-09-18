#include <stdio.h>

float srednjaVrednost(int* niz, int n);
int minNiza(int* niz, int n);
int maxNiza(int* niz, int n);

int main() {
    int n;
    printf("Unesite velicinu niza: ");
    scanf(" %i", &n);
    int niz[n];
    for(int i=0; i<n; i++) {
        printf("Unesite %i.element niza: ", i+1);
        scanf(" %i", &niz[i]);
    }
    for(int i=0; i<n; i++) {
        if(niz[i]==srednjaVrednost(niz, n)){
            printf("Elemenat na %i.poziciji ima istu vrednost kao srednja vrednost niza.\n", i+1);
        }
    }
    printf("\nNajmanji element niza je %i i nalazi se na %i.poziciji.", niz[minNiza(niz, n)], minNiza(niz, n)+1);
    printf("\nNajveci element niza je %i i nalazi se na %i.poziciji.\n", niz[maxNiza(niz, n)], maxNiza(niz, n)+1);
    return 0;
}

float srednjaVrednost(int *niz, int n) {
    int suma = 0;
    for(int i=0; i<n; i++) {
        suma+=niz[i];
    }
    return (float)suma/n;
}


int maxNiza(int *niz, int n) {
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

int minNiza(int *niz, int n) {
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
