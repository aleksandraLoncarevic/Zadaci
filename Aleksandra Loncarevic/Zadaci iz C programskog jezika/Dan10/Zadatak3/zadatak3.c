#include <stdio.h>
#include <stdlib.h>

typedef struct fudbaler{
    float plata;
    int id;
    int idKluba;
    char imePrezime[100];
}FUDBALER;

typedef struct cvor{
    FUDBALER fudbaler;
    struct cvor *sledeci, *prethodni;
}CVOR;

typedef struct lista{
    CVOR *prvi, *poslednji;
}LISTA;

LISTA unosFudbalera(LISTA head, FUDBALER fudbaler, int n);
void ispis(LISTA head);
LISTA izbaciSaNajvecomPlatom(LISTA head);
LISTA izbaciSaNajmanjomPlatom(LISTA head);
int brojFudbaleraSaNajvecomPlatom(LISTA head);
int brojFudbaleraSaNajmanjomPlatom(LISTA head);

int main() {
    LISTA head = {NULL, NULL};
    FUDBALER fudbaler;
    int n;
    printf("Unesite koliko zelite fudbalera da dodate u bazu: ");
    scanf(" %i", &n);

    head = unosFudbalera(head, fudbaler, n);
    ispis(head);

    int brojFudb1 = brojFudbaleraSaNajvecomPlatom(head);
    for(int i=0; i<brojFudb1; i++) {
        head = izbaciSaNajvecomPlatom(head);
    }
    printf("Nakon izbacivanja fudbalera sa najvecom platom:\n");
    ispis(head);

    int brojFudb2 = brojFudbaleraSaNajmanjomPlatom(head);
    for(int i=0; i<brojFudb2; i++) {
        head = izbaciSaNajmanjomPlatom(head);
    }
    printf("Nakon izbacivanja fudbalera sa najmanjom platom:\n");
    ispis(head);
}

LISTA unosFudbalera(LISTA head, FUDBALER fudbaler, int n) {
    for(int i=0; i<n; i++) {
        printf("Unesite sifru %i.fudbalera: ", i+1);
        scanf(" %i", &fudbaler.id);
        printf("Unesite ime i prezime %i.fudbalera: ", i+1);
        scanf(" %[^\n]s", &fudbaler.imePrezime);
        printf("Unesite sifru kluba za koji igra %i.fudbaler: ", i+1);
        scanf(" %i", &fudbaler.idKluba);
        printf("Unesite platu %i.fudbalera: ", i+1);
        scanf(" %f", &fudbaler.plata);
        printf("\n");

        CVOR *novi = malloc(sizeof(CVOR));
        novi->fudbaler = fudbaler;
        if(head.prvi == NULL) {  /*ako je lista prazna*/
            head.prvi = novi;
            head.poslednji = novi;
            novi->sledeci = NULL;
            novi->prethodni = NULL;
        }
        if(novi->fudbaler.plata >= head.prvi->fudbaler.plata) {  //ako je plata novog fudbalera veca od plate prvog fudbalera
            CVOR *pom1 = head.prvi;                             //u listi, dodajemo na pocetak
            novi->sledeci = pom1;
            pom1->prethodni = novi;
            novi->prethodni = NULL;
            head.prvi = novi;
        }else if(novi->fudbaler.plata <= head.poslednji->fudbaler.plata) { //ako je plata novog fudbalera manja od plate
            CVOR *pom2 = head.poslednji;                                  // poslednjeg fudbalera, dodajemo na kraj
            novi->prethodni = pom2;
            pom2->sledeci = novi;
            novi->sledeci = NULL;
            head.poslednji = novi;
        }else {
            CVOR *tek = head.prvi; /*Dodavanje na odredjeno mesto*/
            while(tek->fudbaler.plata > fudbaler.plata) {
                tek = tek->sledeci;
            }
            CVOR *pret = tek->prethodni;
            novi->sledeci = tek;
            tek->prethodni = novi;
            novi->prethodni = pret;
            pret->sledeci = novi;
        }
    }
    return head;
}

LISTA izbaciSaNajvecomPlatom(LISTA head) {
    CVOR *tek1 = head.prvi;
    head.prvi = tek1->sledeci;
    head.prvi->prethodni = NULL;
    free(tek1);
    return head;
}

LISTA izbaciSaNajmanjomPlatom(LISTA head) {
    CVOR *tek2 = head.poslednji;
    head.poslednji = tek2->prethodni;
    head.poslednji->sledeci = NULL;
    free(tek2);
    return head;
}

void ispis(LISTA head) {
    CVOR *tek;
    for(tek = head.prvi; tek; tek=tek->sledeci) {
        printf("%i %s %i %f\n", tek->fudbaler.id, tek->fudbaler.imePrezime, tek->fudbaler.idKluba, tek->fudbaler.plata);
    }
    printf("\n");
}

int brojFudbaleraSaNajvecomPlatom(LISTA head) {  /*ovde brojimo da li postoji vise fudbalera sa istom najvecom platom*/
    CVOR *tek;
    int brojac = 1;
    for(tek=head.prvi->sledeci; tek; tek=tek->sledeci){
        if(tek->fudbaler.plata == head.prvi->fudbaler.plata) {
            brojac++;
        }
    }
    return brojac;
}

int brojFudbaleraSaNajmanjomPlatom(LISTA head) {
    CVOR *tek;
    int brojac = 1;
    for(tek=head.poslednji->prethodni; tek; tek=tek->prethodni){
        if(tek->fudbaler.plata == head.poslednji->fudbaler.plata) {
            brojac++;
        }
    }
    return brojac;
}
