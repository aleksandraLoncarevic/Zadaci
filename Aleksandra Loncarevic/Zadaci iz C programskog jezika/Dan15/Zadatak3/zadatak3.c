#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *sume;
int *matrica;
int pocetak, kraj, r, c;

void *ParcijalnoSabiranje(void *threadId){
    int tId = (int) threadId;
    sume[tId] = 0;
    printf("Nit %i. je izvrsila %i.parcijalno sabiranje.\n", tId+1, tId+1);
    for(int i=pocetak; i<=kraj; i++){
        sume[tId]+=*(matrica+(i%c)+(i/c)*c);    /*kada hocemo da prodjemo kroz matricu samo sa jednom for petljom
                                                  koristimo matrica[i%c][i/c] gde je c broj kolona*/
    }
    return sume[tId];
}

int main() {
    printf("Unesite broj vrsta i kolona matrice: ");
    scanf(" %i %i", &r, &c);
    matrica = (int*) calloc(r*c, sizeof(int));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("Unesite (%i, %i) element matrice: ", i+1, j+1);
            scanf(" %i", matrica+i*c+j);
        }
    }
    /*Ispis matrice*/
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
         printf("%d ", *(matrica + i*c + j));
      }
      printf("\n");
    }

    int brojSuma;
    printf("Unesite broj parcijalnih suma: ");
    scanf(" %i", &brojSuma);

    int brEl = (r*c)/brojSuma;
    sume = (int*)calloc(brojSuma, sizeof(int));
    pthread_t threads[brojSuma];
    int rc, suma;
    void *exit_status;
    int ukupnaSuma = 0;

    for(int i=0; i<brojSuma; i++){
        pocetak = i*brEl;
        kraj = pocetak+brEl-1;
        if(i==(brojSuma-1)){
            kraj = (r*c)-1;
        }
        printf("U main-u kreiramo %i.nit.\n", i+1);
        rc = pthread_create(&threads[i], NULL, ParcijalnoSabiranje, (void*) i);
        if(rc){
            printf("Greska pri kreiranju %i.niti!!!!\n", i+1);
            exit(-1);
        }
        pthread_join(threads[i], &exit_status);
        suma = (int) exit_status;
        printf("Suma %i.niti je %i.\n", i+1, suma);
        ukupnaSuma+=suma;
    }
    printf("Ukupna suma matrice je %i.\n", ukupnaSuma);
    return 0;
}
