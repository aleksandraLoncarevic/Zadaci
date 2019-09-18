#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int n;
int *niz1;
int *niz2;
sem_t mutex;
void *SkalarnoMnozenje(void *threadId);

int main(){
    char imeFajla[20];
    printf("Unesite ime fajla: ");
    scanf(" %s", &imeFajla);

    FILE *file;
    file = fopen(imeFajla, "r");

    fscanf(file, "%i", &n);

    niz1 = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n; i++) {
        fscanf(file, "%i", &niz1[i]);
    }

    niz2 = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n; i++) {
        fscanf(file, "%i", &niz2[i]);
    }

    fclose(file);
    pthread_t threads[n];
    void *rez;
    int proizvod;
    int ukupanZbir = 0;
    sem_init(&mutex, 0, 1);
    int rc;
    for(int i=0; i<n; i++){
        rc = pthread_create(&threads[i], NULL, SkalarnoMnozenje, (void*) i);
        if(rc){
            printf("Greska pri kreiranju niti!!!");
            exit(-1);
        }
    }

    for(int i=0; i<n; i++) {
        pthread_join(threads[i], &rez);
        proizvod = (int) rez;
        ukupanZbir+=proizvod;
        sem_post(&mutex);
    }
    sem_destroy(&mutex);
    printf("%i\n", ukupanZbir);
    return 0;
}

void *SkalarnoMnozenje(void *threadId) {
    sem_wait(&mutex);
    int tId = (int) threadId;
    int proizvod = 0;
    proizvod=niz1[tId]*niz2[tId];
    return (void*)proizvod;
}
