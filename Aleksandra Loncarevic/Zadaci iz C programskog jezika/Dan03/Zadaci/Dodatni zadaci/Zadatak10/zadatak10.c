#include <stdio.h>

int main() {
    int a;
    printf("Unesite broj a: ");
    scanf("%i", &a);
    int p =1;
    for(int i=0; p<10000; i++){
        p*=a+i;
    }
    printf("Dobijeni proizvod je %i.\n", p);
    return 0;
}
