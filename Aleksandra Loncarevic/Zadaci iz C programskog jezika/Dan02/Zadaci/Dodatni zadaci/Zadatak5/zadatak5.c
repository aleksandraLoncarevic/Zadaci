#include <stdio.h>

int main() {
    float rastojanje;
    float vreme;
    printf("Unesi predjeno rastojanje i vreme trajanja u km/h: ");
    scanf("%f %f", &rastojanje, &vreme);
    printf("Brzina iznosi %.2f.", (rastojanje*1000) / (vreme*3600));
    return 0;
}
