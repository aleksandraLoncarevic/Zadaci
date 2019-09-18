#include <stdio.h>
#include <stdlib.h>

typedef struct cvor{
    int broj;
    struct cvor *sledeci;
}CVOR;

CVOR *listaParnihBrojeva(CVOR *prvi);
CVOR *listaCelihBrojeva(CVOR *prvi);
void ispisiListu(CVOR *prvi);
CVOR *oslobodiMemoriju(CVOR *prvi);

int main() {
    printf("**OPERACIJE**\n");
    printf("1)Unos celih brojeva u jednostruko spregnutu listu(dok se ne unese 0)\n"
           "2) Formirati novu listu koja sadrži sve parne brojeve iz liste celih brojeva.\n\n");

    CVOR *prvi = NULL;
    CVOR *parniBrojevi = NULL;
    int izbor;
    do{
        printf("\nUnesite izbor: ");
        scanf(" %i", &izbor);
        switch(izbor) {
        case 1:
            if(prvi==NULL) {
                prvi = listaCelihBrojeva(prvi);
                printf("Lista celih brojeva\n-------------------\n");
                ispisiListu(prvi);
                printf("\n");
            }else{
                prvi = oslobodiMemoriju(prvi);
                prvi = listaCelihBrojeva(prvi);
                printf("Lista celih brojeva\n-------------------\n");
                ispisiListu(prvi);
                printf("\n");
            }
            break;
        case 2:
            if(parniBrojevi == NULL){
                printf("Lista parnih brojeva\n---------------------\n");
                parniBrojevi = listaParnihBrojeva(prvi);
                ispisiListu(parniBrojevi);
                printf("\n");
            }else{
                parniBrojevi = oslobodiMemoriju(parniBrojevi);
                printf("Lista parnih brojeva\n---------------------\n");
                parniBrojevi = listaParnihBrojeva(prvi);
                ispisiListu(parniBrojevi);
                printf("\n");
            }
            break;
        default:
            printf("Ne postoji operacija koju ste uneli!!!");
        }
    }while(izbor>0 && izbor<3);
    return 0;
}

CVOR *dodajElementeNeopadajuce(CVOR *prvi, int b) {
    CVOR *tek = prvi;
    CVOR *prethodni = NULL;
    while(tek && tek->broj<b) {
        prethodni = tek;
        tek = tek->sledeci;
    }
    CVOR *novi = malloc(sizeof(CVOR));
    novi->broj = b;
    novi->sledeci = tek;
    if(prethodni==NULL) {
        prvi = novi;
    }else{
        prethodni->sledeci = novi;
    }
    return prvi;
}

void ispisiListu(CVOR *prvi) {
    CVOR *tek;
    for(tek=prvi; tek; tek=tek->sledeci) {
        printf("%i ", tek->broj);
    }
}

CVOR *listaCelihBrojeva(CVOR *prvi) {
    int n;
    do{
        printf("Unesite ceo broj: ");
        scanf(" %i", &n);
        if(n!=0) {
            prvi = dodajElementeNeopadajuce(prvi, n);
        }
    }while(n!=0);
    return prvi;
}

CVOR *listaParnihBrojeva(CVOR *prvi) {
    CVOR *parniBrojevi = NULL;
    CVOR *tek;
    for(tek=prvi; tek; tek=tek->sledeci) {
        if(tek->broj%2 == 0) {
            parniBrojevi = dodajElementeNeopadajuce(parniBrojevi, tek->broj);
        }
    }
    return parniBrojevi;
}

CVOR *oslobodiMemoriju(CVOR *prvi) {
    CVOR *stari;
    while(prvi) {
        stari = prvi;
        prvi=prvi->sledeci;
        free(stari);
    }
    return prvi;
}
