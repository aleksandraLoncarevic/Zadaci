#include <stdio.h>
#include <math.h>

int main() {
    int a;
    int b;
    printf("Unesite prirodne brojeve a i b: ");
    scanf("%i %i", &a, &b);
    int n = 1;
    while(pow(3, n)+a*n<=b) {
        n++;
    }
    printf("Najmanji prirodan broj n je %i.\n", n);
    return 0;
}
