#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("artikli.txt", "r");
    int barKod;
    char nazivArtikla[20];
    float cena;
    float pdv;
    char ch;

    while((ch=fgetc(file))!=EOF) {
        fscanf(file,"%d %s %f %f", &barKod, &nazivArtikla, &cena, &pdv);
        printf("%i %s %f %f\n", barKod, nazivArtikla, cena, pdv);
    }
    fclose(file);
    return 0;
}
