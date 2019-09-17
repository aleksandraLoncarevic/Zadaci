#include <stdio.h>

int main() {
    int x;
    int y;
    printf("Unesite vrednosti x i y promenljive: ");
    scanf("%d %d", &x, &y);
    /*deo pod a) koristeci pomocnu promenljivu*/
    int temp = x;
    x = y;
    y = temp;
    printf("x = %d, y = %d\n", x, y);

    /*deo pod b) koristeci sabiranje i oduzimanje*/
    /*Samo ovde ja kada unesem vrednosti za x i y prvo ih zamenim pomocu pomocne promenljive,
      pa ih opet zamenim pomocu sabiranja i oduzimanja, pa njihove vrednosti budu kao pocetne.*/
    x = x+y;
    y = x-y;
    x = x-y;
    printf("x = %d, y=%d\n", x, y);
    return 0;
}
