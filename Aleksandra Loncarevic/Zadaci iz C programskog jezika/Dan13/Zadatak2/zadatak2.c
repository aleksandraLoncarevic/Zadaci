#include <stdio.h>
#include <string.h>

typedef struct osoba{
    int dan;
    int mesec;
    int godina;
    char ime[20];
    char adresa[50];
}Osoba;

void unesiOsobe(Osoba *osobe, int n);
void ucitajHoroskop(Osoba *osobe, int n, char *znak);

int main() {
    int n;
    printf("Unesite broj osoba: ");
    scanf(" %i", &n);

    Osoba osobe[n];
    unesiOsobe(osobe, n);

    char znak[10];
    printf("\nUnesite horoskopski znak: ");
    scanf(" %s", &znak);
    ucitajHoroskop(osobe, n, znak);

    return 0;
}

void unesiOsobe(Osoba *osobe, int n) {
    for(int i=0; i<n; i++) {
        printf("\nUnesite ime %i.osobe: ", i+1);
        scanf(" %s", &osobe[i].ime);
        printf("Unesite adresu %i.osobe: ", i+1);
        scanf(" %s", &osobe[i].adresa);
        printf("Unesite dan rodjenja %i.osobe: ", i+1);
        scanf(" %i", &osobe[i].dan);
        printf("Unesite mesec %i.osobe: ", i+1);
        scanf(" %i", &osobe[i].mesec);
        printf("Unesite godinu %i.osobe: ", i+1);
        scanf(" %i", &osobe[i].godina);
    }
}

void ucitajHoroskop(Osoba *osobe, int n, char *znak) {
    FILE *file, *file1;
    file = fopen("horoskop.txt", "r");
    char znak1[10];

    int niz[4];
    while(fscanf(file, "%s", &znak1)!=EOF) {
        if(strcmp(znak, znak1) == 0){
            fscanf(file, "%i %i %i %i", &niz[0], &niz[1], &niz[2], &niz[3]);
        }
    }
    fclose(file);

    strcat(znak,".txt");
    file1 = fopen(znak, "w");
    for(int i=0; i<n; i++) {
        if((osobe[i].dan>=niz[0] && osobe[i].mesec == niz[1])  || (osobe[i].dan<=niz[2] && osobe[i].mesec == niz[3])) {
            printf("%s\n", osobe[i].ime);
            fprintf(file1, "%s\n", osobe[i].ime);
        }
    }
    fclose(file1);
}
