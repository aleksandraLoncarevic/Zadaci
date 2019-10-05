#include <stdio.h>
#include <stdlib.h>

float koeficijentK(int a, int b);
float koeficijentN(int b, int c);
float presecnaTackaX(int, int, int, int, int, int);
float presecnaTackaY(int, int, int, int, int, int);

int main() {
    printf("1.Odnos izmedju dve prave\n2.Exit\n\n");
    int izbor;
    float a1, b1, c1;
    float a2, b2, c2;
    do{
        printf("\nUnesite izbor:");
        scanf(" %i", &izbor);
        switch(izbor) {
        case 1:
            printf("\nUnesite koeficijent a prve prave ax+by=c: ");
            scanf(" %f", &a1);
            printf("Unesite koeficijent b prve prave ax+by=c: ");
            scanf(" %f", &b1);
            printf("Unesite koeficijent c prve prave ax+by=c: ");
            scanf(" %f", &c1);
            printf("\nUnesite koeficijent a druge prave ax+by=c: ");
            scanf(" %f", &a2);
            printf("Unesite koeficijent b druge prave ax+by=c: ");
            scanf(" %f", &b2);
            printf("Unesite koeficijent c druge prave ax+by=c: ");
            scanf(" %f", &c2);
            float k1 = koeficijentK(a1, b1);
            float n1 = koeficijentN(b1, c1);
            float k2 = koeficijentK(a2, b2);
            float n2 = koeficijentN(b2, c2);
            if(k1==k2 && n1==n2) {
                printf("Prave se poklapaju.\n");
            }else if(k1==k2) {
                printf("Prave su paralelne.\n");
            }else{
                float x = presecnaTackaX(a1, b1, c1, a2, b2, c2);
                float y = presecnaTackaY(a1, b1, c1, a2, b2, c2);
                printf("Prave se seku. Tacka preseka je (%.2f,%.2f).\n", x, y);
            }
            break;
        case 2:
            exit(0);
        }
    }while(izbor==1);
    return 0;
}

float koeficijentK(int a, int b) {
    return (float)-a/b;
}

float koeficijentN(int b, int c) {
    return (float)-c/b;
}

float presecnaTackaX(int a1, int b1, int c1, int a2, int b2, int c2) {
    return (float)(c1*b2-b1*c2)/(a1*b2-b1*a2);
}

float presecnaTackaY(int a1, int b1, int c1, int a2, int b2, int c2) {
    return (float)(a1*c2-c1*a2)/(a1*b2-b1*a2);
}
