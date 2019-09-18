#include <stdio.h>

int main() {
    int godina;
    printf("Unesite godinu: ");
    scanf("%i", &godina);
    if((godina%4==0 && godina%100!=0) ||  godina%400==0) {
        printf("Godina je prestupna!");
    } else {
        printf("Godina nije prestupna!");
    }
    return 0;
}
