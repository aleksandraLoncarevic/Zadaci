#include <stdio.h>

int main() {
    int n;
    printf("Unesite dimenziju kvadratne matrice: ");
    scanf(" %i", &n);
    int matrica[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) {
                matrica[i][j] = 23;
            } else if(i<j) {
                matrica[i][j] = (i+1)*(j+1); /*posto nam vrste i kolone idu od 0, proizvod ce biti (i+1)*(j+1)*/
            } else {
                matrica[i][j] = (i+1)+(j+1);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            printf("%i\t", matrica[i][j]);
        }
        printf("\n");
    }
    return 0;
}
