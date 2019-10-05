#include <stdio.h>
#include <stdlib.h>

int sumaPrvihKprirodnihBrojeva(int k);

int main() {
    printf("1.Suma prvih k prirodnih brojeva\n2.Exit\n");
    int izbor;

    int k;
    do{
        printf("\nUnesite izbor: ");
        scanf(" %i", &izbor);
        switch(izbor) {
        case 1:
            do{
                printf("\nUnesite prirodan broj k: ");
                scanf(" %i", &k);
            }while(k<=0);
            printf("Suma prvih %i prirodnih brojeva je %i.\n", k, sumaPrvihKprirodnihBrojeva(k));
            break;
        case 2:
            exit(0);
        }
    }while(izbor==1);
    return 0;
}


int sumaPrvihKprirodnihBrojeva(int k) {
    int suma = 0;
    for(int i=1; i<=k; i++){
        suma+=i;
    }
    return suma;
}
