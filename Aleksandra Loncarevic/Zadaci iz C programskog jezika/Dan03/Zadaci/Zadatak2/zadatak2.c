#include <stdio.h>

int main() {
    float x;
    printf("Unesite broj: ");
    scanf("%f", &x);
    if(x>-2 && x<2) {
        printf("%.3f\n", 2*x);
    } else if(x>=5 && x<=7) {
        printf("%.3f\n", 3*x-1);
    } else {
        printf("%.3f\n", 1/x);
    }
    return 0;
}
