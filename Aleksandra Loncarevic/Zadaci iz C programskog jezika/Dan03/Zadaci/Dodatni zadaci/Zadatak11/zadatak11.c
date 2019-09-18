#include <stdio.h>

int main() {
    int p;
    printf("Unesite broj: ");
    scanf("%i", &p);
    int sum = 0;
    int brojac = 0;
    int i = 1;
    while(brojac<p) {
        if(i%3==0) {
            sum+=i;
            brojac++;
        }
        i++;
    }

    printf("Zbir prvih %i brojeva je %i.\n", p, sum);
}
