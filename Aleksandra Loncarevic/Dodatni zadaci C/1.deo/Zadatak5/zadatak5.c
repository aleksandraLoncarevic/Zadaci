#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float max(float x, float y);
float min(float x, float y);
float absolutnaVrednost(float n);

int main() {
    float x;
    float y;
    printf("1.Min i max dva broja\n2.Eixt\n");
    int izbor;
    do{
        printf("\nUnesite izbor: ");
        scanf(" %i", &izbor);
        switch(izbor) {
        case 1:
            printf("\nUnesite broj x: ");
            scanf(" %f", &x);
            printf("Unesite broj y: ");
            scanf(" %f", &y);
            float z;
            if(x>=y) {
                z = (float) max(x, y) / (1 + min(x, y));
            }else{
                z = (float) max(x, y) / (1 + absolutnaVrednost(min(x, y)));
            }
            printf("z = %f\n", z);
            break;
        case 2:
            exit(0);
        }
    }while(izbor==1);
    return 0;
}

float max(float x, float y) {
    if(x>=y) {
        return x;
    }
    return y;
}

float min(float x, float y) {
    if(x<=y) {
        return x;
    }
    return y;
}

float absolutnaVrednost(float n) {
    if(n<0) {
        return (-1)*n;
    }
    return n;
}
