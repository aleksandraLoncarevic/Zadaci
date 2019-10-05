#include <stdio.h>
#include <stdlib.h>

int deljiviSa7(int n);

int main() {
    printf("1.Koliko brojeva iz intervala [1,..,n] deljivo sa 7\n2.Exit\n");
    int izbor;

    int n;
    do{
        printf("\nUnesite izbor: ");
        scanf(" %i", &izbor);
        switch(izbor) {
        case 1:
            do{
                printf("\nUnesi prirodan broj n: ");
                scanf(" %i", &n);
            }while(n<=0);
            printf("U intervalu [1,...,%i] ima %i brojeva deljivih sa 7.\n", n, deljiviSa7(n));
            break;
        case 2:
            exit(0);
        }
    }while(izbor==1);
    return 0;
}

int deljiviSa7(int n) {
    int brojac = 0;
    for(int i=1; i<=n; i++) {
        if(i%7==0) {
            brojac++;
        }
    }
    return brojac;
}
