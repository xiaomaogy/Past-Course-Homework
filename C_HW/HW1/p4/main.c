#include <stdio.h>
#include <stdlib.h>
#define MAX_LINES 1500
#define MAX_CHAR_PER_LINE 50


void read_file(char *arg, char store[][MAX_CHAR_PER_LINE]);

int main(int argc,  char * argv[])
{
    char *arg = argv[1];
    char store[MAX_LINES][MAX_CHAR_PER_LINE];
    read_file(arg,store);
    int i=0;
    int j=0;

    while(store[i][j]!=EOF){

        if(store[i][j]=='\n'){
            i++;
            j=0;
        }
        else{
            putchar(store[i][j++]);
        }
    }
    return 0;
}

void read_file(char *arg, char store[][MAX_CHAR_PER_LINE])
{
    FILE * file;
    char ch;
    int i,j;

    file = fopen(arg,"r");
    if(file==NULL)
    {
        printf("cannot open file\n");
        exit(1);
    }

    i=0;
    j=0;

    while((ch = fgetc(file))!=EOF){
        store[i][j++]=ch;
        if(ch=='\n'){
            i++;
            j=0;
        }
    }

    store[i][j]=EOF;

    fclose(file);


}
