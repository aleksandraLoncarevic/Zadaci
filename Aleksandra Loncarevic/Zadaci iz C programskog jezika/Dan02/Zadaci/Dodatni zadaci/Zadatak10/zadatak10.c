#include <stdio.h>
#include <math.h>

int main() {
    float a, b;
    float ugao;
    printf("Unesite dve stranice trougla: ");
    scanf("%f %f", &a, &b);
    printf("Unesite ugao izmedju unetih stranica: ");
    scanf("%f", &ugao);
    /*Posto funkcija cos iz biblioteke math.h radi sa radijanima a mi unosimo stepene, ovde sam  to konvertovala*/
    ugao = (M_PI/180) * ugao;
    float c = sqrt(pow(a, 2) + pow(b ,2) - 2*a*b*cos(ugao));
    printf("Treca stranica iznosi %f.\n", c);
    return 0;
}
