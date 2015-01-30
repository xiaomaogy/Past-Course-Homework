#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINES 1020
#define MAX_CHAR_PER_LINE 30

void read_file(char *arg, char wordArray[][MAX_CHAR_PER_LINE], char wordCount[][27]);

int main(int argc,  char * argv[])
{
    char *arg = argv[1];
    
    char wordArray[MAX_LINES][MAX_CHAR_PER_LINE];
    
    char wordCount[MAX_LINES][27];
    int i;
    memset(wordCount,'0', MAX_LINES*27*sizeof(char));
    for(i=0; i<MAX_LINES; i++)
        wordCount[i][26]=0;
    
    char testWordCount[27];
    char testWord[MAX_CHAR_PER_LINE];
    memset(testWordCount, '0', 27*sizeof(char));
    testWordCount[26]=0;
    
    read_file(arg, wordArray, wordCount);
    
    printf("Enter words:");
    
    char ch2;
    int have=0;
    int j = 0;
    while((ch2 = getchar())!=-1)
    {
        testWord[j++] = ch2;
        testWordCount[tolower(ch2)-'a']++;
        if(ch2==' '||ch2=='\n')
        {
            testWord[j-1]='\0';
            j = 0;
            if(strlen(testWord)==0){
                printf("Enter Words:");
                continue;
            }
            have = 0;
            for(int i=0; i< MAX_LINES; i++)
            {
                if(strcmp(testWordCount, wordCount[i])==0)
                {
                    if(have==0)
                    {
                        have = 1;
                        printf("%s : ", testWord);
                    }
                    printf("%s ",wordArray[i]);
                }
            }
            if(have==1)
                printf("\n");
            have = 0;
            memset(testWordCount, '0', 26*sizeof(char));
            if(ch2=='\n')
                printf("Enter Words:");
        }
    }
    
    return 0;
}


void read_file(char *arg, char wordArray[][MAX_CHAR_PER_LINE], char wordCount[][27])
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
    
    while((ch = fgetc(file))!=EOF)
    {
        if(ch=='\n')
        {
            i++;
            j=0;
            continue;
        }
        wordArray[i][j++]=ch;
        wordCount[i][tolower(ch)-'a']++;
    }
    
    wordArray[i][j]=EOF;
    
    fclose(file);
    
    
}
