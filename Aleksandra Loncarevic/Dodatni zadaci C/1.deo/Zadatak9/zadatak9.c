#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("1.Resenja kvadratne jednacine\n2.Exit\n");
    int izbor;
    float a, b, c;
    do{
        printf("\nUnesi izbor:");
        scanf(" %i", &izbor);
        switch(izbor) {
        case 1:
            printf("\nUnesite koeficijent a jednacine ax^2+bx+c=0: ");
            scanf(" %f", &a);
            printf("Unesite koeficijent b jednacine ax^2+bx+c=0: ");
            scanf(" %f", &b);
            printf("Unesite koeficijent c jednacine ax^2+bx+c=0: ");
            scanf(" %f", &c);
            if(a==0) {
                float x = (float) -c/b;
                printf("Imamo linearnu jednacinu %.2fx+%.2f=0 cije resenje je %.3f.\n", b, c, x);
            }else{
                float diskriminanta = b*b-4*a*c;
                if(diskriminanta<0) {
                    float xRe = (float) -b/(2*a);
                    float xIm = (float)sqrt(-1*diskriminanta)/(2*a);
                    printf("Jednacina ima kompleksna resenja.\nx = %.2f + %.2fi\ny = %.2f - %.2fi\n", xRe, xIm, xRe, xIm);
                }else if(diskriminanta==0) {
                    float x = (float) -b/(2*a);
                    printf("Jednacina ima samo jedno realno resenje, a to je %.3f.", x);
                }else{
                    float x = (float) (-b+sqrt(diskriminanta))/(2*a);
                    float y = (float) (-b-sqrt(diskriminanta))/(2*a);
                    printf("Jednacina ima dva realna resenja, x = %.3f i y=%.3f\n", x, y);
                }
            }
            break;
        case 2:
            exit(0);
        }
    }while(izbor==1);
    return 0;
}
