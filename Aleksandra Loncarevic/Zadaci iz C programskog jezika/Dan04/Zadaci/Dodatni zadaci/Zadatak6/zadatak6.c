#include <stdio.h>

int nzd (int a,int b){
    if(b==0) {
        return a;
    } else {
        a=a%b; //nakon ovoga, a ce uvijek biti manje od b
        return nzd(b, a);
    }
}

int main(){
    int a, b;
    printf("Unesite dva broja: ");
    scanf(" %i %i", &a, &b);
    printf("Najveci zajednicki delilac unetih brojeva je %i.\n", nzd(a, b));
    return 0;
}

