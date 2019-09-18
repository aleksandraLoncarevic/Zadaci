#include <stdio.h>
#include <stdlib.h>

int main(){
	void *blok_p, *bajt_p;
	int vel, n;
	char o, *format_p ;

	while(1){
		o = 0 ;
		while (o != 'c' && o != 'z' && o != 'k'){
			printf("Tip brojeva: (c)eli/(z)naci, ili (k)raj?");
			scanf("%c", &o);
			switch(o){
			case 'c' : 	vel = sizeof(int);
					format_p = "%d";
					break ;
			case 'z' :	vel = sizeof(char) ;
					format_p = "%c" ;
					break ;
			case 'k' :	break ;
			default:	printf("Neispravan unos! Ponovite.\n");
			}
		}
		if (o == 'k') break ;
		printf("Broj podataka?");
		scanf("%d", &n);
		blok_p = malloc(vel*n) ;
		printf("Podaci:\n");

		for (bajt_p=blok_p; bajt_p<(char*)blok_p+n*vel; (char*)bajt_p+=vel){
            printf("?"); scanf(format_p, bajt_p);
        }
		printf("Bajtovi:\n");
		for (bajt_p = blok_p; bajt_p<(char*)blok_p+n*vel; ((char*)bajt_p)++)
			printf("%x", *(char *)bajt_p);
		printf("\n");
		free(blok_p);
	}
}


