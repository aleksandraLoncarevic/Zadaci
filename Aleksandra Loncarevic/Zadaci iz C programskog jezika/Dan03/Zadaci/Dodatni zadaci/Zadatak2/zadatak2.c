#include <stdio.h>

int main() {
    int x;
    int y;
    printf("Unesite dva cela broja: ");
    scanf("%i %i", &x, &y);
    for(int i=x; i<=y; i+=2) {
        printf("%i\n", i);
    }
    return 0;
}
