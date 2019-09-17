#include <stdio.h>

int main() {
    float a;
    float b;
    float c;
    printf("Unesite tri broja: ");
    scanf("%f %f %f", &a, &b, &c);
    float prosek = (a + b + c)/3;
    printf("Prosek uneta tri broja je %.3f\n", prosek);
    return 0;
}
