#include <stdio.h>

int main() {
    float jacina;
    printf("Unesite jacinu struje u miliamperima: ");
    scanf(" %f", &jacina);
    jacina = (float) jacina/1000; /*konvertujemo u ampere*/
    float napon;
    printf("Unesite napon u voltima: ");
    scanf(" %f", &napon);
    float otpor = (float) napon/jacina;
    printf("Otpornost nelinearnog otpornika je %.3f.\n", otpor);
    return 0;
}
