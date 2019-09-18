#include <stdio.h>
#define MAX 30

typedef struct student {
    float prosek;
    char index[10];
    char imePrezime[MAX];
} STUDENT;

float prosekStudenata(STUDENT *nizStudenata, int);
void studentiIznadProseka(STUDENT *nizStudenata, int);

int main() {
    int n;
    printf("Unesite broj studenata: ");
    scanf(" %i", &n);
    STUDENT nizStudenata[n];
    for(int i=0; i<n; i++) {
        printf("Unesite ime i prezime studenta %i: ", i+1);
        scanf(" %[^\n]s", &nizStudenata[i].imePrezime);
        printf("Unesite broj indeksa studenta %i: ", i+1);
        scanf(" %s", &nizStudenata[i].index);
        printf("Unesite prosek ocena studenta %i: ", i+1);
        scanf(" %f", &nizStudenata[i].prosek);
    }
    printf("Prosek studenata je %f.\n", prosekStudenata(nizStudenata, n));
    printf("Studenti sa ocenama iznad proseka:\n");
    printf("**********************************\n");
    studentiIznadProseka(nizStudenata, n);
    return 0;
}

float prosekStudenata(STUDENT *nizStudenata, int n) {
    float suma = 0;
    for(int i=0; i<n; i++) {
        suma+=nizStudenata[i].prosek;
    }
    return suma/n;
}

void studentiIznadProseka(STUDENT *nizStudenata, int n) {
    float prosek = prosekStudenata(nizStudenata, n);
    for(int i=0; i<n; i++) {
        if(nizStudenata[i].prosek>prosek) {
            printf("%s %s", nizStudenata[i].imePrezime, nizStudenata[i].index);
        }
    }
}
