#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Unesite broj n: ");
    scanf("%i", &n);
    float pi=1;
    for(int i=2; i<=n; i++) {
        pi+= 1/pow(i,2);
    }
    pi = sqrt(6*pi);
    printf("Priblizna vrednost broja PI za unet broj %i je %f.", n, pi);
    return 0;
}
