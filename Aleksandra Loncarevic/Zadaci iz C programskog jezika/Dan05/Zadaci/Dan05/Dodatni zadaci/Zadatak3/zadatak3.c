#include <stdio.h>
#include <stdbool.h>

int main() {
    int vr, kol;
    printf("Unesite broj vrsta: ");
    scanf(" %i", &vr);
    printf("Unesite broj kolona: ");
    scanf(" %i", &kol);
    int matrica[vr][kol];
    for(int i=0; i<vr; i++) {
        for(int j=0; j<kol; j++) {
            printf("Unesite element na (%i, %i) poziciju: ", i+1, j+1);
            scanf(" %i", &matrica[i][j]);
        }
    }

    int k=0; /*fiksiramo kolonu, a prolazimo kroz vrste samo*/
    bool a = false;
    for(int i=0; i<vr; i++){
        if(matrica[i][k]%2==0) {
            a = true;
        }
        k++;
    }

    if(a) {
        printf("U matrici postoje kolone koje su parne.\n");
    } else {
        printf("U matrici ne postoje kolone koje su parne.\n");
    }
    return 0;
}
