#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int proveraDanaUnedelji(int dan);
int proveraKaraktera(char *vreme);
int validnoVreme(char *vreme);
void vremeDolaska(int danPolaska, char *vremePolaska, char *vremeTrajanja);
void unos();

int main() {
    printf("1.Unos polaska broda i racunanje kada on stize na odrediste.\n2.Exit\n");
    int izbor;
    do{
        printf("\nUnesite izbor: ");
        scanf(" %i", &izbor);
        switch(izbor){
        case 1:
            unos();
            break;
        case 2:
            exit(0);
        }
    }while(izbor==1);
    return 0;
}

void unos() {
    int danUnedelji;
    char vreme[9];
    char vremePlovidbe[20];
    int pD, pK1, pK2, pV;
    do{
        printf("\nUnesite redni dan u nedelji kada brod isplovljava: ");
        scanf("%i", &danUnedelji);
        pD = proveraDanaUnedelji(danUnedelji);
        if(pD==0) {
            do{
                printf("Unesite vreme isplovljavanja broda(hh:mm:ss): ");
                scanf(" %s", &vreme);
                pK1 = proveraKaraktera(vreme);
                if(pK1==0) {
                    pV = validnoVreme(vreme);
                    if(pV==0) {
                        do{
                            printf("Unesite duzinu trajanja plovidbe(hh:mm:ss): ");
                            scanf(" %s", &vremePlovidbe);
                            pK2 = proveraKaraktera(vremePlovidbe);
                        }while(pK2==1);
                    }
                }
            }while(pV==1 || pK1==1);
        }
    }while(pD==1);
    vremeDolaska(danUnedelji, vreme, vremePlovidbe);
}

int proveraDanaUnedelji(int dan) {
    int provera = 0;
    if(dan<=0 || dan>7) {
        printf("Nepravilan unos za radni dan u nedelji!!\n");
        provera = 1;
    }
    return provera;
}

int proveraKaraktera(char *vreme) {
    int i = 0;
    int proveraKaraktera = 0;
    while(vreme[i]!='\0'){
        if(vreme[i]!=':' && !isdigit(vreme[i])) {
            proveraKaraktera = 1;
            break;
        }
        i++;
    }
    if(proveraKaraktera==1) {
        printf("Nisu dozvoljena slova niti drugi karakteri za unos vremena!!!\n");
    }
    return proveraKaraktera;
}

int validnoVreme(char *vreme) {
    int provera = 0;
    int h, m, s;
    sscanf(vreme, "%d:%d:%d", &h, &m, &s);
    if(h<=0 || h>24){
        printf("Niste uneli pravilno sate!!!\n");
        provera = 1;
    }
    if(m<0 || m>60) {
        printf("Niste uneli pravilno minute!!!\n");
        provera = 1;
    }
    if(s<0 || s>60) {
        printf("Niste uneli pravilno sekunde!!!\n");
        provera = 1;
    }
    return provera;
}

void vremeDolaska(int danPolaska, char *vremePolaska, char *vremeTrajanja) {
    int h0, m0, s0;
    sscanf(vremePolaska, "%d:%d:%d", &h0, &m0, &s0);
    int h1, m1, s1;
    sscanf(vremeTrajanja, "%d:%d:%d", &h1, &m1, &s1);
    int h = h0 + h1;
    int m = m0 + m1;
    int s = s0 + s1;
    while(s>=60) {
        s-=60;
        m+=1;
    }
    while(m>=60){
        m-=60;
        h+=1;

    }
    while(h>24){
        h-=24;
        danPolaska+=1;
        while(danPolaska>7) {
            danPolaska-=7;
        }
    }
    printf("Brod je stigao na odrediste %d.dana u %d:%d:%d.\n", danPolaska, h, m, s);
}
