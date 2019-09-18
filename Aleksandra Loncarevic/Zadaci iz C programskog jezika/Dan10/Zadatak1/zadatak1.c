#include <stdio.h>
#include <stdlib.h>


typedef struct cvor {
    int broj;
    struct cvor *sledeci;
}CVOR;

CVOR *dodajNaPocetak(CVOR *prvi);
void ispisiListu(CVOR *prvi);
CVOR *najveciElement(CVOR *prvi);
CVOR *najmanjiElement(CVOR *prvi);
void swap(CVOR *max, CVOR *min);

int main() {
    int n;
    printf("Unesite broj n: ");
    scanf(" %i", &n);

    CVOR *prvi = NULL;
    for(int i=0; i<n; i++) {
        prvi = dodajNaPocetak(prvi);
    }
    printf("Lista nasumicno %i celih brojeva je: ", n);
    ispisiListu(prvi);
    CVOR *max = najveciElement(prvi);
    printf("\nNajveci element je %i.\n", max->broj);
    CVOR *min = najmanjiElement(prvi);
    printf("Najmanji element je %i.\n", min->broj);
    swap(max, min);
    printf("Lista posle zamene najveceg i najmanjeg elementa: ");
    ispisiListu(prvi);
}

CVOR *dodajNaPocetak(CVOR *prvi) {
    CVOR *novi = malloc(sizeof(CVOR));
    novi->broj = rand();
    novi->sledeci = prvi;
    prvi = novi;
    return prvi;
}

void ispisiListu(CVOR *prvi) {
    CVOR *tek;
    for(tek=prvi; tek; tek=tek->sledeci) {
        printf("%i ", tek->broj);
    }
}

CVOR *najveciElement(CVOR *prvi) {
    CVOR *tek;
    CVOR *max = prvi;
    for(tek=prvi->sledeci; tek; tek=tek->sledeci) {
        if(tek->broj>max->broj) {
            max=tek;
        }
    }
    return max;
}

CVOR *najmanjiElement(CVOR *prvi) {
    CVOR *tek;
    CVOR *min = prvi;
    for(tek=prvi->sledeci; tek; tek=tek->sledeci) {
        if(tek->broj<min->broj) {
            min=tek;
        }
    }
    return min;
}

void swap(CVOR *max, CVOR *min) {
    int t;
    t = max->broj;
    max->broj = min->broj;
    min->broj = t;
}
