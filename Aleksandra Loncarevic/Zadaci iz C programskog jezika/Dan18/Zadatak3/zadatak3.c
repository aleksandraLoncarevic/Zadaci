#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int niz[], int, int);
void mergeSort(int niz[], int, int);
void insertionSort(int niz[], int);
double min(double a, double b, double c);

int main(){
    int n;
    printf("Unesite broj elemenata niza: ");
    scanf(" %i", &n);
    int niz[n];
    for(int i=0; i<n; i++) {
        niz[i] = rand();
    }

    clock_t t1;
    t1 = clock();
    quickSort(niz, 0, n-1);
    t1 = clock()-t1;
    double vremeIzvrsavanja1 = ((double)t1)/CLOCKS_PER_SEC;
    printf("Vreme izvrsavanja quick sort-a algoritma je %lf.\n", vremeIzvrsavanja1);


    clock_t t2;
    t2 = clock();
    mergeSort(niz, 0, n-1);
    t2 = clock() - t2;
    double vremeIzvrsavanja2 = ((double)t2)/CLOCKS_PER_SEC;
    printf("Vreme izvrsavanja merge sort-a algoritma je %lf.\n", vremeIzvrsavanja2);

    clock_t t3;
    t3 = clock();
    insertionSort(niz, n);
    t3 = clock() - t3;
    double vremeIzvrsavanja3 = ((double)t3)/CLOCKS_PER_SEC;
    printf("Vreme izvrsavanja insertion sort-a algoritma je %lf.\n", vremeIzvrsavanja3);

    if(vremeIzvrsavanja1==min(vremeIzvrsavanja1, vremeIzvrsavanja2, vremeIzvrsavanja3)){
        printf("Najefikasniji algoritam je quick sort.\n");
    }else if(vremeIzvrsavanja2==min(vremeIzvrsavanja1, vremeIzvrsavanja2, vremeIzvrsavanja3)){
        printf("Najefikasniji algoritam je merge sort.\n");
    }else{
        printf("Najefikasniji algoritam je insertion sort.\n");
    }
    return 0;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particija(int niz[], int manji, int veci) {
    int pivot = niz[veci];
    int i = (manji - 1);

    for (int j = manji; j <= veci - 1; j++) {
        if (niz[j] < pivot) {
            i++;
            swap(&niz[i], &niz[j]);
        }
    }
    swap(&niz[i + 1], &niz[veci]);
    return (i + 1);
}

void quickSort(int niz[], int manji, int veci) {
    if (manji<veci) {
        int pi = particija(niz, manji, veci);
        quickSort(niz, manji, pi - 1);
        quickSort(niz, pi + 1, veci);
    }
}

void merge(int niz[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = niz[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = niz[m + 1+ j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            niz[k] = L[i];
            i++;
        }
        else{
            niz[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        niz[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        niz[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int niz[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;
        mergeSort(niz, l, m);
        mergeSort(niz, m+1, r);

        merge(niz, l, m, r);
    }
}

void insertionSort(int niz[], int n) {
    int i, k, j;
    for (i = 1; i < n; i++) {
        k = niz[i];
        j = i - 1;
        while (j >= 0 && niz[j] > k) {
            niz[j + 1] = niz[j];
            j = j - 1;
        }
        niz[j + 1] = k;
    }
}

double min(double a, double b, double c){
    if(a<b){
        if(a<c){
            return a;
        }else{
            return c;
        }
    }else{
        if(b<c){
            return b;
        }else{
            return c;
        }
    }
}
