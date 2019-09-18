#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define DUZINA 30

int main() {
    char *gradovi[MAX][DUZINA], grad[DUZINA];
    int brojGradova = 0, i;
    do{
        printf("Unesite grad: ");
        gets(grad);
        if(!strlen(grad)){
            break;
        }
        for(i=brojGradova-1; i>=0; i--) {
            if(strcmp(gradovi[i], grad)>0) {
                strcpy(gradovi[i+1], gradovi[i]);
            }else{
                break;
            }
        }
        strcpy(gradovi[i+1], grad);
    }while(++brojGradova<MAX);

    printf("\nUredjeni niz gradova:\n");
    for(int i=0; i<brojGradova; i++) {
        printf("%s\n", gradovi[i]);
    }
    return 0;
}

