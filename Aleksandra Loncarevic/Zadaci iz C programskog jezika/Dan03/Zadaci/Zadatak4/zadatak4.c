#include <stdio.h>

int main() {
    int broj;
    printf("Unesite broj: ");
    scanf("%d", &broj);
    int obrnuti = 0; /*ovo je obrnuti broj koji cemo ispisati na izlazu*/
    do{
        obrnuti = 10*obrnuti + broj%10;
        broj=broj/10;
    }while(broj>0);
    printf("Permutovan broj je %d.\n", obrnuti);
    return 0;
}
