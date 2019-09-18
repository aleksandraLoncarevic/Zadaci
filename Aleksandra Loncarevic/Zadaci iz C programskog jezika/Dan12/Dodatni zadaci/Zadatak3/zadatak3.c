#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char imeFajla[20];
    do{
        printf("Unesite ime fajla iz kog zelite da ucitate sadrzaj: ");
        scanf(" %s", &imeFajla);
        file = fopen(imeFajla, "r");
    }while(file==NULL);

    char rec[10];
    printf("Unesite rec: ");
    scanf(" %s", &rec);
    char string[20];
    char recenica[] = "Programski jezik C";

    FILE *file1;
    file1 = fopen("zamenjenTekst.txt", "w");


    while(fscanf(file, "%s", &string)!=EOF) {
        if(strcmp(string, rec) == 0) {
            fprintf(file1, "%s ", recenica);
        }else{
            fprintf(file1, "%s ", string);
        }
    }
    fclose(file1);
    fclose(file);

    file = fopen(imeFajla,"w");
    file1 = fopen("zamenjenTekst.txt","r");

    while(fscanf(file1,"%s",&string) != EOF)
    {
        fprintf(file,"%s ",&string);
    }
    fclose(file);
    fclose(file1);
    remove("zamenjenTekst.txt");


    return 0;
}
