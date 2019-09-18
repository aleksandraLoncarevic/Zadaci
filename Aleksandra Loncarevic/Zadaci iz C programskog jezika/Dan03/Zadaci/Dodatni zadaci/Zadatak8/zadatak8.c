#include <stdio.h>

int main() {
    int x;
    int y;
    printf("Unesi brojeve x i y: ");
    scanf("%i %i", &x, &y);
    int brojac = 0;
    for(int i=x; i<=y; i++) {
        if(i%2==0 && i%7!=0) {
            brojac++;
        }
    }
    printf("Parnih brojeva u intervalu [%i, %i] ima %i.\n", x, y, brojac);
    return 0;
}
