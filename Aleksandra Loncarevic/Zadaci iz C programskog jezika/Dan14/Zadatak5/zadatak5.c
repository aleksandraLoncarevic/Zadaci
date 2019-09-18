#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct SComplex{
    double Re, Im;
} TComplex;

TComplex Zbir(TComplex z1, TComplex z2){
    TComplex cplx;
    cplx.Re= z1.Re + z2.Re;
    cplx.Im= z1.Im + z2.Im;
    return cplx;
}

void Konjug(TComplex*pZ){
    pZ->Im= -pZ->Im;
}

void Ispis(TComplex z){
    if (z.Im>= 0)
        printf("%5.4f + j%5.4f", z.Re, z.Im);
    else
        printf("%5.4f -j%5.4f", z.Re, -z.Im);
}

int DaLiJeBroj(const char *pstr){
    int bTacka= FALSE;
    if (*pstr=='+' || *pstr=='-')
        ++pstr;
    while(*pstr){
        if (!isdigit(*pstr) && *pstr!='.')
            return FALSE;
        if (*pstr== '.')  {
            if (bTacka)
                return FALSE;
            bTacka= TRUE;
        }
        pstr++;
    }
    return TRUE;
}

int main(int argc, char *argv[]){
    TComplex z1, z2, zbir;
    int i;
    if (argc!= 5){
        printf("Unesite tacno cetiri argumenta programa!\n");
        return -1;
    }
    printf("Argumenti su sledeci:\n");
    for (i=1; i < argc; i++)
        printf("%d%s\n", i, argv[i]);
    for (i=1; i < argc; i++){
        if (!DaLiJeBroj(argv[i])){
            printf("Uneli ste argument koji nije broj!\n");
            return -1;
        }
    }

    z1.Re = atof(argv[1]);
    z1.Im = atof(argv[2]);
    z2.Re = atof(argv[3]);
    z2.Im = atof(argv[4]);
    printf("\nPrvibroj: ");
    Ispis(z1);
    printf("\nDrugibroj: ");
    Ispis(z2);
    zbir = Zbir(z1, z2);
    Konjug(&z1);
    Konjug(&z2);
    printf("\nZbir: ");
    Ispis(zbir);
    printf("\nKonjug(z1): ");
    Ispis(z1);
    printf("\nKonjug(z2): ");
    Ispis(z2);
    return 0;
}
