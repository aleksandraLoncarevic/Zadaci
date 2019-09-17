#include <stdio.h>

int main() {
    int oznaka;
    printf("Unesite oznaku sahovskog polja: ");
    scanf("%i", &oznaka);
    printf("Uneta oznaka je na poziciji (%i, %i).\n", oznaka/8, oznaka%8);

    int x1, y1;
    printf("Unesite koordinate sahovskog polja: ");
    scanf("%i %i", &x1, &y1);
    printf("Za unete koordinate oznaka ce biti %i.\n", x1*8+y1);
    return 0;
}
