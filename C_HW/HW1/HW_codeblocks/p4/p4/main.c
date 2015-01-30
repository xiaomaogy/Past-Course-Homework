
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINES 1500
#define MAX_CHAR_PER_LINE 50


void read_file(char *, char **);

int main(int argc,  char * argv[]) {
    char *arg = argv[1];
    char store[MAX_LINES][MAX_CHAR_PER_LINE];
    read_file(arg,store);
    int i;
    int j;
    for(i=0;i<MAX_LINES && **store[i][j]!=EOF;i++){
        for(j=0;j<MAX_CHAR_PER_LINE && **store[i][j]!='\n';j++){
            putchar(**store[i][j]);
        }
        return 0;
    }
    
    void read_file(char *arg, char **store){
        FILE * file;
        char ch;

        file = fopen(arg,"r");
        if(file==NULL){
            printf("cannot open file\n");
            exit(1);
        }
        
        ch = fgetc(file);
        for(int i=0;i<MAX_LINE && ch!=EOF;i++){
            for(int j=0;ch!='\n' && j<MAX_CHAR_PER_LINE;j++){
                store[i][j] = ch;
                ch = fgetc(file);
            }
        }
        
        printf("\n");
        fclose(file);
        
        
    }