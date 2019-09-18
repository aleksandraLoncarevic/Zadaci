#include <stdio.h>

void prostiBrojevi(int);

int main() {
    int broj;
    printf("Unesite broj: ");
    scanf(" %i", &broj);
    prostiBrojevi(broj);
    return 0;
}

int prost(int m) {
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
    return 0;
}

void prostiBrojevi(int m) {
    printf("Svi prosti brojevi do broja %i su: \n", m);
    for(int i=2; i<=m; i++) {
        if(prost(i)==1) {
            printf("%i\n", i);
        }
    }
}
