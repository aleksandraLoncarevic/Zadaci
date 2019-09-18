#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file1, *file2;
    char ch, ch1;

    char imeFajla1[20];
    do{
        printf("Unesite ime fajla iz kog zelite da ucitate sadrzaj: ");
        scanf(" %s", &imeFajla1);
        file1 = fopen(imeFajla1, "r");
    }while(file1==NULL);

    char imeFajla2[20];
    printf("Unesite ime fajla u koji zelite da upisete promenjeni sadrzaj: ");
    scanf(" %s", &imeFajla2);
    file2 = fopen(imeFajla2, "w");

    while(1) {
        ch = fgetc(file1);
        if(ch == EOF) {
            break;
        }else{
            ch1 = toupper(ch);
            putc(ch1, file2);
        }
    }

    printf("\nUspesno!!\n");

    fclose(file1);
    fclose(file2);
    return 0;
}
