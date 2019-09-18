#include <stdio.h>

void sortiraj(int *array, int n);
void kreirajfajlSortiran(int *array, int n);
void ucitajFajlSortiran();

int main() {
    FILE *file;
    file = fopen("matrica.txt", "r");
    int n,m;
    fscanf(file, "%i %i", &n, &m);

    int matrica[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            fscanf(file, "%i ", &matrica[i][j]);
        }
    }
    fclose(file);

    int array[n];
    if(n == m) {                    /*ako je matrica kvadratna*/
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i+j==n-1) {
                    array[i] = matrica[i][j];
                }
            }
        }
    }else{                         /*ako nije kvadratna matrica*/
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i+j==n) {
                    array[i] = matrica[i][j];
                }
            }
        }
    }

    sortiraj(array, n);
    kreirajfajlSortiran(array, n);
    ucitajFajlSortiran();

    return 0;
}

void sortiraj(int *array, int n) {
    for(int j=1; j<n; j++) {
        for(int i=0; i<j; i++) {
            if(array[j]<array[i]) {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

void kreirajfajlSortiran(int *array, int n) {
    FILE *file;
    file = fopen("sortiran.txt", "w");
    fprintf(file, "%i\n", n);
    for(int i=0; i<n; i++) {
        fprintf(file, "%i ", array[i]);
    }
    fclose(file);
}

void ucitajFajlSortiran(){
    FILE *file;
    file = fopen("sortiran.txt", "r");

    int n;
    fscanf(file, "%i", &n);
    int matrica[n][n];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
                if(i<j) {
                    matrica[i][j] = 0;
                }else if(i>j){
                    matrica[i][j] = 1;
                }else {
                    fscanf(file, "%i ", &matrica[i][j]);
                }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%i ", matrica[i][j]);
        }
        printf("\n");
    }
}


