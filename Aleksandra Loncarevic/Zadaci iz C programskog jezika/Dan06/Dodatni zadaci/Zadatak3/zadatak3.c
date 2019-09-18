#include <stdio.h>

int brMestana(int jmbg[][13], int, int);

int main() {
    int godina;
    printf("Unesite godinu rodjenja: ");
    scanf(" %i", &godina);
    if((godina>=2000 && godina<=2799) || (godina>=1800 && godina<=1999)) {
        int brojMestana;
        printf("Unesite broj mestana sela: ");
        scanf(" %i", &brojMestana);
        int jmbg[brojMestana][13];
        for(int i=0; i<brojMestana; i++) {
            printf("Unesite JMBG %i.mestanina: ", i+1);
            for(int j=0; j<13; j++) {
                scanf("%1d", &jmbg[i][j]);
            }
        }
        printf("Broj mestana koji su rodjenji %i.godine je %i.\n", godina, brMestana(jmbg, brojMestana, godina));
    }
    return 0;
}

int brMestana(int jmbg[][13], int n, int godina) {
    int brojac = 0;
    for(int i=0; i<n; i++) {
        int godinaJmbg = jmbg[i][4]*100+jmbg[i][5]*10+jmbg[i][6];
            if(godina%1000==godinaJmbg) {
                brojac++;
            }
    }
    return brojac;
}
