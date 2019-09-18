#include <stdio.h>

double iznos(int n, double p, double s) {
    double iznos = s + (s*p/100)*n;
    return iznos;
}

int main() {
    int godina;
    double kamata;
    double suma;
    printf("Unesite sumu novca koju imate: ");
    scanf(" %lf", &suma);
    printf("Unesite godisnju kamatu: ");
    scanf(" %lf", &kamata);
    printf("Unesite broj godina: ");
    scanf(" %i", &godina);
    printf("Suma novca kojom raspolazete posle %i godina, sa godisnjom kamatom od %.3lf i pocetnom sumom %.3lf je %.3lf.\n", godina, kamata, suma, iznos(godina, kamata, suma));
    return 0;
}
