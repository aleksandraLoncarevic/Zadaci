#include <stdio.h>

int main() {
    char ime[20];
    int radniSati;
    float plata;
    char jmbg[13];

    printf("1.Unos\n2.Zaposleni sa najvecom platom\n");
    int izbor;

    char ch;

    FILE *file1, *file2;
    do{
        printf("\nIzaberite operaciju: ");
        scanf(" %i", &izbor);
        switch(izbor){
        case 1:
            file1 = fopen("zaposleni.txt", "a");

            printf("\nUnesite JMBG radnika: ");
            scanf(" %s", &jmbg);
            fprintf(file1, "%s ", jmbg);

            printf("Unesite ime: ");
            scanf(" %s", &ime);
            fprintf(file1, "%s ", ime);

            printf("Unesite broj mesecnih radnih sati i platu: ");
            scanf(" %i %f", &radniSati, &plata);
            fprintf(file1, "%i %f\n", radniSati, plata);

            fclose(file1);
            break;

        case 2:
            file2 = fopen("zaposleni.txt", "r");
            while((ch=fgetc(file2))!=EOF){
                fscanf(file2, "%s %s %i %f", &jmbg, &ime, &radniSati, &plata);
                if(plata/radniSati>1000) {
                    printf("%s %s\n", jmbg, ime);
                }
            }
            fclose(file2);
            break;
        }
    }while(izbor>0 && izbor<3);

    return 0;
}
