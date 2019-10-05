#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

float ekvivalentnaOtpornost(float *niz, int n, char veza);

int main() {
    printf("1.Racunanje ekvivalentne otpornosti otpornika\n2.Exit\n");
    int izbor;

    int n;
    char veza;
    float *niz;
    do{
        printf("\nUnesite izbor: ");
        scanf(" %i", &izbor);
        switch(izbor) {
        case 1:
            do{
                printf("\nUnesite broj otpornika: ");
                scanf(" %i", &n);
                niz = calloc(n, sizeof(float));
                if(n>0){
                    for(int i=0; i<n; i++){
                        printf("Unesite otpornost R%i otpornika: ", i+1);
                        scanf(" %f", &niz[i]);
                    }
                    do{
                        printf("Unesite 'r' za redno ekvivalentnu otpornost, 'p' za paralelnu: ");
                        scanf(" %c", &veza);
                    }while(veza!='r' && veza!='p');
                }
            }while(n<=0);
            printf("Ekvivalentna otpornost iznosi %.3f.\n", ekvivalentnaOtpornost(niz, n, veza));
            break;
        case 2:
            exit(0);
        }
    }while(izbor==1);
    return 0;
}

float ekvivalentnaOtpornost(float *niz, int n, char veza) {
    float ekvOtp = 0;
    if(veza=='r') {
        for(int i=0; i<n; i++) {
            ekvOtp+=niz[i];
        }
    }else{
        for(int i=0; i<n; i++) {
            ekvOtp+=(float)1/niz[i];
        }
    }
    return ekvOtp;
}
