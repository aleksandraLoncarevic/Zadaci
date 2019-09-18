#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
    char ch;
    while (1){
        if(kbhit()){
            ch = getch();
            if((int)ch==32){
                printf("%d\n",rand());
            }else
                printf("Greska!\n");
        }
        if((int)ch==27)
            break;
    }
    return 0;
}
