#include <stdio.h>
#include <stdlib.h>

typedef struct knjiga{
    int brojStrana;
    char naziv[20];
}KNJIGA;

typedef struct node{
    KNJIGA knjiga;
    struct node *next;
}NODE;

NODE *push(KNJIGA, NODE *top);
NODE *pop(NODE *top);
void printStek(NODE *top);

int main() {
    printf("1.Unos knjiga u STEK\n2.Brisanje knjige sa vrha steka\n3.Ispisivanje knjige sa vrha steka\n");
    KNJIGA knjiga;
    NODE *top = NULL;
    int i;
    do{
        printf("\nUnesite izbor operacija: ");
        scanf(" %i", &i);
        switch(i) {
        case 1:
            printf("\nUnesite naziv knjige: ");
            scanf(" %s", &knjiga.naziv);
            printf("Unesite broj strana knjige: ");
            scanf(" %i", &knjiga.brojStrana);
            top = push(knjiga, top);
            printf("Stek sa knjigama:\n");
            printStek(top);
            break;
        case 2:
            top = pop(top);
            printf("\nObrisana je knjiga sa vrha steka.\n");
            printf("Stek sa knjigama:\n");
            printStek(top);
            break;
        case 3:
            if(top!=NULL){
                printf("\nKnjiga %s je na vrhu steka.\n", top->knjiga.naziv);
            }else{
                printf("Stek je prazan!!\n");
            }
            break;
        }
    }while(i>0 && i<4);
    return 0;
}

NODE *push(KNJIGA knjiga, NODE *top) {           /*dodajemo na pocetak odnosno vrh steka*/
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->knjiga = knjiga;
    newNode->next = top;
    top = newNode;
    return top;
}

NODE *pop(NODE *top) {      /*brisemo sa pocetka odnosno vrha steka*/
    NODE *temp = top;
    top = top->next;
    free(temp);
    return top;
}

void printStek(NODE *top) {
    NODE *temp;
    for(temp=top; temp; temp=temp->next) {
        printf("%s %i\n", temp->knjiga.naziv, temp->knjiga.brojStrana);
    }
}
