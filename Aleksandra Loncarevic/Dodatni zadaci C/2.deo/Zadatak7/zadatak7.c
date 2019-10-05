#include<stdio.h>

int main(){
    int duzina, i=0, j=0, k, l;
    printf("Unesite duzinu bocnih strana sestougla:");
    scanf("%d", &duzina);

    for(i = 1, k=duzina, l=2*duzina-1; i<duzina; i++, k--, l++){
        for(j = 0; j < 3*duzina; j++){
            if(j>=k && j<=l){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }

    for(i = 0, k=1, l=3*duzina-2; i<duzina; i++, k++, l--){
        for(j=0; j<3*duzina;j++){
                if(j>=k && j<=l){
                    printf("*");
                }else{
                    printf(" ");
                }
            }
            printf("\n");
        }
}
