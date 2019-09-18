#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct izlaz{
    char iskaz[6];
}IZLAZ;

double *ulaznaLista;
IZLAZ *izlaznaLista;
void *Ispisivanje(void *duzina);

int main() {
    int n;
    printf("Unesite velicinu ulazne liste: ");
    scanf(" %i", &n);

    ulaznaLista = (double*)calloc(n, sizeof(double));
    for(int i=0; i<n; i++) {
        printf("Unesite %i.element liste: ", i+1);
        scanf(" %lf", &ulaznaLista[i]);
    }

    izlaznaLista = (IZLAZ*)calloc(n, sizeof(IZLAZ));
    for(int i=0;i<n;i++){
        if(ulaznaLista[i]<=5){
            strcpy(izlaznaLista[i].iskaz,"FALSE");
        }else{
            strcpy(izlaznaLista[i].iskaz,"TRUE");
        }
    }
    pthread_t thread;
    int rc;
    rc = pthread_create(&thread, NULL, Ispisivanje, (void*) n);
    if(rc) {
        printf("Greska pri kreiranju niti!!!\n");
        exit(-1);
    }
    pthread_exit(NULL);
    return 0;
}

void *Ispisivanje(void *duzina) {
    int n;
    n = (int) duzina;
    printf("Ulazna lista:\n");
    for(int i=0; i<n; i++) {
        printf("%lf\t", ulaznaLista[i]);
    }
    printf("\nIzlazna lista:\n");
    for(int i=0; i<n; i++) {
        printf("%s\t", izlaznaLista[i].iskaz);
    }
    pthread_exit(NULL);
}
