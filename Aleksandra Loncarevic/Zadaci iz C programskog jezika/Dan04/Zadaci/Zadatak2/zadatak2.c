#include <stdio.h>

int n;

void zbirCifara() {
    int suma = 0;
    while(n!=0){
        suma += n%10;
        n/=10;
    }
    printf("Zbir svih cifara broja je %i.\n", suma);
}

int main() {
    printf("Unesite prirodan broj: ");
    scanf(" %i", &n);
    zbirCifara();
    return 0;
}
