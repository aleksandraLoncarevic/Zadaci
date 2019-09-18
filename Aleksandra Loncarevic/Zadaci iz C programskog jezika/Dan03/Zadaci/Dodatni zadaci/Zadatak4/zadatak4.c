#include <stdio.h>

int main() {
    int n;
    printf("Unesite broj: ");
    scanf("%i", &n);
    for(int i=1; i<=n; i++) {
        for(int j=n; j>0; j--) {
           if(j%i==0) {
               printf("(%i, %i)\t", i, j);
           }
        }
    }
    return 0;
}
