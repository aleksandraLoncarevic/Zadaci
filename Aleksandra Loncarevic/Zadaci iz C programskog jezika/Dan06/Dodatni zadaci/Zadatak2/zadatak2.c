#include <stdio.h>

int preostaloDiskova(float *precnikDiskova, int brojDiskova, float precnikBrave);

int main() {
    float precnikBrave;
    printf("Unesite precnik otvora brave: ");
    scanf(" %f", &precnikBrave);
    int brojDiskova;
    printf("Unesite broj diskova koje kljuc ima: ");
    scanf(" %i", &brojDiskova);
    float precnikDiskova[brojDiskova];
    for(int i=0; i<brojDiskova; i++) {
        printf("Unesite precnik %i.diska: ", i+1);
        scanf(" %f", &precnikDiskova[i]);
    }
    printf("Broj diskova koji su ostali van brave je %i.\n", preostaloDiskova(precnikDiskova, brojDiskova, precnikBrave));
    return 0;
}

int preostaloDiskova(float *precnikDiskova, int brojDiskova, float precnikBrave) {
    int brojac = 0;
    for(int i=brojDiskova-1; i>=0; i--) {
        if(precnikDiskova[i]<=precnikBrave) {
            brojac++;
        }else{
            break;
        }
    }
    return brojDiskova-brojac; /*preostali broj diskova koji nisu prosli precnik brave*/
}
