#include <stdio.h>

int main() {
    int i = (5<3) || (~(2==6-3) && (7>8 || 6<9));
    if(i==0) {
        printf("Vrednost izraza je netacna.");
    } else {
         printf("Vrednost izraza je tacna.");
    }
    return 0;
}
