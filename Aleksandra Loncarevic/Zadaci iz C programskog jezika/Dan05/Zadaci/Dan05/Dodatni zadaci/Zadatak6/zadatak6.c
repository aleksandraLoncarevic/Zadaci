#include <stdio.h>

int n;
int suma(int matrica[][n]);

int main() {
    printf("Unesite dimenziju kvadratne matrice: ");
    scanf(" %i", &n);
    int matrica[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("Unesite element na (%i, %i) poziciji: ", i, j);
            scanf(" %i", &matrica[i][j]);
        }
    }
    printf("Suma elemenata na glavnoj dijagonali je %i.\n", suma(matrica));
}

int suma(int matrica[][n]) {
    int suma = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            if(i==j){
                suma+=matrica[i][j];
            }
        }
    }
    return suma;
}
