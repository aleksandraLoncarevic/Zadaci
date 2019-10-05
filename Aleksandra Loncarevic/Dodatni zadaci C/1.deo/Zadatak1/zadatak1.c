#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void pravougliTrougao(float a, float b);

int main() {
    float a,b;
    printf("1.Hipotenuza, obim i povrsina trougla\n2.Exit\n");
    int izbor;
    do{
        printf("\nUnesite izbor: ");
        scanf(" %i", &izbor);
        switch(izbor){
        case 1:
            printf("\nUnesite duzinu prve katete pravouglog trougla: ");
            scanf("%f", &a);
            printf("Unesite duzinu katete druge pravouglog trougla: ");
            scanf("%f", &b);
            pravougliTrougao(a, b);
            break;
        case 2:
            exit(0);
        }
    }while(izbor==1);
    return 0;
}

void pravougliTrougao(float a, float b) {
    float c = sqrt(a*a + b*b);
    printf("\nHipotenuza pravouglog trougla iznosi %.3f.\n", c);
    float povrsina = (a*b)/2;
    printf("Povrsina pravouglog trougla je %.3f.\n", povrsina);
    float obim = a + b + c;
    printf("Obim pravouglog trougla je %.3f.\n", obim);
}
