#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define n 40


int proveraDuzine(char *adresa);
int proveraKaraktera(char *adresa);
char *replace(char *str, char *a, char *b);
char *skratiAdresu(char *adresa);
char *vodeceNule(char *adresa);

int main(){
    char ipv6[n];
    int proveraDuz;
    int proveraKar;
    do{
        printf("Unesite IPv6 adresu(aaaa:bbbb:cccc:dddd:eeee:ffff:gggg:hhhh): ");
        scanf(" %s", &ipv6);
        proveraKar = proveraKaraktera(ipv6);
        if(proveraKar == 0) {
            char adresa[n];
            strcpy(adresa, ipv6);
            proveraDuz = proveraDuzine(adresa);
        }
    }while(proveraDuz == 1 || proveraKar == 1);

    printf("Zamenom grupe nula sa * dobijamo:\n%s\n", replace(ipv6, "0000", "*"));
    printf("\nSkratimo jednu ili vise grupa nula:\n%s\n", skratiAdresu(ipv6));
    printf("\nUklonimo vodecene nule:\n%s\n", vodeceNule(ipv6));
    printf("\nKonacna skracena verzija IPv6:\n%s\n", replace(ipv6, "*", "0"));
    return 0;
}

int proveraDuzine(char *adresa) {
    int provera = 0;
    int size = 0;
    char *ptr = strtok(adresa, ":");
    char **validniDelovi = NULL;
    while(ptr!=NULL) {
        if(strlen(ptr)==4) {
            validniDelovi = realloc(validniDelovi, sizeof(char*) * ++size);
            validniDelovi[size-1] = ptr;
        }
        ptr = strtok(NULL, ":");
    }
    if(size != 8) {
        printf("Duzina IPv6 adrese nije validna!!!\n");
        provera = 1;
    }
    return provera;
}

int proveraKaraktera(char *adresa) {
    int provera = 0;
    char validniKarakteri[] = {'A', 'B', 'C', 'D', 'E', 'F',
                               'a', 'b', 'c', 'd', 'e', 'f',
                               ':', '0', '1', '2', '3', '4',
                               '5', '6', '7', '8', '9'};

   for(int i=0; adresa[i]!='\0'; i++) {
        char tekuci = adresa[i];
        int j = 0;
        while(j<24) {
            if(tekuci == validniKarakteri[j]) {
                break;
            }
            j++;
        }
        if(j == 23) {
            printf("Uneli ste nedozvoljene karaktere za IPv6 adresu!!!\n");
            provera = 1;
            break;
        }
    }
    return provera;
}

char *replace(char* str, char* a, char* b){
    int len  = strlen(str);
    int lena = strlen(a), lenb = strlen(b);
    for (char *p=str; p=strstr(p,a); ++p) {
        if (lena!=lenb) {
            memmove(p+lenb, p+lena, len - (p - str) + lenb);
        }
        memcpy(p, b, lenb);
    }
    return str;
}

char *skratiAdresu(char *adresa) {
    int size = strlen(adresa);
    int i;
    for(i=size; i>0; i--) {          //idemo od kraja adrese i prvu grupu nula menjamo ::
        if(adresa[i]=='*' && adresa[i-1]==':') {
            adresa[i] = ':';
            break;
        }
    }
    if(i==0){       //ako u adresi nema nijedne grupe nula, ostalo je jos da proverimo pocetak adrese
        if(adresa[i]=='*') {
            adresa[i]=':';
        }
    }
    while(strstr(adresa, "*::")) {     //kada zamenimo prvu grupu nula :: proveramo da li pored te grupe postoji jos grupa nula
        adresa = replace(adresa, "*::", "::");
    }
    while(strstr(adresa, ":::")) {   //na kraju samo sredimo ispis
        adresa = replace(adresa, ":::", "::");
    }
    return adresa;
}

char *vodeceNule(char *adresa) {
    while(strstr(adresa, ":0")){
        replace(adresa, ":0", ":");
    }
    int size = strlen(adresa);
    while(adresa[0]=='0' && adresa[1]!=':') {
        for(int i=0; i<size; i++) {
            adresa[i]=adresa[i+1];
        }
    }
    return adresa;
}
