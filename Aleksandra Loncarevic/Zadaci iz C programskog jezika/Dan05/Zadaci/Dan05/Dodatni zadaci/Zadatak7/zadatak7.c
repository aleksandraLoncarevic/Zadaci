#include <stdio.h>

int n;
int m;

int minKolone(int matrica[][m], int k) {
    int min = matrica[0][k];
    for(int i=1; i<n; i++) {
        if(matrica[i][k]<min){
            min = matrica[i][k];
        }
    }
    return min;
}

int maxNiza(int *niz, int n) {
    int max = niz[0];
    for(int i=1; i<n; i++) {
        if(niz[i]>max){
            max= niz[i];
        }
    }
    return max;
}

int main() {
    printf("Unesite broj redova: ");
    scanf(" %i", &n);
    printf("Unesite broj kolona: ");
    scanf(" %i", &m);
    int matrica[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("Unesite element na poziciju (%i, %i): ", i, j);
            scanf(" %i", &matrica[i][j]);
        }
    }
    printf("Minimumi kolona su:\n");
    int niz[m]; /*niz u koga smestamo minumume kolona*/
    for(int i=0; i<m; i++) {
        niz[i] = minKolone(matrica, i);
        printf("%i\t", niz[i]);
    }
    printf("\nNajveci od svih minimuma je %i.\n", maxNiza(niz, m));
    return 0;
}
