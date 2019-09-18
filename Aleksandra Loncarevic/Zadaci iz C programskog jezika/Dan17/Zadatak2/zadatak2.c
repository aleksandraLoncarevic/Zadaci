#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

typedef struct string{
    char slovo;
    struct string *next;
}String;

String *dodajNaKraj(String *head, char c);
void ispisiRec(String *head);
void *ProveraKaraktera(void *arg);
sem_t mutex;
String *tek1, *tek2;

int main() {
    char rec1[20], rec2[20];
    printf("Unesite string 1: ");
    scanf("%s", &rec1);
    char c1;
    String *head1 = NULL;
    for(int i=0; rec1[i]!='\0'; i++) {
        c1 = rec1[i];
        head1 = dodajNaKraj(head1, c1);
    }

    printf("\nUnesite string 2: ");
    scanf("%s", &rec2);
    char c2;
    String *head2 = NULL;
    for(int i=0; rec2[i]!='\0'; i++) {
        c2 = rec2[i];
        head2 = dodajNaKraj(head2, c2);
    }

    tek1 = head1;
    tek2 = head2;
    pthread_t thread;
    void *rez;
    sem_init(&mutex, 0, 1);
    while(tek1!=NULL && tek2!=NULL){
        pthread_create(&thread, NULL, ProveraKaraktera, NULL);
        pthread_join(thread, &rez);
        if(rez!=NULL) {
            printf("Prvi razlicit karakter drugog stringa je %c.\n", tek2->slovo);
            break;
        }
        tek1=tek1->next;
        tek2=tek2->next;
        sem_post(&mutex);
    }
    sem_destroy(&mutex);
    return 0;
}

String *dodajNaKraj(String *head, char c) {
    String *novi = (String*) malloc(sizeof(String));
    novi->slovo = c;
    novi->next = NULL;
    String *tek;
    if(head==NULL) {
        head = novi;
    }else{
        for(tek=head; tek->next; tek=tek->next);
        tek->next = novi;
    }
    return head;
}

void *ProveraKaraktera(void* arg) {
    sem_wait(&mutex);
    if(tek1->slovo==tek2->slovo){
        return NULL;
    }
    return (void*)tek2->slovo;
}
