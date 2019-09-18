#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define ESC 27

typedef struct cvor{
    char osoba[20];
    struct node *next;
}NODE;

typedef struct queue{
    NODE *front, *rear;
}QUEUE;

QUEUE push(char *osoba, QUEUE queue);
QUEUE pop(QUEUE queue);

int main() {
    printf("Dodajte novu osobu u red- [a]\nIzbacite osobu iz reda - [d]\nIzadjite [0]\n");
    char c;
    char osoba[20];
    QUEUE queue = {NULL, NULL};
    do{
        printf("\nUnesite izbor: ");
        scanf(" %c", &c);
        switch(c){
        case 'a':
            printf("\nUnesite osobu: ");
            scanf(" %s", &osoba);
            queue = push(osoba, queue);
            printf("Trenutne osobe u redu su:\n");
            printQueue(queue);
            break;
        case 'd':
            printf("\nPosle izbacivanja:\n");
            queue = pop(queue);
            printQueue(queue);
            break;
        default:
            exit(1);
        }
    }while(c=='a' || c=='d');
    return 0;
}

QUEUE push(char *osoba, QUEUE queue) {               /*dodajemo osobe na kraj*/
    NODE *newNode = (NODE*) malloc(sizeof(NODE));
    strcpy(newNode->osoba, osoba);
    newNode->next = NULL;
    if(queue.front == NULL) {
        queue.front = newNode;
    }else{
        queue.rear->next = newNode;
    }
    queue.rear = newNode;
    printf("Nova osoba je usla u red.\n");
    return queue;
}

void printQueue(QUEUE queue) {
    NODE *tek;
    for(tek=queue.front; tek; tek=tek->next) {
        printf("%s\n", tek->osoba);
    }
    printf("\n");
}

QUEUE pop(QUEUE queue) {                /*brisemo osobe sa pocetka*/
    NODE *temp;
    if(queue.front == NULL) {
        printf("Red je prazan!!!");
    }else if(queue.front == queue.rear){
        queue.front = NULL;
        queue.rear = NULL;
    }else{
        temp = queue.front;
        queue.front = queue.front->next;
    }
    free(temp);
    return queue;
}
