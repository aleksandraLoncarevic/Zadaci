#include <stdio.h>

void popunjavanje_niza(int* niz, int br_elemenata);
void sortirajNiz(int* niz, int n);
int jednakiSkupovi(int *niz1, int, int *niz2, int);

int main() {
    int n1;
    printf("Unesite broj elemenata skupa S1: ");
    scanf(" %i", &n1);
    int S1[n1];
    popunjavanje_niza(S1, n1);
    sortirajNiz(S1, n1);

    int n2;
    printf("Unesite broj elemenata skupa S1: ");
    scanf(" %i", &n2);
    int S2[n2];
    popunjavanje_niza(S2, n2);
    sortirajNiz(S2, n2);

    int jednaki = jednakiSkupovi(S1, n1, S2, n2);
    if(jednaki == 1) {
        printf("Skupovi su jednaki!");
    } else {
        printf("Skupovi nisu jednaki!");
    }
    return 0;
}

void popunjavanje_niza(int* niz, int br_elemenata) {
    for(int i=0;i<br_elemenata;i++) {
        int ima_broj=0;
        int broj=0;
        do{
         broj=0;
         printf("Unesite %d. element niza: ", i+1);
         scanf(" %d", &broj);
         ima_broj=0;
         for(int j=0;j<i;j++){
             if(niz[j]==broj){
                 ima_broj=1;
             }
         }
        }while(ima_broj==1);
        niz[i]=broj;
    }
}

void sortirajNiz(int *niz, int n) {
    for(int j=1; j<n; j++) {
        for(int i=0; i<j; i++) {
            if(niz[i]>niz[j]) {
                int temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
}

int jednakiSkupovi(int *niz1, int n1, int *niz2, int n2) {
    if(n1>n2 || n2>n1) {
        return 0;
    }else{
        for(int i=0, j=0; i<n1, j<n2; i++, j++) {
            if(niz1[i]!=niz2[j]) {
                return 0;
            }
        }
    }
    return  1;
}
