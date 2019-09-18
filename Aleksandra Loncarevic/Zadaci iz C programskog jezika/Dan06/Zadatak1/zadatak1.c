#include<stdio.h>

char* samoSlova(char* niz);

int main() {
    char str[150];
    printf("Enter a string: ");
    gets(str);
    printf("Output String: ");
    printf("%s", samoSlova(str));
    return 0;
}

char* samoSlova(char* niz) {
    int i, j;
    for(i = 0; niz[i] != '\0'; i++){
            while (!( (niz[i] >= 'a' && niz[i] <= 'z') || (niz[i] >= 'A' && niz[i] <= 'Z') || niz[i] == '\0') ){
                for(j = i; niz[j] != '\0'; j++){
                    niz[j] = niz[j+1];
                }
                niz[j] = '\0';
            }
    }
    return niz;
}
