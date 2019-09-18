#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct matrica{
        int i, j;
}MATRICA;

int n;
int *proizvod;
int *matrica1;
int *matrica2;
void *PomnoziMatrice(void* matrica);

int main() {
    FILE *file;
    file = fopen("matrice.txt", "r");

    fscanf(file, "%i", &n);

    matrica1 = (int*) calloc(n*n, sizeof(int));
    printf("Matrica 1:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            fscanf(file, "%i", matrica1+i*n+j);
            printf("%i ",  *(matrica1+i*n+j));
        }
        printf("\n");
    }

    matrica2 = (int*) calloc(n*n, sizeof(int));
    printf("\nMatrica 2:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            fscanf(file, "%i", matrica2+i*n+j);
            printf("%i ",  *(matrica2+i*n+j));
        }
        printf("\n");
    }

    proizvod = (int*)calloc(n*n, sizeof(int));
    MATRICA matrica[n*n];
    pthread_t threads[n*n];
    int rc;
    for(int i=0; i<(n*n); i++){
        matrica[i].i = i/n;
        matrica[i].j = i%n;
        rc = pthread_create(&threads[i], NULL, PomnoziMatrice, (void*)&matrica[i]);
        if(rc) {
            printf("Greska pri kreiranju niti!!!");
            exit(-1);
        }
    }
    for(int i=0; i<n*n; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nProizvod matrica:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%i ", *(proizvod+i*n+j));
        }
        printf("\n");
    }
    return 0;
}

void *PomnoziMatrice(void *matrica) {
    MATRICA *mat = (MATRICA*) matrica;
    int suma = 0;
    for(int k=0; k<n; k++) {
        suma+= *(matrica1+(mat->i)*n+k) * (*(matrica2+k*n+mat->j));
    }
    *(proizvod+(mat->i)*n+mat->j)=suma;
    return NULL;

}
