#include <stdio.h>
#include <math.h>

int main() {
    float r;
    float h;
    printf("Unesite poluprecnik i visinu kupe: ");
    scanf("%f %f", &r, &h);
    printf("Zapremina kupe iznosi %.3f.", (pow(r,2)*M_PI*h)/3);
    return 0;
}
