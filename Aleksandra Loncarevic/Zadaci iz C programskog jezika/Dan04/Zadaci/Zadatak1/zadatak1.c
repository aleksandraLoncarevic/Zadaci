#include <stdio.h>

void parniBrojevi(int a, int b) {
    printf("Parni brojevi veci od %i, a manji od %i su: \n", a, b);
    for(int i=a+1; i<b; i++) {
        if(i%2 == 0) {
            printf("%i\n", i);
        }
    }
}

int main() {
    int a, b;
    printf("Unesite brojeve a i b: ");
    scanf(" %i %i", &a, &b);
    parniBrojevi(a, b);
    return 0;
}


