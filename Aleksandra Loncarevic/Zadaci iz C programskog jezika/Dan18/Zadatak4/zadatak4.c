#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 100001

void Eratosten(int a[], int n);
int main(){
    int max;
    int prosti[MAXSIZE] = { 0 };
    printf("Unesi broj manji ili jednak %d: ", MAXSIZE -1);
    scanf("%d", &max);
    printf("\n");
    Eratosten(prosti, max);
    printf("Svi prosti brojevi manji ili jednaki %d su:\n", max);
    for (int i = 2; i <= max; i++){
        if (prosti[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
void Eratosten(int a[], int n){
    for(int i = 2; i <= sqrt(n); i++) {
            if (a[i] == 0) {
                int k = 2;
                while (k * i <= n){
                        a[k * i] = 1;
                        k++;
                }
            }
    }
}
