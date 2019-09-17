#include <stdio.h>
#include <math.h>

int main() {
    float a;
    float b;
    printf("Unesite stranice trougla: ");
    scanf("%f %f", &a, &b);
    float c = sqrt(pow(a, 2) + pow(b, 2));
    printf("Hipotenuza trougla je %f.\n", c);
    return 0;
}
