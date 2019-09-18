#include <stdio.h>

void prostiBrojeviNiza(int *niz, int n);

int main() {
    int n;
    printf("Unesite velicinu niza: ");
    scanf(" %i", &n);
    int niz[n];
    for(int i=0; i<n; i++) {
        printf("Unesite %i.element niza: ", i+1);
        scanf(" %i", &niz[i]);
    }
    prostiBrojeviNiza(niz, n);
    return 0;
}

int prost(int m) {
    if(m>1) {
        int suma = 0;
        for(int i=2; i<=m/2; i++) {
            if(m%i!=0) {
                suma+=0;
            } else {
                suma+=1;
            }
        }
        if(suma==0) {   /*ako broj ne bude deljiv nijednim brojem od 2 do m/2 zbir ce biti 0*/
            return 1;   /*inace ako budem deljiv bar jednim brojem od 2 do m/2 zbir ce biti bar 1*/
        }
    }
    return 0;
}

void prostiBrojeviNiza(int *niz, int n) {
    for(int i=0; i<n; i++) {
        if(prost(niz[i])) {
            printf("%i\t", niz[i]);
        }
    }
}

