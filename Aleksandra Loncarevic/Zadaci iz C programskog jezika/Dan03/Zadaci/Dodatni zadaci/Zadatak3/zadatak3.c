#include <stdio.h>

int main() {
    int n;
    printf("Unesite broj: ");
    scanf("%i", &n);
    for(int i=1; i<n; i++) {
        int c1 = i%10;
        if(c1==6 && i%3==0) {
            printf("%i\n", i);
        }
    }
    return 0;
}
