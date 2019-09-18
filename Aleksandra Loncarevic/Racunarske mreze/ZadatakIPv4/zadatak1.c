#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define n 16

int *splitAndConvertChar(char *adress);
int proveraKaraktera(char *adresa);
int opseg(int *array);
void broadcast(int *arr1, int *arr2);
int dozvoljenjeCifre(int *array);
int *binarniZapis(int);

int main() {
    char ipAdress[n];
    int provera1, p1;
    int *arr1;
    do{
        printf("Unesite IP adresu (xxx.yyy.zzz.ddd): ");
        scanf(" %s", &ipAdress);
        provera1 = proveraKaraktera(ipAdress);
        arr1 = splitAndConvertChar(ipAdress);
        p1 = opseg(arr1);
    }while(provera1==1 || p1==1);

    char subnetMask[n];
    int provera2, p2, pr2;
    int *arr2;
    do{
        printf("Unesite mreznu masku (xxx.yyy.zzz.ddd): ");
        scanf(" %s", &subnetMask);
        provera2 = proveraKaraktera(subnetMask);
        arr2 = splitAndConvertChar(subnetMask);
        p2 = opseg(arr2);
        pr2 = dozvoljenjeCifre(arr2);
    }while(provera2==1 || p2==1 || pr2==1);


    printf("\nSUBNET:\n");
    int *arr3 = (int*) calloc(4, sizeof(int));
    for(int i = 0; i<3; i++){
        arr3[i] = arr1[i] & arr2[i];
        printf("%i.", arr3[i]);
    }
    printf("%i", arr1[3]&arr2[3]);


    printf("\nSubnet u binarnom zapisu:\n");
    for(int i=0; i<4; i++) {
        int *bin = binarniZapis(arr3[i]);
        for(int j=0; j<8; j++) {
            printf("%i", bin[j]);
        }
        if(i<3) {
            printf(".");
        }
    }

    printf("\n\nBROADCAST:\n");
    broadcast(arr1, arr2);
    return 0;
}

int proveraKaraktera(char *adress) {                /*funkcija koja proverava da li uneta adresa sadrzi karaktere*/
    int provera = 0;
    int i = 0;
    while(adress[i]!='\0') {
        if(adress[i]!='.' && !isdigit(adress[i]))  {
            provera = 1;
            printf("Neispravan unos!!\n");
            break;
        }
        i++;
    }
    return provera;
}

int opseg(int *array){      /*funkcija koja proverava da li je svaki deo ip adrese u intervalu (0, 255)*/
    int provera = 0;
    int i = 0;
    while(i<4) {
        if(array[i]<0 || array[i]>255){
            provera = 1;
            printf("Broj %i nije u intervalu od 0 do 255!!!\n", array[i]);
            break;
        }
        i++;
    }
    return provera;
}

int dozvoljenjeCifre(int *array) {     /*dozvoljeni brojevi za mreznu masku*/
    int provera = 0;
    for(int i=0; i<4; i++) {
        if(array[i]!=0 && array[i]!=128 && array[i]!=192 && array[i]!=224 && array[i]!=240
                       && array[i]!=248 && array[i]!=252 && array[i]!=254 && array[i]!=255) {
            provera = 1;
            printf("Broj %i za mreznu masku nije dozvoljen!!!\n", array[i]);
            break;

        }
    }
    return provera;
}


int *splitAndConvertChar(char adress[n]) {    /*funkcija koja deli string na podstringove prema znaku "."*/
    char delim[] = ".";                       /*i konvertuje ih u int i smesta u niz*/
    char *ptr = strtok(adress, delim);
    int i = 0;
    int *array = (int*)calloc(4, sizeof(int));
    while(ptr != NULL) {
        *(array+i) = atoi(ptr);
        i++;
        ptr = strtok(NULL, delim);
    }
    return array;
}

void broadcast(int *arr1, int *arr2) {
    int *arr3 = (int*) calloc(4, sizeof(int));
    for(int i=0; i<4; i++) {
        if(arr2[i]==255) {
            arr3[i] = arr1[i];
        }else if(arr2[i]==0) {
            arr3[i] = 255;
        }else{
            int x = 256 - arr2[i];
            int y = x;
            while(y<=arr1[i]) {
                y+=x;
            }
            y-=1;
            arr3[i] = y;
        }
    }
    for(int i=0; i<3; i++) {
        printf("%i.", arr3[i]);
    }
    printf("%i", arr3[3]);
    printf("\nBroadcast u binarnom zapisu:\n");
    for(int i=0; i<4; i++) {
        int *bin = binarniZapis(arr3[i]);
        for(int j=0; j<8; j++) {
            printf("%i", bin[j]);
        }
        if(i<3) {
            printf(".");
        }
    }
}

int *binarniZapis(int broj) {            /*funkcija koja pretvara dekadni zapis u binarni*/
    int *binarniZap = (int*) calloc(8, sizeof(int));
    for(int i=7; i>=0; i--) {
        binarniZap[i] = broj % 2;
        broj = broj/2;
    }
    return binarniZap;
}
