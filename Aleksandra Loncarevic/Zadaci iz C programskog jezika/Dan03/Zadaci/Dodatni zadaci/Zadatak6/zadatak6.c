#include <stdio.h>

int main() {
    int n;
    printf("Unesite broj: ");
    scanf("%i", &n);
    for(int i=1; i*i<n; i++) {
        printf("%i\n", i);
    }
    return 0;
}
