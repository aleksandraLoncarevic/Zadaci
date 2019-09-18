#include <stdio.h>

int main() {
    int n;
    printf("Unesite ceo broj: ");
    scanf("%d", &n);
    if(n>0) {
        printf("Apsolutna vrednost broja je %d.\n", n);
    } else {
        printf("Apsolutna vrednost broja je %d.\n", -1 * n);
    }
    return 0;
}
