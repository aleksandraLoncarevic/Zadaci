#include <stdio.h>

int main() {
    FILE *file = fopen("studenti.txt", "w");

    int brojStudenata;
    printf("Unesite broj studenata: ");
    scanf(" %i", &brojStudenata);

    char ime[30];
    int ocena;

    for(int i=0; i<brojStudenata; i++) {
        printf("Za studenta %i.\n", i+1);

        printf("Unesite ime studenta: ");
        scanf(" %s", &ime);
        fprintf(file, "Ime:%s\n", ime);

        printf("Unesite ocenu: ");
        scanf(" %i", &ocena);
        fprintf(file, "Ocena:%i\n\n", ocena);
    }
    fclose(file);
    return 0;
}
