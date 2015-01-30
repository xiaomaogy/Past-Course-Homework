//
//  main.c
//  p10
//
//  Created by yuan gao on 10/27/14.
//  Copyright (c) 2014 yuan gao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    float test[100];
    FILE * fp;
    int width = argv[2];
    
    fp = fopen(argv[1], "r");
    memset(test, '0', 100*sizeof(float));
    
    
    int i=0;    //index for num of float
    int k=0;    //index for each float
    char ch;
    char temp[20];
    while(1){
        
        do{
            ch=fgetc(fp);
            if(ch == '\n' || ch == ' ' || ch == EOF){
                break;
            }
            temp[k++]=ch;
        }
        while(1);
        temp[k]=0;
        
        
        
        if(ch==EOF){
            break;
        }
    }
}


/*
while (1)
{
    do
    {
        ch=fgetc(fp);
        if(ch=='\n'||ch==' '||ch==EOF)
        {
            break;
        }
        temp[k++]=ch;
    }
    while(1);
    temp[k]=0;
    
    if(hasRepeat(temp, strlen(temp))==0)
    {
        k=0;
        if(ch==EOF)
            break;
        continue;
    }
    
    if(i==0)
    {
        strcpy(wordList[i],temp);
        wordCount[i]++;
        i++;
    }
    else
    {
        for(j=0; j<i; j++)
        {
            if(strcmp(wordList[j],temp)==0)
            {
                wordCount[j]++;
                break;
            }
        }
        if(j==i)
        {
            strcpy(wordList[i],temp);
            wordCount[i]++;
            i++;
        }
    }
    
    k=0;
    
    if(ch==EOF)
        break;
}*/
