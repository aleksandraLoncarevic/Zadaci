#include <stdio.h>
#include <stdlib.h>

void trougao(int n);

int main() {
    printf("1.Trougao\n2.Exit\n");
    int izbor;

    int n;
    do{
        printf("\nUnesite izbor: ");
        scanf(" %i", &izbor);
        switch(izbor) {
        case 1:
            do{
                printf("\nUnesite neparan broj n: ");
                scanf(" %i", &n);
            }while(n%2==0);
            trougao(n);
            break;
        case 2:
            exit(0);
        }
    }while(izbor==1);
}

void trougao(int n) {
    int i, j;
    for(i=1; i<=n; i+=2) {
        for(j=0;j<i;j++){
            printf(" ");
        }
        for(j=n; j>=i; j--) {
            printf("* ");
        }
        printf("\n");
    }
}
