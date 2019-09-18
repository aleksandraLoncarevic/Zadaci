#include <stdio.h>
#include <math.h>

int brojParova(int);

int main() {
    int velikiBroj;
    printf("Unesi pozitivan ceo broj koji predstavlja veliki broj sa vrha karte: ");
    scanf(" %i", &velikiBroj);
    printf("Broj parova dobijenih iz broja %i cija su oba elementi deljiva sa 3 je: %i\n", velikiBroj, brojParova(velikiBroj));
}

int brojCifara(int broj) {
    int brCif = 0;
    while(broj!=0) {
        brCif++;
        broj=broj/10;

    }
    return brCif;
}

int brojParova(int broj) {
    int brojac = 0;
    int brCif = brojCifara(broj);
    for(int i=1; i<brCif; i++){
        int x1 = broj/pow(10, i); /*x1-prvi element para*/
        int y1 = broj % (int) pow(10, i); /*y1-drugi element para*/
        if(x1%3==0 && y1%3==0) {
            brojac++;
        }
    }
    return brojac;
}


