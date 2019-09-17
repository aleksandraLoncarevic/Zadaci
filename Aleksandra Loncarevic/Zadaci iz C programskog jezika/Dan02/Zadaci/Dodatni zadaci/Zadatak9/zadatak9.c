#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1;
    printf("Unesite koordinate prve tacke: ");
    scanf("%f %f", &x1, &y1);
    float x2, y2;
    printf("Unesite koordinate druge tacke: ");
    scanf("%f %f", &x2, &y2);
    float rastojanje = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
    printf("Rastojanje izmedju tacaka je %.3f.\n", rastojanje);
    return 0;
}
