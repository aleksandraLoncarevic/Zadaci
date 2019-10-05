#include <stdio.h>
#include <stdlib.h>

void beskonacanNiz(int n);

int main() {
    printf("1.Unos n\n2.Exit\n");
    int izbor;

    int n;
    do{
        printf("\nUnesite izbor: ");
        scanf(" %i", &izbor);
        switch(izbor) {
        case 1:
            do{
                printf("\nUnesite n: ");
                scanf(" %i", &n);
            }while(n<=8);
            beskonacanNiz(n);
            break;
        case 2:
            exit(0);
        }
    }while(izbor==1);
    return 0;
}


void beskonacanNiz(int n) {
    int pocetnaVel = 2;
    int *niz = (int*)calloc(pocetnaVel, sizeof(int));
    niz[0] = 2;
    niz[1] = 8;
    int i = 1;
    do{
        ++pocetnaVel;
        *niz = (int*)realloc(*niz, pocetnaVel);
        ++i;
        niz[i] = niz[i-1] + 6;
    }while(n>niz[i]);
    if(n==niz[i]){
        printf("Uneti element se nalazi u nizu na poziciji %i.\n", i+1);
    }else{
        printf("Uneti element se ne nalazi u nizu. Postoje elementi %i i %i.\n", niz[i-1], niz[i]);
    }
    free(niz);
}
