//
//  main.c
//  p3
//
//  Created by yuan gao on 10/29/14.
//  Copyright (c) 2014 yuan gao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINES 1020
#define MAX_CHAR_PER_LINE 30

void readFile(char *arg, char wordArray[MAX_LINES][MAX_CHAR_PER_LINE],char wordCount[MAX_LINES][27]);

int main(int argc, char * argv[]) {
    
    char wordArray[MAX_LINES][MAX_CHAR_PER_LINE];        //store the dictionary word
    char wordCount[MAX_LINES][27];                       //store the letter count in that word
    
    char testWord[MAX_CHAR_PER_LINE];
    char testWordCount[27];
    
    
    memset(wordCount,'0',MAX_LINES*27*sizeof(char));
    for(int i=0;i<MAX_LINES;i++){
        wordCount[i][26]=0;
    }
    
    
    memset(wordArray,'0',MAX_LINES*MAX_CHAR_PER_LINE*sizeof(char));
    for(int i=0;i<MAX_LINES;i++){
        wordArray[i][MAX_CHAR_PER_LINE-1]=0;
    }
    
    memset(testWord,'0', MAX_CHAR_PER_LINE*sizeof(char));
    
    memset(testWordCount,'0', 27*sizeof(char));
    testWordCount[26]=0;
    
    
    char *arg=argv[1];
    
    readFile(arg, wordArray,wordCount);
    
    printf("Enter words: ");
    
    
    char ch2;
    int have=0;
    int i=0;
    int j=0;
    int k=0;
    
    while((ch2=getchar())!=EOF){
        
        
        testWord[j++]=ch2;
        testWordCount[tolower(ch2)-'a']++;
        
        if(ch2=='\n' || ch2==' '){
            
            testWord[j-1]=0;
            j=0;
            if(strlen(testWord)==0){
                printf("Enter words: ");
                continue;
            }
            
            
            for(k=0;k<MAX_LINES;k++){
                if(strcmp(testWordCount,wordCount[k])==0){
                    if(have == 0){
                        have = 1;
                        printf("%s: ",testWord);
                    }
                    printf("%s ",wordArray[k]);
                }
            }
            
            if(have == 1){
                printf("\n");
            }
            
            have = 0;
            memset(testWordCount,'0', 27*sizeof(char));
            testWordCount[26]=0;
            
            if(ch2=='\n'){
                printf("Enter words: ");
            }
        }
        
    }
    
    
    
    return 0;
}

void readFile(char *arg, char wordArray[MAX_LINES][MAX_CHAR_PER_LINE],char wordCount[MAX_LINES][27]){
    FILE * fp;
    int i,j;
    char ch;
    
    fp = fopen(arg,"r");
    
    if(fp == NULL){
        printf("cannot open file\n");
        exit(1);
    }
    
    i=0;
    j=0;
    
    while((ch=fgetc(fp))!=EOF){
        if(ch=='\n'){
            wordArray[i][j]=0;
            i++;
            j=0;
            continue;
        }
        
        wordArray[i][j++]=ch;
        wordCount[i][tolower(ch)-'a']++;
        
        
    }
    
    wordCount[i][j]=EOF;
    
    fclose(fp);
    
    
}
