#include <stdio.h>
#include <conio.h>

void popunjavanje_niza(int *niz, int);
void sortirajNiz(int *niz, int);


int main() {
    int n;
    printf("Unesite broj elemenata niza: ");
    scanf(" %i", &n);
    int niz[n];
    popunjavanje_niza(niz, n);
    return 0;
}

void sortirajNiz(int *niz, int n) {
    for(int j=1; j<n; j++) {
        for(int i=0; i<j; i++) {
            if(niz[i]<niz[j]) {
                int temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
}

void popunjavanje_niza(int* niz, int br_elemenata) {
    int i;
    for(i=0;i<br_elemenata;i++) {
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

        if(broj>0){
            niz[i]=broj;
        if(i>0){
            sortirajNiz(niz,i+1);
        }
        }
        else
             break;
    }
    br_elemenata = i;
    printf("Sadrzaj niza:\n");
    for(int i=0; i<br_elemenata; i++) {
        printf(" %i\t", niz[i]);
    }
}

