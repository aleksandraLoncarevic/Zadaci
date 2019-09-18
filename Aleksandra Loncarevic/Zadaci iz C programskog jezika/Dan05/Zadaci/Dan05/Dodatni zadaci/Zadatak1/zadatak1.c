#include <stdio.h>

int palindrom(int niz[], int n) {
    int sum = 0;
    for(int i=0; i<=n/2; i++) {
        if(niz[i]==niz[n-i-1]) {
            sum+=0;
        } else {
            sum+=1;
        }
    }
    if(sum==0) {
        return 1;
    }
    return 0;
}

int main() {
    int n;
    printf("Unesite velicinu niza: ");
    scanf(" %i", &n);
    int niz[n];
    for(int i=0; i<n; i++) {
        printf("Unesite %i.element niza: ", i+1);
        scanf(" %i", &niz[i]);
    }
    if(palindrom(niz, n)) {
        printf("Uneti niz je palindrom!!!");
    }else {
        printf("Uneti niz nije palindrom!!!");
    }
    return 0;
}

