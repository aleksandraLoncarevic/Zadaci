#include <stdio.h>
#include <string.h>
#define MAX 50

typedef struct kodni_zapis{
    char rec[10];
    char slovo;
} KODNI_ZAPIS;

void kodiraj(char *str, KODNI_ZAPIS *kodni_zapis, int);

int main() {

    char str[MAX];
    printf("Unesite string: ");
    scanf(" %s", &str);

    int brojKodnihZapisa;
    printf("Unesite broj kodnih zapisa: ");
    scanf("%i", &brojKodnihZapisa);
    printf("--------------------------\n");
    KODNI_ZAPIS kodniZapis[brojKodnihZapisa];
    for(int i=0; i<brojKodnihZapisa; i++) {
        printf("Unesite slovo %i.kodnog zapisa: ", i+1);
        scanf(" %c", &kodniZapis[i].slovo);
        printf("Unesite rec %i.kodnog zapisa: ", i+1);
        scanf(" %s", &kodniZapis[i].rec);
    }
    kodiraj(str, kodniZapis, brojKodnihZapisa);
    return 0;
}

void kodiraj(char *str, KODNI_ZAPIS *kodniZapis, int brojKodnihZapisa) {
    char new_str[100];
    int i=0, k;
    for(int j=0; j<brojKodnihZapisa; j++) {
        if(str[i]==kodniZapis[j].slovo) {
            int n = strlen(kodniZapis[j].rec);
            for(k=0; k<n; k++) {
                new_str[i+k]=kodniZapis[j].rec[k];
            }
            i++;
        }else{
            new_str[i]=str[i-k+1];
            i++;
        }
    }
    printf("%s", new_str);
}
