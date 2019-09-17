#include <stdio.h>

int main() {
    int a;
    int b;
    printf("Unesite stranice pravougaonika: ");
    scanf("%d %d", &a, &b);
    printf("Obim pravougaonika je %d.\n", 2*a+2*b);
    printf("Povrsina pravougaonika je %d.\n", a*b);
    return 0;
}
