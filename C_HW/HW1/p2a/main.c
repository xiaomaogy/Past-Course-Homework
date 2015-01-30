#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]){

    FILE * fp;
    fp =  fopen(argv[1], "r");

    char ch;

    while((ch = fgetc(fp))!=EOF){
        if(ch=='\t'){
            putchar(' ');
            //putchar(' ');
        }
        else{
            putchar(ch);
        }
    }

    return 0;
}
