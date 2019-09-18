#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int *a;
int *b;
int *c;

void *Saberi(void *threadId) {
    int tId;
    tId = (int) threadId;
    printf("Nit %i je sabrala %i.elemente niza an i bn.\n", tId+1, tId+1);
    c[tId] = a[tId]+b[tId];
    printf("%i.element niza cn je %i.\n", tId+1, c[tId]);
    pthread_exit(NULL);
}

int main() {
    int n;
    printf("Unesite velicinu niza: ");
    scanf(" %i", &n);

    a = calloc(n, sizeof(int));
    for(int i=0; i<n; i++) {
        printf("Unesite %i.element niza an: ", i+1);
        scanf(" %i", &a[i]);
    }
    printf("\n");

    b = calloc(n, sizeof(int));
    for(int i=0; i<n; i++) {
        printf("Unesite %i.element niza bn: ", i+1);
        scanf(" %i", &b[i]);
    }

    c = calloc(n, sizeof(int));
    pthread_t threads[n];
    int rc;
    for(int i=0; i<n; i++){
        printf("U mainu-u kreiramo nit %i.\n", i+1);
        rc = pthread_create(&threads[i], NULL, Saberi, (void*)i);
        if(rc) {
            printf("Greska pri kreiranju niti!!\n");
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}
