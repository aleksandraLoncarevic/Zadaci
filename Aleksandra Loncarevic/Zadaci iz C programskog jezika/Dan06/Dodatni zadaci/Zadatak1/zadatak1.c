#include <stdio.h>
#include <math.h>


typedef struct zid {
    int visinaA;
    int visinaB;
    int visinaC;
} ZID;

int max(int, int, int);
int preostaloRedova(ZID urosevi, ZID varijanta);

int main() {
    ZID urosevi;
    printf("Unesite broj redova cigala koje su Uros i njegovi drugovi napravili: ");
    scanf(" %i", &urosevi.visinaA);
    scanf(" %i", &urosevi.visinaB);
    scanf(" %i", &urosevi.visinaC);
    ZID varijanta1;
    printf("Unesite broj redova cigala u 1.varijanti koju je Urosev deda zamislio: ");
    scanf(" %i", &varijanta1.visinaA);
    scanf(" %i", &varijanta1.visinaB);
    scanf(" %i", &varijanta1.visinaC);
    ZID varijanta2;
    printf("Unesite broj redova cigala u 2.varijanti koju je Urosev deda zamislio: ");
    scanf(" %i", &varijanta2.visinaA);
    scanf(" %i", &varijanta2.visinaB);
    scanf(" %i", &varijanta2.visinaC);
    int minuta1 = 30 * preostaloRedova(urosevi, varijanta1);
    int minuta2 = 30 * preostaloRedova(urosevi, varijanta2);
    if(minuta1>minuta2) {
        printf("Minimalan broj minuta koji je potreban Urosu i njegovim drugovima da poprave zid je %i.\n", minuta2);
    }else{
        printf("Minimalan broj minuta koji je potreban Urosu i njegovim drugovima da poprave zid je %i.\n", minuta1);
    }
    return 0;
}

int max(int a, int b, int c) {
    if(a>b) {
        if(a>c) {
            return a;
        } else {
            return c;
        }
    } else {
        if(b > c) {
            return b;
        } else {
            return c;
        }
    }
}

int absolutnaVrednost(int a) {
    if(a<0) {
        return a*(-1);
    }else{
        return a;
    }
}

int preostaloRedova(ZID urosevi, ZID varijanta) {
    int preostaloRedovaA = absolutnaVrednost(urosevi.visinaA-varijanta.visinaA);
    int preostaloRedovaB = absolutnaVrednost(urosevi.visinaB-varijanta.visinaB);
    int preostaloRedovaC = absolutnaVrednost(urosevi.visinaC-varijanta.visinaC);
    return max(preostaloRedovaA, preostaloRedovaB, preostaloRedovaC);
}
