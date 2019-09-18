#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    file = fopen("tekst.txt", "r");
    char c;

    int brojac1 = 0;
    int brojac2 = 0;
    int brojac3 = 0;

    while((c=fgetc(file))!=EOF) {
        if(c=='a') {
            brojac1++;
        } else if(c == 'b'){
            brojac2++;
        } else if(c == 'c') {
            brojac3++;
        }
    }
    fclose(file);

    FILE *fileABC, *fileA, *fileB, *fileC;
    int opcija;
    printf("Ako zelite da broj pojavljivanja slova a, b i c da ispisete u jednu datoteku pristisnite 1,"
           " ako zelite u odvojene datoteke pritisnite 0: ");
    scanf(" %i", &opcija);
    if(opcija) {
        fileABC = fopen("karakteri.txt", "w");
        fprintf(fileABC, "Slova a ima: %i", brojac1);
        fprintf(fileABC, "\nSlova b ima: %i", brojac2);
        fprintf(fileABC, "\nSlova c ima: %i", brojac3);
        fclose(fileABC);
    }else{
        fileA = fopen("a.txt", "w");
        fprintf(fileA, "Slova a ima: %i", brojac1);
        fclose(fileA);
        fileB = fopen("b.txt", "w");
        fprintf(fileB, "Slova b ima: %i", brojac2);
        fclose(fileB);
        fileC = fopen("c.txt", "w");
        fprintf(fileC, "Slova c ima: %i", brojac3);
        fclose(fileC);
    }
    return 0;
}

