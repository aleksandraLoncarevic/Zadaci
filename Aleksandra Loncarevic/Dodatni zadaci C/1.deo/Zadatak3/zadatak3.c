#include <stdio.h>
#include <math.h>

int main() {
    float const spcOtpornost = 1.55*pow(10, -8);
    float l;
    printf("Unesite duzinu provodnika u metrima: ");
    scanf(" %f", &l);
    float d;
    printf("Unesite precnik provodnika u milimetrima: ");
    scanf(" %f", &d);
    d = (float) d/1000; /*konvertujemo milimetre u metre*/
    float poprecniPresek = (float)(d*d*M_PI)/4;
    float otpornost = spcOtpornost * (float) (l/poprecniPresek);
    printf("Otpornost provodnika je %.15f.\n", otpornost);
    return 0;
}
