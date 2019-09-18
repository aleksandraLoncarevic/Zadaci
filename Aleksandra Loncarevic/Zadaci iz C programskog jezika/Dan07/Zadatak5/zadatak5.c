#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100

int main() {
    float x[N], y[N];
    int n;
    while(1) {
        printf("Unesite broj tacaka: ");
        scanf(" %i", &n);

        if(n<=0 || n>N){
            break;
        }

        printf("Random izgenerisane tacke su:\n");
        for(int i=0; i<n; i++) {
            x[i] = rand()/(float)RAND_MAX;
            y[i] = rand()/(float)RAND_MAX;
            printf("(%f %f)\n", x[i], y[i]);
        }
        int j=0;
        for(int i=0; i<n; i++) {
            if(pow(x[i], 2) + pow(y[i], 2) <= 1) {
                x[j]=x[i];
                y[j]=y[i];
                j++;
            }
        }
        n=j;
        printf("Tacke koje pripadaju krugu jedinicnog precnika su:\n");
        for(int i=0; i<n; i++) {
            printf("(%f %f)\n", x[i], y[i]);
        }
    }
    return 0;
}
