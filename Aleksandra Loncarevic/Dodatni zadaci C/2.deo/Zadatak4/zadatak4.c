#include <stdio.h>
#include <stdlib.h>

int NZD(int n, int m);
int NZS(int n, int m);

int main() {
    printf("1.NZS(n, m) i NZD(n, m)\n2.Exit\n");
    int izbor;

    int n, m;
    do{
        printf("\nUnesite izbor: ");
        scanf(" %i", &izbor);
        printf("\n");
        switch(izbor) {
        case 1:
            do{
                printf("Unesite prirodan broj n: ");
                scanf(" %i", &n);
                if(n>0){
                    do{
                        printf("Unesite prirodan broj m: ");
                        scanf(" %i", &m);
                    }while(m<=0);
                }
            }while(n<=0);
            printf("NZD(%i, %i) = %i\nNZS(%i, %i) = %i\n", n, m, NZD(n, m), n, m, NZS(n, m));
            break;
        case 2:
            exit(0);
        }
    }while(izbor==1);
    return 0;
}

int NZD(int n, int m) {
    while(m!=0) {
        if(n>m) {
            n = n - m;
        }else{
            m = m - n;
        }
    }
    return n;
}

int NZS(int n, int m) {
    return (n*m)/NZD(n, m);
}
