#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct racun{
    float iznos;
    int broj;
    int indikator;
    char primalac[30];
    char uplatilac[30];
} RACUN;

typedef struct cvor{
    RACUN racun;
    struct cvor *sledeci;
}CVOR;

CVOR *dodajNaKraj(CVOR* prvi, RACUN racun);
void ispisRacuna(CVOR *prvi);
void izaberi();
void testPodaci();

int main() {
    testPodaci();
    return 0;
}

void testPodaci() {
    int izbor;
    printf("Unesite 1 ako zelite da bazu popunite test podacima, 0 ako ne zelite: ");
    scanf(" %i", &izbor);
    CVOR *prvi = NULL;
    if(izbor) {
            /*TEST PODACI*/
        RACUN racun1;
        racun1.broj=1;
        strcpy(racun1.primalac, "PMF");
        strcpy(racun1.uplatilac, "Aleksandra");
        racun1.iznos=10000.00;
        racun1.indikator=1;
        prvi = dodajNaKraj(prvi, racun1);

        RACUN racun2;
        racun2.broj=2;
        strcpy(racun2.primalac, "FTN");
        strcpy(racun2.uplatilac, "Marko");
        racun2.iznos=15000.00;
        racun2.indikator=0;
        prvi = dodajNaKraj(prvi, racun2);

        RACUN racun3;
        racun3.broj=3;
        strcpy(racun3.primalac, "SBB");
        strcpy(racun3.uplatilac, "Petar");
        racun3.iznos=3300.00;
        racun3.indikator=0;
        prvi = dodajNaKraj(prvi, racun3);

        RACUN racun4;
        racun4.broj=4;
        strcpy(racun4.primalac, "Intesa");
        strcpy(racun4.uplatilac, "Aleksa");
        racun4.iznos=5000.00;
        racun4.indikator=1;
        prvi = dodajNaKraj(prvi, racun4);

        RACUN racun5;
        racun5.broj=5;
        strcpy(racun5.primalac, "Informatika");
        strcpy(racun5.uplatilac, "Pavle");
        racun5.iznos=6000.00;
        racun5.indikator=0;
        prvi = dodajNaKraj(prvi, racun5);

        izaberi(prvi);
    }
    izaberi(prvi);
}

CVOR *dodajNaKraj(CVOR *prvi, RACUN racun) {
    CVOR *tekuci;
    CVOR *novi = malloc(sizeof(CVOR));
    novi->racun = racun;
    novi->sledeci = NULL;
    if(!prvi){
        prvi = novi;
    }else{
        for(tekuci=prvi; tekuci->sledeci; tekuci=tekuci->sledeci);
        tekuci->sledeci=novi;
    }
    return prvi;
}

void ispisRacuna(CVOR *prvi) {
    CVOR *tekuci;
    for(tekuci=prvi; tekuci; tekuci=tekuci->sledeci) {
        printf("%i %s %s %f %i\n", tekuci->racun.broj, tekuci->racun.uplatilac, tekuci->racun.primalac, tekuci->racun.iznos, tekuci->racun.indikator);
    }
}

RACUN noviRacun(RACUN racun) {
    printf("\nUnesite broj racuna: ");
    scanf(" %i", &racun.broj);
    printf("Unesite uplatioca racuna: ");
    scanf(" %s", &racun.uplatilac);
    printf("Unesite primaoca racuna: ");
    scanf(" %s", &racun.primalac);
    printf("Unesite iznos koji uplacujete: ");
    scanf(" %f", &racun.iznos);
    printf("Unesite 1 ako je racun placen, 0 ako nije: ");
    scanf(" %i", &racun.indikator);
    return racun;
}

int  placanjePostojecegRacuna(int brojRacuna, CVOR *prvi) {
    CVOR *tekuci;
    for(tekuci=prvi; tekuci; tekuci=tekuci->sledeci) {
        if(tekuci->racun.broj==brojRacuna && tekuci->racun.indikator==0) {
            tekuci->racun.indikator = 1;
            return 1;
        }
    }
    return 0;
}

void ispisRacunaZaUnetogPrimaoca(CVOR *prvi, char *primalac) {
    CVOR *tekuci;
    for(tekuci=prvi; tekuci; tekuci=tekuci->sledeci) {
        if(strcmp(tekuci->racun.primalac, primalac)==0) {
            printf("%i %s %s %f %i\n", tekuci->racun.broj, tekuci->racun.uplatilac, tekuci->racun.primalac, tekuci->racun.iznos, tekuci->racun.indikator);
        }
    }
}

void ispisRacuneKojiNisuPlaceni(CVOR *prvi) {
    CVOR *tekuci;
    for(tekuci=prvi; tekuci; tekuci=tekuci->sledeci) {
        if(tekuci->racun.indikator==0) {
            printf("%i %s %s %f %i\n", tekuci->racun.broj, tekuci->racun.uplatilac, tekuci->racun.primalac, tekuci->racun.iznos, tekuci->racun.indikator);
        }
    }
}

CVOR *brisiRacun(CVOR *prvi, int brojRacuna) {
    CVOR *tekuci = prvi;
    CVOR *prethodni = NULL, *stari;
    while(tekuci) {
        if(tekuci->racun.broj!=brojRacuna) {
            prethodni=tekuci;
            tekuci=tekuci->sledeci;
        }else {
            stari=tekuci;
            tekuci=tekuci->sledeci;
            if(!prethodni) {
                prvi=tekuci;
            }else{
                prethodni->sledeci=tekuci;
            }
            free(stari);
        }
        return prvi;
    }
}

CVOR *brisiListu(CVOR *prvi) {
    CVOR *stari;
    while(prvi) {
        stari=prvi;
        prvi=prvi->sledeci;
        free(stari);
    }
    printf("Lista je obrisana!!!\n");
    return prvi;
}

void izaberi(CVOR *prvi) {
    RACUN racun;
    printf("\n***BAZA RACUNA***\n");
    printf("1. Dodavanje novog racuna\n2. Placanje postojeceg racuna.\n3. Brisanje racuna sa odredjenim brojem racuna.\n"
            "4. Prikaz podataka racuna sa unetim nazivom primaoca.\n5. Prikaz svih racuna koji nisu placeni.\n"
            "6. Prikaz svih racuna u bazi.\n7. Brisanje svih racuna u bazi.\n8. Izlaz iz programa.\n");
    int izbor;
    int brojRacuna;
    char primalac[20];
    do{
        printf("\nIzaberite sta zelite(1-8): ");
        scanf(" %i", &izbor);
        switch(izbor) {
            case 1:
                racun = noviRacun(racun);
                prvi = dodajNaKraj(prvi, racun);
                break;
            case 2:
                printf("\nUnesite racun koji zelite da platite: ");
                scanf(" %i", &brojRacuna);
                int placanje = placanjePostojecegRacuna(brojRacuna, prvi);
                if(placanje==1) {
                    printf("Racun je placen!\n");
                }else{
                    printf("Racun ne postoji u bazi ili je placen vec!!!\n");
                }
                break;
            case 3:
                printf("\nUnesite broj racuna koji zelite da obrisete: ");
                scanf(" %i", &brojRacuna);
                prvi = brisiRacun(prvi, brojRacuna);
                break;
            case 4:
                printf("\nUnesite primaoca cije podatke racuna zeilte da ispisete: ");
                scanf(" %s", &primalac);
                ispisRacunaZaUnetogPrimaoca(prvi, primalac);
                break;
            case 5:
                printf("\nRacuni koji nisu placeni:\n");
                ispisRacuneKojiNisuPlaceni(prvi);
                break;
            case 6:
                ispisRacuna(prvi);
                break;
            case 7:
                prvi=brisiListu(prvi);
                testPodaci();
                break;
            case 8:
                exit(1);
        }
    }while(izbor>0 && izbor<9);
}

