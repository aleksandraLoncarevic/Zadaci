#include <stdio.h>
#include <math.h>

int main() {
    float const E0 = 8.85 * pow(10, -12);
    float R;
    printf("Unesite poluprecnik kruzne ploce obloge kondezatora u milimetrima: ");
    scanf(" %f", &R);
    R = (float) R/1000;
    float d;
    printf("Unesite rastojaje izmedju obloga kondezatora u milimetrima: ");
    scanf(" %f", &d);
    d = (float) d/1000;
    float Er;
    printf("Unesite relativnu dielektricnu konstantu izolatora koja se nalazi izmedju dva kondezatora: ");
    scanf(" %f", &Er);
    float poprPresek = R*R*M_PI;
    float kapacitet = Er * E0 * (float)(d/poprPresek);
    printf("Kapacitet plocastog kondezatora je %.20f.\n", kapacitet);
    return 0;
}
