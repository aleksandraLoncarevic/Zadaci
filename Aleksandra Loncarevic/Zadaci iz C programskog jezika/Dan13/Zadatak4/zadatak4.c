#include <stdio.h>

typedef struct roba {
    int sifra, kolicina;
    char naziv[15];
    float cena;
}ROBA;

int main() {

    FILE *file, *file1;
    file = fopen("magacin.txt", "r");
    int broj;
    fscanf(file, "%i", &broj);
    ROBA roba[broj];

    file1 = fopen("sredjeno.txt", "w");

    for(int i=0; i<broj; i++) {
        fscanf(file, "%i %s %i %f", &roba[i].sifra, &roba[i].naziv, &roba[i].kolicina, &roba[i].cena);
    }
    fclose(file);

    for(int j=0; j<broj-1; j++) {
        for(int i=j+1; i<broj; i++){
            if(roba[i].sifra == roba[j].sifra) {
                roba[i].kolicina += roba[j].kolicina;
            }
        }
    }

    for(int i=0; i<broj; i++) {
        printf("%i %s %i %f\n", roba[i].sifra, roba[i].naziv, roba[i].kolicina, roba[i].cena);
    }

    fclose(file1);
    return 0;
}
