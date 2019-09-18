#include <stdio.h>

int realnoVreme(int, int);

int main() {
    int s;
    printf("Unesite pozitivan ceo broj koji predstavlja vrednost za koju ce nakon svakog minuta uvecavati broj sati: ");
    scanf(" %i", &s);
    int m;
    printf("Unesite pozitivan ceo broj koji predstavlja vrednost za koju ce nakon svakog minuta uvecavati broj minuta: ");
    scanf(" %i", &m);
    printf("Sat u toku dana je tacan %i puta.\n", realnoVreme(s, m));
    return 0;
}
int realnoVreme(int x, int y) {
    int brojac =0;
    int s = 0;
    int m = 0 ;
    for(int i=0; i<=2; i++) {
        for(int j=1; j<=59; j++) {
            s+=x;
            m+=y;
            if(m>=60){
                m = m - 60;
            }
            if(s>=24) {
                s = s - 24;
            }
            if(s==i && m==j) {
                brojac++;
            }

        }
    }
    return brojac;
}
