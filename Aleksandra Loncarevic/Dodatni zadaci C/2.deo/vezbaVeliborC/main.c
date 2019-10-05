#include <stdio.h>
#include <stdlib.h>


//long reverse(int n);    //2
int main()
{
     /*int broj,brojInv;
    printf("Unesite celi broj: ");
    scanf("%d", &broj);

   brojInv = 0;        //1
    while(broj != 0)
    {
        brojInv = brojInv * 10;
        brojInv = brojInv + broj % 10;
        broj = broj / 10;
    }
    printf("Inverzni broj je: %d", brojInv);

    brojInv = reverse(broj);
    printf("Inverzni broj je: %d", brojInv);*/

    unsigned int n, k;
    printf("Upisite koliko prostih brojeva se trazi: ");
    scanf("%d", &n);
    if (n == 1)
        printf("2");
    else if (n == 2)
        printf("2, 3");
    else
        for(k=1; k<=n; k++)
    {
            printf("2\n3\n%d\n%d\n", 6*k-1, 6*k+1);
    }



    return 0;
}
/*long reverse(int n)
{
    static long r = 0;
    if(n == 0)
        return 0;
    r = r * 10;
    r = r + n % 10;
    reverse(n/10);
    return r;
}*/
