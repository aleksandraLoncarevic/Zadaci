#include <stdio.h>

int prestupnaGodina(int godina);

int main() {
    printf("1.Broj dana u mesecu za unetu godinu\n2.Exit\n\n");

    int dani[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int godina;
    int redniBrojMes;

    int izbor;
    do{
        printf("\nUnesi izbor: ");
        scanf(" %i", &izbor);
        switch(izbor){
            case 1:
                do{
                    printf("\nUnesite godinu: ");
                    scanf(" %i", &godina);
                    if(godina>0){
                    do{
                        printf("Unesite redni broj meseca u godini: ");
                        scanf(" %i", &redniBrojMes);
                    }while(redniBrojMes<0 || redniBrojMes>12);
                }
            }while(godina<=0);
            if(redniBrojMes==2 && prestupnaGodina(godina)) {
                printf("Broj dana u %i.mesecu %i.godine je %i.\n", redniBrojMes, godina, dani[redniBrojMes-1]+1);
            }else{
                printf("Broj dana u %i.mesecu %i.godine je %i.\n", redniBrojMes, godina, dani[redniBrojMes-1]);
            }
            break;
            case 2:
                exit(01201);
        }
    }while(izbor==1);
    return 0;
}

int prestupnaGodina(int godina) {
    if((godina%400==0) || (godina%100!=0 && godina%4==0)) {
        return 1;
    }
    return 0;
}
