#include <stdio.h>

int n;
int brojSaNajviseDelilaca();

int main() {
    printf("Unesite broj: ");
    scanf(" %i", &n);
    printf("\nBroj izmedju 1 i %i sa najvise delilaca je %i.\n", n, brojSaNajviseDelilaca());
    return 0;
}

int brojDelioca(int n) { /*Ova funkcija vraca broj delilaca za uneti broj*/
    int brojac = 0;
    for(int i=1; i<=n; i++) {
        if(n%i==0) {
            brojac++;
        }
    }
    return brojac;
}

int brojSaNajviseDelilaca() {
    int i;
    int niz[n]; /*U ovaj niz unosim broj delilaca za brojeve od 1 do n, znaci elementi niza ce mi biti brojaci delilaca*/
    for(i=0; i<n; i++) {
        niz[i] = brojDelioca(i+1);
    }

    int max = niz[0];   /*Posto ndeks niza krece od 0 do n-1, a na tim pozicijama se nalaze brojaci delilaca brojeva od 1 do n, mi */
    int max_index = 1; /*ovde pronalazimo max brojac, ali vracamo broj koji ima max broj delilaca*/
    for(int i=1; i<n; i++){
        if(niz[i]>=max) {
            max = niz[i];
            max_index = i+1;
        }
    }
    return max_index;
}
