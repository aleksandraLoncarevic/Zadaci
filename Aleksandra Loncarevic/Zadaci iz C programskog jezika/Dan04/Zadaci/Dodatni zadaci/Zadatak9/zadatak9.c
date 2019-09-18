#include <stdio.h>
#include <stdlib.h>

float prosekZaZbir(int);
void test();

int main() {
    int zbirKockica;
    printf("Unesite broj koji zelite da dobijete bacanjem dve kockice(2-12): ");
    scanf(" %i", &zbirKockica);
    if(zbirKockica<2 || zbirKockica>12) {
        printf("Neispravan opseg!!!\n");
    } else {
        float prosek = prosekZaZbir(zbirKockica);
        printf("Prosecan broj bacanja kockica za 100000 pokusaja je %.2f\n", prosek);
        test();
    }
    return 0;
}

int baciZbir(int zeljeniIshod) {
    int brojBacanja = 0;
    int trenutnoBacanje = 0;
    do{
       brojBacanja++;
       trenutnoBacanje = (rand() % 11) + 2;
    }while(trenutnoBacanje!=zeljeniIshod);
    return brojBacanja;
}

float prosekZaZbir(int zeljeniIshod) {
    int ukupanBrojBacanja = 0;
    for(int i=0; i<100000; i++) {
        ukupanBrojBacanja+=baciZbir(zeljeniIshod);
    }
    return (float) ukupanBrojBacanja/100000;
}

void test() {
    printf("Zbir dve kocke\tProsecan broj bacanja:\n");
    for(int i=2; i<=12; i++) {
        float prosek = prosekZaZbir(i);
        printf("\t%i\t\t%.2f\n", i, prosek);
    }
}
