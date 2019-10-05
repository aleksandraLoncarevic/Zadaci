#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float poluprecnikMnogougla(int n, float a);
float povrsinaMnogougla(int n, float a, float r);

int main() {
    int n;
    float a;
    printf("1.Povrsina mnogougla\n2.Exit\n");
    int izbor;
    do{
        printf("\nUnesite izbor: ");
        scanf(" %i", &izbor);
        switch(izbor) {
        case 1:
            printf("\nUnesite broj stranica pravilnog mnogougla mnogougla: ");
            scanf(" %i", &n);
            printf("Unesite duzinu stranice pravilnog mnogougla: ");
            scanf(" %f", &a);
            float r = poluprecnikMnogougla(n, a);
            printf("Poluprecnik opisane kruznice pravilnog mnogougla je %.3f.\n", r);
            float p = povrsinaMnogougla(n, a, r);
            printf("Povrsina mnogougla je %.3f.\n", p);
            break;
        case 2:
            exit(0);
        }
    }while(izbor==1);
    return 0;
}


float poluprecnikMnogougla(int n, float a) {
    float alfa = (float) 360/n;
    float beta = (float) (180 - alfa)/2;
    float betaRad = beta * (M_PI/180); /*posto funkcija tan radi sa radijanima ovde konvertujemo stepene u radijane*/
    float r = tan(betaRad) * (a/2);
    return r;
}

float povrsinaMnogougla(int n, float a, float r) {
    float povrsina = (float) (n * a *r)/2;
    return povrsina;
}
