#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("1.Pogadjanje broja\n2.Exit\n");
    int izbor;

    int broj;
    int zamisljeniBroj;
    do{
        printf("\nUnesite izbor: ");
        scanf(" %i", &izbor);
        switch(izbor) {
        case 1:
            zamisljeniBroj = (rand()%99)+1;
            for(int i=0; i<6; i++) {
                printf("\nUnesite broj: ");
                scanf(" %i", &broj);
                if(broj==zamisljeniBroj) {
                    printf("Svaka cast pogodili ste zamisljeni broj!!!\n");
                    break;
                }else if(broj<zamisljeniBroj) {
                    printf("Zamisljeni broj je veci od broja koji ste uneli.\n");
                }else{
                    printf("Zamisljeni broj je manji od broja koje ste uneli.\n");
                }
            }
            printf("\nNE ODUSTAJ!!!Pokusaj ponovo. Bili ste blizu.\n");
            break;
        case 2:
            exit(0);
        }
    }while(izbor==1);
    return 0;
}
