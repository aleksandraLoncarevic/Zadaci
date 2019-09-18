#include <stdio.h>
#include <ctype.h>

void sifruj();
void desifruj();

int main() {
    sifruj();
    desifruj();
    return 0;
}

void sifruj() {
    FILE *file, *file1;
    char imeFajla[30];
    printf("Unesite putanju do fajla: ");
    scanf(" %s", &imeFajla);

    file = fopen(imeFajla, "r");

    if(file==NULL){
        printf("Greska!!!");
    }
    file1 = fopen("SifrovanaDatoteka.txt", "w");

    char ch;
    while((ch=fgetc(file))!=EOF) {
        if(ch>='a' && ch<='z') {
            if(ch == 'z'){
                ch = 'a';
                fputc(ch, file1);
            }else{
                ch++;
                ch = toupper(ch);
                fputc(ch, file1);
            }
        }else if(ch>='A' && ch<='Z'){
           if(ch == 'A') {
               ch = 'Z';
               fputc(ch, file1);
            }else{
                ch--;
                ch = tolower(ch);
                fputc(ch, file1);
            }
        }else if(isdigit(ch)) {
            ch++;
            fputc(ch,file1);
        }else{
            fputc(ch, file1);
        }
    }
    fclose(file);
    fclose(file1);
}

void desifruj() {
    FILE *file, *file1;
    file = fopen("SifrovanaDatoteka.txt", "r");
    if(file==NULL){
        printf("Greska!!!");
    }
    file1 = fopen("DesifrovanaDatoteka.txt", "w");

    char ch;
    while((ch=fgetc(file))!=EOF) {
        if(ch>='a' && ch<='z') {
            if(ch == 'a'){
                ch = 'z';
                fputc(ch, file1);
            }else{
                ch++;
                ch = toupper(ch);
                fputc(ch, file1);
            }
        }else if(ch>='A' && ch<='Z'){
           if(ch == 'Z') {
               ch = 'A';
               fputc(ch, file1);
            }else{
                ch--;
                ch = tolower(ch);
                fputc(ch, file1);
            }
        }else if(isdigit(ch)) {
            ch--;
            fputc(ch,file1);
        }else{
            fputc(ch, file1);
        }
    }
    fclose(file);
    fclose(file1);
}

