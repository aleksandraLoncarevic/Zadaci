#include <stdio.h>

/*Zadatak 5 deo pod a.*/

int main() {
    int x,y; /*koordinate pocetne pozicije topa*/
    printf("Unesite koordinate pocetne pozicije topa: ");
    scanf("%i %i", &x, &y);
    char oznaka; /*oznaka za smer*/
    printf("Uneti oznaku za smer u kom zelite da pomerite topa(u-up, r-right, l-left, d-down): ");
    scanf(" %c", &oznaka);
    int d;
    printf("Unesite koliko polja zelite da se pomerite: ");
    scanf(" %i", &d);
    if(oznaka=='u' && (x-d)>0) {         /*uslov x-d>0 znaci da top sme ici gore do 1 vrste, izvan ne moze*/
        printf("(%i, %i)", x-d, y);
    } else if(oznaka=='r' && (y+d)<9) {  /*uslov y+d<9 znaci da top sme ici desno do 8 kolone, izvan ne moze*/
        printf("(%i, %i)", x, y+d);
    } else if(oznaka=='d' && (x+d)<9) {  /*uslov x+d<9 znaci da top sme ici dole do 8 vrste,izvan ne moze*/
        printf("(%i, %i)", x+d, y);
    } else if(oznaka=='l' && (y-d)>0) { /*uslov y-d>0 znaci da top sme ici levo do 1 kolone, izvan ne moze*/
        printf("(%i, %i)", x, y-d);
    } else {
        printf("Top se ne moze pomeriti za unetu oznaku!!!\n");
    }
    return 0;
}
