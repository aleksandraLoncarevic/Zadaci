#include <stdio.h>
#include <math.h>

int main() {
    float x;
    printf("Unesite broj x: ");
    scanf("%f", &x);
    printf("Resenje jednacine 5x^4-3x+15 za uneto x je %.2f.\n", 5*pow(x, 4)-3*x+15);
    return 0;
}
