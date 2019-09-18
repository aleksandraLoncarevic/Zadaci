#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* substr(char *s1);

int main() {
    char s1[30];
    printf("Unesite string S1: ");
    scanf(" %s", &s1);

    char *s2 = substr(s1);
    printf("%s", s2);
    return 0;
}

void removeChar(char *s2,int k, char c) {
    int i, j, k1;
    for(i=0; i<k; i++) {
        if(s2[i] == c) {
            k1=k-1;
            for(j=i; j<k; j++) {
                s2[j]=s2[j+1];
            }
        }
    }
    k=k1;
}

char* substr(char *s1){
    int p, q;
    printf("Unesite broj p: ");
    scanf(" %i", &p);
    printf("Unesite broj q: ");
    scanf(" %i", &q);
	int k = q - p;
    char *s2 = (char*)malloc(sizeof(char) * (k+1));
	strncpy(s2, s1+p, k);
	s2[k+1]='\0';
	removeChar(s2, k, 'a');
	s2[k+1]='\0';
	return s2;
}
