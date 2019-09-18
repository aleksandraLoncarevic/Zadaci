#include <stdio.h>

void bruteForce(int *niz, int n) {
    for(int j=1; j<n; j++) {
        for(int i=0; i<j; i++) {
            if(niz[i]>niz[j]) {
                int temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
}
int main(){
    int n;
    printf("Unesite velicinu niza: ");
    scanf(" %i", &n);
    int niz[n];
    for(int i=0; i<n; i++){
        printf("Unesite %i.element niza: ", i+1);
        scanf(" %i", &niz[i]);
    }
    bruteForce(niz, n);
    printf("Sortirani niz:\n");
    for(int i=0; i<n; i++){
        printf("%i\t", niz[i]);
    }
    return 0;
}
