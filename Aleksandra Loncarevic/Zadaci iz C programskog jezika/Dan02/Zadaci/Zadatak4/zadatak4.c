#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, z1;
    float x2, y2, z2;
    printf("Unesite koordinate prve tacke <x1, y1, z1>: ");
    scanf("%f %f %f", &x1, &y1, &z1);
    printf("Unesite koordinate druge tacke <x2, y2, z2>: ");
    scanf("%f %f %f", &x2, &y2, &z2);
    float rastojanje = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2) + pow((z1-z2), 2));
    printf("Rastojanje izmedju tacaka je %f.\n", rastojanje);
    return 0;
}
