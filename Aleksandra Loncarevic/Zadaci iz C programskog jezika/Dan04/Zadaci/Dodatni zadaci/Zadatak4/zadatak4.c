#include <stdio.h>

void sabiranje();
void oduzimanje();
void mnozenje();
void deljenje();

int main() {

    int operacija;
    do{
    printf("\nUnesite operaciju(1.Sabiranje, 2.Oduzimanje, 3.Mnozenje, 4.Deljenje, 5.Izlaz): ");
    scanf(" %i", &operacija);
        switch(operacija) {
    case 1:
        sabiranje();
        break;
    case 2:
        oduzimanje();
        break;
    case 3:
        mnozenje();
        break;
    case 4:
        deljenje();
        break;
    case 5:
        return 0;
        break;
    }
    } while(operacija!=5);
}

void sabiranje() {
    int a, b;
    printf("Unesite brojeve: ");
    scanf(" %i %i", &a, &b);
    printf("SABIRANJE: %i\n", a+b);
}

void oduzimanje() {
    int a, b;
    printf("Unesite brojeve: ");
    scanf(" %i %i", &a, &b);
    printf("ODUZIMANJE: %i\n", a-b);
}

void mnozenje() {
    int a, b;
    printf("Unesite brojeve: ");
    scanf(" %i %i", &a, &b);
    printf("MNOZENJE: %i\n", a*b);
}

void deljenje() {
    int a, b;
    printf("Unesite brojeve: ");
    scanf(" %i %i", &a, &b);
    printf("DELJENJE: %f\n", (float)a/b);
}
