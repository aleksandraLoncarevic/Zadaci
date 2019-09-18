#include <stdio.h>
#define N 100

int brojBinarnihJedinica(unsigned char n);

int main() {
    unsigned char a[N];
    int n;
    while(1) {
        printf("\nUnesite N: ");
        scanf(" %i", &n);
        if(n<=0 || n>N) {
            break;
        }
        printf("Unesite poruku: ");
        for(int i=0; i<n; i++) {
            scanf(" %d", &a[i]);
        }
        for(int i=0; i<n; i++) {
            int jedinice = brojBinarnihJedinica(a[i]);
            printf("Broj binarnih jedinica je %i.\n", jedinice);
            if(jedinice%2!=0) {
                a[i] = a[i] | 128;
            }
        }
        printf("Poruka za slanje: ");
        for(int i=0; i<n; i++) {
            printf("%u\t", a[i]);
        }
    }
    return 0;
}

int brojBinarnihJedinica(unsigned char n) {
  int brojac = 0;
  while (n) {
    brojac += n & 1;
    n >>= 1;
  }
  return brojac;
}
