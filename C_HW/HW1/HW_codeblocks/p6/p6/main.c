//
//  main.c
//  p6
//
//  Created by yuan gao on 10/27/14.
//  Copyright (c) 2014 yuan gao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 10
int n;
int num=0;
char ori[LEN]="abbcfed";
char mat[LEN]="       ";
char result[LEN];
char used[LEN];
void push(char ch);
void solve(int level);

int main(){
    n=strlen(ori);
    
    printf("%s %c %c",ori,mat[1],result[1]);
    
    
    
    
    
    return 0;
}

void push(char ch){
    for(int i=0;i<num;i++){
        if(mat[i]==ch){
            used[i]++;
            return;
        }
    }
    
    mat[num]=ch;
    used[num]++;
    num++;
}


