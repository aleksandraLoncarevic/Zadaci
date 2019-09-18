#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct node {
    int playerId;
    char firstName[MAX];
    char lastName[MAX];
    int points;
    struct node *next;
} NODE;

int main () {
    NODE *head = NULL, *last = NULL, *newNode, *current;
    FILE *input1, *input2, *izlaz;

    int playerId, pointsToDefend, pointsWon, points;
    char firstName[MAX], lastName[MAX];

    if ((input1 = fopen("teniseri.txt","r")) == NULL) {
        printf("Greska u otvaranju ulazne datocurrente teniseri.txt!");
        exit(1);
    }
    if ((input2 = fopen("wimbledon.txt","r")) == NULL) {
        printf("Greska u otvaranju ulazne datocurrente wimbledon.txt!");
        exit(1);
    }
    if ((izlaz = fopen("atplista.txt","w")) == NULL) {
        printf("Greska u otvaranju izlazne datocurrente atplista.txt!");
        exit(4);
    }

    while(fscanf(input1, "%d %s %s %d", &playerId, firstName, lastName, &points)!=EOF) {
        if ((newNode = malloc(sizeof(NODE))) == NULL) {
            printf("Greska u alociranju memorije!");
            exit(3);
        }
        newNode->next = NULL;
        newNode->points = points;
        newNode->playerId = playerId;
        strcpy(newNode->firstName, firstName);
        strcpy(newNode->lastName, lastName);
        if (head == NULL){
            head = newNode;
        }else{
            last->next = newNode;
        }
        last = newNode;
    }

    while(fscanf(input2, "%d %d %d", &playerId, &pointsToDefend, &pointsWon)!=EOF) {
        current = head;
        while (current != NULL && current->playerId != playerId){
            current = current->next;
        }
        if (current != NULL){
            current->points += (pointsWon - pointsToDefend);
        }
    }

    current = head;
    while (current != NULL) {
        fprintf(izlaz,"%d %s %s %d\n", current->playerId, current->firstName, current->lastName, current->points);
        current = current->next;
    }

    current = head;
    while (current != NULL) {
        last = current;
        current = current->next;
        free(last);
    }

    fclose(input1);
    fclose(input2);
    fclose(izlaz);
    return 0;
}
