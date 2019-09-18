#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct zaposleni {
    float plata;
    char ime_prezime[50];
    char jmbg[13];
}ZAPOSLENI;

typedef struct cvor {
    ZAPOSLENI zaposleni;
    struct cvor *sledeci;
}CVOR;

 void prikaziZaposlene(CVOR *lista);
 CVOR* dodajNaPocetak(CVOR *lista, ZAPOSLENI radnik);
 void modifikacija(CVOR *lista);

int main() {
    printf("*BAZA ZAPOSLENIH*\n1.PRIKAZ\n2.DODAJ\n3.MODIFIKUJ\n4.IZLAZ\n");
    int izbor;
    CVOR *lista = NULL;
    do{
        printf("\nUnesite izbor: ");
        scanf(" %i", &izbor);
        ZAPOSLENI radnik;

        switch(izbor) {
        case 1:
            prikaziZaposlene(lista);
            break;
        case 2:
            lista = dodajNaPocetak(lista, radnik);
            break;
        case 3:
            modifikacija(lista);
            break;
        case 4:
            exit(0);
        }
    }while(izbor>0 && izbor<5);
    return 0;
}

void prikaziZaposlene(CVOR *lista) {
    CVOR *tekuci;
    for(tekuci=lista; tekuci; tekuci=tekuci->sledeci) {
        printf("%s\t%s\t%f\n", tekuci->zaposleni.ime_prezime, tekuci->zaposleni.jmbg, tekuci->zaposleni.plata);
    }
}

CVOR *dodajNaPocetak(CVOR *lista, ZAPOSLENI radnik) {
    CVOR *novi = malloc(sizeof(CVOR));
    printf("\nUnesite ime i prezime radnika: ");
    scanf(" %[^\n]s", &radnik.ime_prezime);
    printf("Unesite jmbg radnika: ");
    scanf(" %s", &radnik.jmbg);
    printf("Unesite platu radnika: ");
    scanf(" %f", &radnik.plata);
    novi->zaposleni = radnik;
    novi->sledeci = lista;
    lista = novi;
    return lista;
}

int proveraJMBG(char jmbg1[13], char jmbg2[13]) {
    for(int i=0; i<13; i++) {
        if(jmbg1[i]==jmbg2[i]) {
            return true;
        }
    }
    return false;
}

void modifikacija(CVOR *lista) {
    char JMBG[13];
    printf("Unesite jmbg zaposlenog kome zelite promenite podatke: ");
    scanf(" %s", &JMBG);
    CVOR *tekuci;
    for(tekuci=lista; tekuci; tekuci=tekuci->sledeci) {
        if(proveraJMBG(JMBG, tekuci->zaposleni.jmbg)) {
            int izbor;
            do{
                printf("1.Ime prezime\n2.JMBG\n3.Plata\n4.Izlaz\n");
                printf("Unesite sta zelite da promenite: ");
                scanf(" %i", &izbor);
                switch(izbor){
                    case 1:
                        printf("Unesite novo ime i prezime: ");
                        scanf(" %[^\n]s", &tekuci->zaposleni.ime_prezime);
                        break;
                    case 2:
                        printf("Unesite novi JMBG: ");
                        scanf(" %s", &tekuci->zaposleni.jmbg);
                        break;
                    case 3:
                        printf("Unesite novi iznos za platu: ");
                        scanf(" %f", &tekuci->zaposleni.plata);
                        break;
                }
            }while(izbor>0 && izbor<4);
        }
    }
}
