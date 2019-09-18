#include <stdio.h>

int prost(int);

int main() {
    int broj;
    printf("Unesite broj: ");
    scanf(" %i", &broj);
    if(prost(broj)==1) {
        printf("Broj %i je prost!!!\n", broj);
    } else {
        printf("Broj %i nije prost!!!\n", broj);
    }
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
